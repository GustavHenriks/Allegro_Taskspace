#include "HandManip.h"

HandManip* HandManip::me = NULL;

//======================================================================================================//
//=================================== Condtruction & Initialization ====================================//
//======================================================================================================//

HandManip::HandManip(ros::NodeHandle &n,double frequency, ControllerMode controllerMode): 
  _n(n),
  _loopRate(frequency),
  _dt(1.0f/frequency),
  _controllerMode(controllerMode)
{
   me = this;
   //---------------------------------
   // Define the parameter that you will use later
   //------------------------------- 
   _current_joint_position[DOF_JOINTS] = {0.0};
   _current_joint_velocity[DOF_JOINTS] = {0.0};
   _current_joint_torque[DOF_JOINTS]   = {0.0};
   _desired_joint_position[DOF_JOINTS] = {0.0};
   _desired_joint_velocity[DOF_JOINTS] = {0.0};
   _desired_joint_torque[DOF_JOINTS]   = {0.0};


   _msgJointCmd.position.resize(DOF_JOINTS);
   _msgJointCmd.velocity.resize(DOF_JOINTS);
   _msgJointCmd.effort.resize(DOF_JOINTS);
    
   _msgRealJointStates.position.resize(DOF_JOINTS);
   _msgRealJointStates.velocity.resize(DOF_JOINTS);
   _msgRealJointStates.effort.resize(DOF_JOINTS);

   _msgDesiredJointStates.position.resize(DOF_JOINTS);
   _msgDesiredJointStates.velocity.resize(DOF_JOINTS);
   _msgDesiredJointStates.effort.resize(DOF_JOINTS);

   _stop =false;

   reference_point_position = {0.0, 0.0, 0.0};
   // reference pose 
   _gravity << 0.0f, 0.0f, -9.80665f;

   
   // Optitrack
   for(int k = 0; k < TOTAL_NB_MARKERS; k++)
  {
    _firstOptitrackPose[k] = false;
    _markersPosition.setConstant(0.0f);
    _markersPosition0.setConstant(0.0f);
  }
   _optitrackOK = false;
   _markersPosition.setConstant(0.0f);
   _markersPosition0.setConstant(0.0f);
   _markersSequenceID.setConstant(0);
   _markersTracked.setConstant(0);
   _averageCount = 0;
   _p1 << 0.0f, 0.0f, 0.0f;

   // Object
   _baseRobotOrigin << 0.066f, 0.9f, 0.0f; // to be corrected


}


bool HandManip::init()
{
   // subscriber definition
   _subJointSates = _n.subscribe("/allegroHand_0/joint_states",1,
      &HandManip::updateHandStates,this,ros::TransportHints().reliable().tcpNoDelay());

   _subOptitrackPose[1] = _n.subscribe<geometry_msgs::PoseStamped>("/optitrack/1/pose", 1, 
      &HandManip::updateOptitrack,this,_1,1,ros::TransportHints().reliable().tcpNoDelay());


   //publisher definition
   _pubDesiredJointSates = _n.advertise<sensor_msgs::JointState>("desiredJointState",1);
   _pubJointCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/joint_cmd",  1);
   _pubTorqueCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/torque_cmd",1);

   //initialize the kinematic and jacobian solver
   initializeKinemtic();

   // filter section:
   _x0p = {0.0 , 0.0 , 0.0};
   _x1p = {0.0 , 0.0 , 0.0};
   _x2p = {0.0 , 0.0 , 0.0};
   _x3p = {0.0 , 0.0 , 0.0};

   _v0p = {0.0 , 0.0 , 0.0};
   _v1p = {0.0 , 0.0 , 0.0};
   _v2p = {0.0 , 0.0 , 0.0};
   _v3p = {0.0 , 0.0 , 0.0};

   filterGain = 0.2;
   //
   
   // attractor of each ds -> will be reoved later as the ds should be defined from out side of this node
   X0_target_inRef = {0.0795334, -0.02275253, 0.0836488};
   X1_target_inRef = {0.0789154,  0.00851324, 0.0836488};
   X2_target_inRef = {0.0607702,  0.0478584,  0.0563102};
   X3_target_inRef = {0.0778476, -0.0575216,  0.0390766};

   alphaGain0 = 7; //7000
   alphaGain1 = 15;
   alphaGain2 = 15;
   alphaGain3 = 15;
   dsGainMatrix_0 = alphaGain0 * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_1 = alphaGain1 * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_2 = alphaGain2 * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_3 = alphaGain3 * Eigen::Matrix3d::Identity(3,3);
   // Sending a minimun force

   EPSILON_FORCE        = 0.0001;
   LIMIT_FORCE          = 10.00;
   nullGainController   = 1.00;
   _null_joint_position[12]= 0.80;

   // initializing the passive Ds Controller
   _dimX = 3;

   _eigenValue_0 = 7.0;
   _eigenValue_1 = 7.0;
   _eigenValue_2 = 7.0;
   _eigenValue_3 = 7.0;

   _eigenValue_dissipative_0 = 10.0;
   _eigenValue_dissipative_1 = 10.0;
   _eigenValue_dissipative_2 = 10.0;
   _eigenValue_dissipative_3 = 10.0;

   dsController_0 = new DSController(_dimX, _eigenValue_0,_eigenValue_dissipative_0);
   dsController_1 = new DSController(_dimX, _eigenValue_1,_eigenValue_dissipative_1);
   dsController_2 = new DSController(_dimX, _eigenValue_2,_eigenValue_dissipative_2);
   dsController_3 = new DSController(_dimX, _eigenValue_3,_eigenValue_dissipative_3);
}

//======================================================================================================//
//========================================= Main Function ==============================================//
//======================================================================================================//

void HandManip::run()
{
 while(!_stop && ros::ok())
 {
    _mutex.lock();

    //-----------------------------------------//
    //--------- Check for prerequisits --------//
    //-----------------------------------------//

    // Initialize optitrack
    if(!_optitrackOK)
     {
      optitrackInitialization();
     }
     else
    {

    //-----------------------------------------//
    //------------ Body of th Code ------------//
    //-----------------------------------------//
    X_Object_inRef = getObjectPosition();

    computeCommand();
    publishData();
    
    //-----------------------------------------//
    //------------Save for Output--------------//
    //-----------------------------------------//
    
    //=> Dit: Log Data
    //logData

    ros::spinOnce();
    _loopRate.sleep();
    
    }

    //CF: End of the optitrack ELSE
    _mutex.unlock();

 }

    //-----------------------------------------//
    //-------- Termination of th Code ---------//
    //-----------------------------------------//
 
 //SEND ZERO COMMAND
 //=> Dit
 
  publishData();
  ros::spinOnce();
  _loopRate.sleep();

 // _outputFile.close();
  ros::shutdown();

}

// void HandManip::stopNode(int sig)
// {
//     me->_stop = true;
// }



//======================================================================================================//
//====================================== Control  Function =============================================//
//======================================================================================================//
void HandManip::computeCommand()
{
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  //0- Update position and velocity in the desired frame
  //1- Compute the Jacobians:
  //2- Compute the DS
  //3- From the DS then Compute the Desired command 
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  
  updateRefPosVel(); // update position and velocity of fingertips all in the reference frame
  updateJacobians(); // get the jacobian of the current pose
  
  JF_0 = jacobian_finger_0.topRows(3);
  JF_1 = jacobian_finger_1.topRows(3);
  JF_2 = jacobian_finger_2.topRows(3);
  JF_3 = jacobian_finger_3.topRows(3);
  
  typeAttractors();
  setAttractors();
  
  computeDS(); // Get the desired velocity

   if (_controllerMode == Position_Mode)
      computeCommandPsMode();
   else if(_controllerMode == Torque_Mode)
      computeCommandTqMode();
}

void HandManip::updateRefPosVel()
{
   // get positions in Ref
   updateForwardKinematic();

   // get velocity in Ref 
   // to filter : V_filtered_t = alpha*V_t + (1-alpha)*V_filtered_previous
   for(int i =0; i<3; i++){
      V0_current_inRef[i] = filterGain * ( (X0_current_inRef[i] - _x0p[i])/_dt ) + (1-filterGain)*_v0p[i];
      _v0p[i] = V0_current_inRef[i]; 
      _x0p[i] = X0_current_inRef[i]; 
 
      V1_current_inRef[i] = filterGain * ( (X1_current_inRef[i] - _x1p[i])/_dt ) + (1-filterGain)*_v1p[i];
      _v1p[i] = V1_current_inRef[i]; 
      _x1p[i] = X1_current_inRef[i]; 
 
      V2_current_inRef[i] = filterGain * ( (X2_current_inRef[i] - _x2p[i])/_dt ) + (1-filterGain)*_v2p[i];
      _v2p[i] = V2_current_inRef[i]; 
      _x2p[i] = X2_current_inRef[i]; 
 
      V3_current_inRef[i] = filterGain * ( (X3_current_inRef[i] - _x3p[i])/_dt ) + (1-filterGain)*_v3p[i];
      _v3p[i] = V3_current_inRef[i];
      _x3p[i] = X3_current_inRef[i];
   }

}
void HandManip::typeAttractors(){
   attractorType_0 = AttractorType::Stabilizer;
   attractorType_1 = AttractorType::Stabilizer;
   attractorType_2 = AttractorType::Stabilizer;
   attractorType_3 = AttractorType::Stabilizer;
 }

void HandManip::setAttractors(){
   
   // for the stabilizer test
   if (attractorType_0 == Contributor){
      // will be updated 
   }
   else if (attractorType_0 == Workspace)
   {
      // will be updated
   }
   else
   {
      Eigen::Vector3d relDis_0 = {0.0, -0.035, 0.010};
      X0_target_inRef = X_Object_inRef + relDis_0;
   }
   //------------------------------------------------
   if (attractorType_1 == Contributor){
      // will be updated 
   }
   else if (attractorType_1 == Workspace)
   {
      // will be updated
   }
   else
   {
      Eigen::Vector3d relDis_1 = {0.0, 0.010, 0.035};
      X1_target_inRef = X_Object_inRef + relDis_1;
   }
   //----------------------------------------------------
   if (attractorType_2 == Contributor){
      // will be updated 
   }
   else if (attractorType_2 == Workspace)
   {
      // will be updated
   }
   else
   {
      Eigen::Vector3d relDis_2 = {0.0, 0.035, 0.010};
      X2_target_inRef = X_Object_inRef + relDis_2;
   }
   //---------------------------------------------------
   if (attractorType_3 == Contributor){
      // will be updated 
   }
   else if (attractorType_3 == Workspace)
   {
      // will be updated
   }
   else
   {
      Eigen::Vector3d relDis_3 = {0.0, 0.0, -0.035};
      X3_target_inRef = X_Object_inRef + relDis_3;
   }

}

void HandManip::computeDS()
{
   // This is a simple Ds just to test the functionality of the controller
   // which later will be replaced by a  practical ds
   
/*
   V0_ds_inRef = dsGainMatrix_0 * (X0_target_inRef - X0_current_inRef);
   V1_ds_inRef = dsGainMatrix_1 * (X1_target_inRef - X1_current_inRef);
   V2_ds_inRef = dsGainMatrix_2 * (X2_target_inRef - X2_current_inRef);
   V3_ds_inRef = dsGainMatrix_3 * (X3_target_inRef - X3_current_inRef);
*/
   // alphaGain0 = 7; //7000
   // alphaGai1 = 15;
   // alphaGai2 = 15;
   // alphaGai3 = 15;

   if ((X0_target_inRef - X0_current_inRef).norm() > 0.1)
      alphaGain0 = 7.0;
   else
      alphaGain0 = 15.0;
   if ((X1_target_inRef - X1_current_inRef).norm() > 0.1)
      alphaGain1 = 7.0;
   else
      alphaGain1 = 15.0;
   if ((X2_target_inRef - X2_current_inRef).norm() > 0.1)
      alphaGain2 = 7.0;
   else
      alphaGain2 = 15.0;
   if ((X3_target_inRef - X3_current_inRef).norm() > 0.1)
      alphaGain3 = 10.0;
   else
      alphaGain3 = 20.0;

   dsGainMatrix_0 = alphaGain0 * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_1 = alphaGain1 * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_2 = alphaGain2 * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_3 = alphaGain3 * Eigen::Matrix3d::Identity(3,3);

   V0_ds_inRef = dsGainMatrix_0 * (X0_target_inRef - X0_current_inRef);
   V1_ds_inRef = dsGainMatrix_1 * (X1_target_inRef - X1_current_inRef);
   V2_ds_inRef = dsGainMatrix_2 * (X2_target_inRef - X2_current_inRef);
   V3_ds_inRef = dsGainMatrix_3 * (X3_target_inRef - X3_current_inRef);


   // std::cout << (X0_target_inRef - X0_current_inRef).transpose() << std::endl;
   // std::cout << (X1_target_inRef - X1_current_inRef).transpose() << std::endl;
   // std::cout << (X2_target_inRef - X2_current_inRef).transpose() << std::endl;
   // std::cout << (X3_target_inRef - X3_current_inRef).transpose() << std::endl << std::endl;

}
void HandManip::computeCommandPsMode(){

   X0_dsGenerated_inRef = _dt * V0_ds_inRef ;//+ X0_current_inRef; //X0_target_inRef ;  
   X1_dsGenerated_inRef = _dt * V1_ds_inRef ;//+ X1_current_inRef; //X1_target_inRef ;  
   X2_dsGenerated_inRef = _dt * V2_ds_inRef ;//+ X2_current_inRef; //X2_target_inRef ;  
   X3_dsGenerated_inRef = _dt * V3_ds_inRef ;//+ X3_current_inRef; //X3_target_inRef ; 

   // -------Jacobian Tanspose Method:
   // Eigen::Vector3d tempVec_0 = JF_0 * JF_0.transpose() * X0_dsGenerated_inRef;
   // Eigen::Vector3d tempVec_1 = JF_1 * JF_1.transpose() * X1_dsGenerated_inRef;
   // Eigen::Vector3d tempVec_2 = JF_2 * JF_2.transpose() * X2_dsGenerated_inRef;
   // Eigen::Vector3d tempVec_3 = JF_3 * JF_3.transpose() * X3_dsGenerated_inRef;

   // performance gain for the jacobian transpose
   // double betaGain_0 = (double)( X0_dsGenerated_inRef.transpose() * tempVec_0 )/( tempVec_0.transpose() * tempVec_0 );
   // double betaGain_1 = (double)( X1_dsGenerated_inRef.transpose() * tempVec_1 )/( tempVec_1.transpose() * tempVec_1 );
   // double betaGain_2 = (double)( X2_dsGenerated_inRef.transpose() * tempVec_2 )/( tempVec_2.transpose() * tempVec_2 );
   // double betaGain_3 = (double)( X3_dsGenerated_inRef.transpose() * tempVec_3 )/( tempVec_3.transpose() * tempVec_3 );

   double betaGain_0 = 0.5;
   double betaGain_1 = 0.5;
   double betaGain_2 = 0.5;
   double betaGain_3 = 0.5;

   joint_command_finger_0 =  betaGain_0 * JF_0.transpose() * X0_dsGenerated_inRef;
   joint_command_finger_1 =  betaGain_1 * JF_1.transpose() * X1_dsGenerated_inRef;
   joint_command_finger_2 =  betaGain_2 * JF_2.transpose() * X2_dsGenerated_inRef;
   joint_command_finger_3 =  betaGain_3 * JF_3.transpose() * X3_dsGenerated_inRef;

   // ------Jacobian psudo inverse method 
   // Eigen::MatrixXd tempMat_0 = JF_0.transpose() * JF_0;
   // Eigen::MatrixXd tempMat_1 = JF_1.transpose() * JF_1;
   // Eigen::MatrixXd tempMat_2 = JF_2.transpose() * JF_2;
   // Eigen::MatrixXd tempMat_3 = JF_3.transpose() * JF_3;

   // joint_command_finger_0 = tempMat_0.inverse() * JF_0.transpose() * X0_dsGenerated_inRef;
   // joint_command_finger_1 = tempMat_1.inverse() * JF_1.transpose() * X1_dsGenerated_inRef;
   // joint_command_finger_2 = tempMat_2.inverse() * JF_2.transpose() * X2_dsGenerated_inRef;
   // joint_command_finger_3 = tempMat_3.inverse() * JF_3.transpose() * X3_dsGenerated_inRef;

   for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _desired_joint_position[j]   = joint_command_finger_0[j] + _current_joint_position[j];
      _desired_joint_position[j+4] = joint_command_finger_1[j] + _current_joint_position[j+4];
      _desired_joint_position[j+8] = joint_command_finger_2[j] + _current_joint_position[j+8];
      _desired_joint_position[j+12]= joint_command_finger_3[j] + _current_joint_position[j+12];
   }
}

void HandManip::computeCommandTqMode(){

   // update the passive Ds
   // update ensuring passivity
   // control_force = my_passive_ds->UpdatePassive(actual_velocity, desired_velocity, dt);
   // update ignoring the passivity (energy tank) : not now
   // Null Space Controller
   // Gravity Compensation
   // Torque limits

   dsController_0->Update(V0_current_inRef, V0_ds_inRef);
   dsController_1->Update(V1_current_inRef, V1_ds_inRef);
   dsController_2->Update(V2_current_inRef, V2_ds_inRef);
   dsController_3->Update(V3_current_inRef, V3_ds_inRef);


   _torque_command_0 =  JF_0.transpose() * dsController_0->control_output();
   _torque_command_1 =  JF_1.transpose() * dsController_1->control_output();
   _torque_command_2 =  JF_2.transpose() * dsController_2->control_output();
   _torque_command_3 =  JF_3.transpose() * dsController_3->control_output();


   for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _desired_joint_torque[j]   = _torque_command_0[j];
      _desired_joint_torque[j+4] = _torque_command_1[j];
      _desired_joint_torque[j+8] = _torque_command_2[j];
      _desired_joint_torque[j+12]= _torque_command_3[j];
   }

   // ------Jacobian null space  method to cover the redundancy
   nullSpaceControl();
   // Compensate for the gravity on each joint
   gravityCompensation(); 

   // torque Command Limits: Allways send a minimum torque and take care of saturation
   for (int i =0; i< DOF_JOINTS; i++){
      _desired_joint_torque[i] -=  gravity[i+6];
      if (fabs(_desired_joint_torque[i]) < EPSILON_FORCE )
         _desired_joint_torque[i] = EPSILON_FORCE;
      else if ( _desired_joint_torque[i] >  LIMIT_FORCE )
         _desired_joint_torque[i] = LIMIT_FORCE;
      else if ( _desired_joint_torque[i] <  -LIMIT_FORCE)
         _desired_joint_torque[i] = -LIMIT_FORCE;
   }

}


//======================================================================================================//
//================================ Subscriber and Publisher Function ===================================//
//======================================================================================================//
void HandManip::updateHandStates(const sensor_msgs::JointState &msg)
{
   for (int i = 0; i < DOF_JOINTS; i++)
   {
      _current_joint_position[i] = msg.position[i];
      _current_joint_velocity[i] = msg.velocity[i];
      _current_joint_torque[i]   = msg.effort[i];

   } 

}

void HandManip::publishData()
{

   for (int i = 0; i < DOF_JOINTS; i++) {
      _msgDesiredJointStates.position[i] = _desired_joint_position[i];
      // _msgDesiredJointStates.velocity[i] = _desired_joint_velocity[i];
      _msgDesiredJointStates.effort[i] = _desired_joint_torque[i];
   }
   //  _pubDesiredJointSates.publish(_msgDesiredJointStates);
   
   if(_controllerMode == Torque_Mode)
      _pubTorqueCmd.publish(_msgDesiredJointStates);
   else if(_controllerMode == Position_Mode)
      _pubJointCmd.publish(_msgDesiredJointStates);

}

//------------------------------------ Optitrack System ------------------------------------

void HandManip::optitrackInitialization()
{
  if(_averageCount< AVERAGE_COUNT)
  {
    if( _markersTracked(0) )
    {
      _markersPosition0 = (_averageCount*_markersPosition0+_markersPosition)/(_averageCount+1);
      _averageCount++;
    }
    std::cerr << "[ObjectGrasping]: Optitrack Initialization count: " << _averageCount << std::endl;
    if(_averageCount == 1)
    {
      ROS_INFO("[ObjectGrasping]: Optitrack Initialization starting ...");
    }
    else if(_averageCount == AVERAGE_COUNT)
    {
      ROS_INFO("[ObjectGrasping]: Optitrack Initialization done !");
      // ----------------Now set the origin
      // _leftRobotOrigin = _markersPosition0.col(ROBOT_BASIS_LEFT)-_markersPosition0.col(ROBOT_BASIS_RIGHT);
       _baseRobotOrigin = _markersPosition0.col(0)
    }
  }
  else
  {
    _optitrackOK = true;
  }
}


void HandManip::updateOptitrack(const geometry_msgs::PoseStamped::ConstPtr& msg, int k) 
{  

   _markersSequenceID(k) = msg->header.seq;
   _markersTracked(k) = checkTrackedMarker(_markersPosition.col(k)(0),msg->pose.position.x);
   
   _markersPosition.col(k) << msg->pose.position.x, msg->pose.position.y, msg->pose.position.z;

}

uint16_t HandManip::checkTrackedMarker(float a, float b)
{
  if(fabs(a-b)< FLT_EPSILON)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

Eigen::Vector3d HandManip::getObjectPosition(){
   if(_markersTracked.sum() == TOTAL_NB_MARKERS)
   {
      // Compute markers position in the hand robot frame
      _p1 = _markersPosition.col(1)-_markersPosition0.col(0);
   
      //----------->>>>> The visualization market will be added later.
      //----> object orientation also


      // Filter  position and  Orientation of the object
      
      // Send the visualization marker
      
      //----------->> Update here
      Eigen::Vector3d _xobject = {0.090, -0.030, 0.090};

      return _xobject;
   }
}

Eigen::Vector4d HandManip::getObjectOrientation(){
   
   //----------->> Update here


}



//======================================================================================================//
//================================ Kinematic and Dynamic Function ======================================//
//======================================================================================================//
void HandManip::initializeKinemtic()
{

   //  ROS_INFO("Initialize Started");
    // We will start by instantiating a
    // `RobotModelLoader`_
    // object, which will look up
    // the robot description on the ROS parameter server and construct a
    // :moveit_core:`RobotModel` for us to use.
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    kinematic_model = robot_model_loader.getModel();
    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());

    /* Using the :moveit_core:`RobotModel`, we can construct a
      :moveit_core:`RobotState` that maintains the configuration
       of the robot. 
       We will set all joints in the state to their default values. 
       We can then get a :moveit_core:`JointModelGroup`, which represents the robot
       model for a particular group, e.g. the "finger_0" of the AllegroHand robot.
    */
    kinematic_state = robot_state::RobotStatePtr(new robot_state::RobotState(kinematic_model));
    kinematic_state->setToDefaultValues();
    
    _joint_model_finger_0 = kinematic_model->getJointModelGroup("finger_0");
    _joint_model_finger_1 = kinematic_model->getJointModelGroup("finger_1");
    _joint_model_finger_2 = kinematic_model->getJointModelGroup("finger_2");
    _joint_model_finger_3 = kinematic_model->getJointModelGroup("finger_3");
    
    const std::vector<std::string>& joint_names_finger_0 = _joint_model_finger_0->getVariableNames();
    const std::vector<std::string>& joint_names_finger_1 = _joint_model_finger_1->getVariableNames();
    const std::vector<std::string>& joint_names_finger_2 = _joint_model_finger_2->getVariableNames();
    const std::vector<std::string>& joint_names_finger_3 = _joint_model_finger_3->getVariableNames();

    kinematic_state->copyJointGroupPositions(_joint_model_finger_0, _joint_values_finger_0);
    kinematic_state->copyJointGroupPositions(_joint_model_finger_1, _joint_values_finger_1);
    kinematic_state->copyJointGroupPositions(_joint_model_finger_2, _joint_values_finger_2);
    kinematic_state->copyJointGroupPositions(_joint_model_finger_3, _joint_values_finger_3);

    for (std::size_t i = 0; i < joint_names_finger_0.size(); ++i)
    {
        ROS_INFO("Joint %s: %f", joint_names_finger_0[i].c_str(), _joint_values_finger_0[i]);
    }
}

void HandManip::updateForwardKinematic()
{
    // Now, we can compute forward kinematics for a set of random joint values. (not necessary)
    // kinematic_state->setToRandomPositions(joint_model_group);
    // Note that we would like to find the pose of the "fingerTip"
    for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _joint_values_finger_0[j]          = (double)_current_joint_position[j];
      _joint_values_finger_1[j]          = (double)_current_joint_position[j+4];
      _joint_values_finger_2[j]          = (double)_current_joint_position[j+8];
      _joint_values_finger_3[j]          = (double)_current_joint_position[j+12];
     }
     
    kinematic_state->setJointGroupPositions(_joint_model_finger_0, _joint_values_finger_0);
    kinematic_state->setJointGroupPositions(_joint_model_finger_1, _joint_values_finger_1);
    kinematic_state->setJointGroupPositions(_joint_model_finger_2, _joint_values_finger_2);
    kinematic_state->setJointGroupPositions(_joint_model_finger_3, _joint_values_finger_3);

    const Eigen::Affine3d& state_fingertip_0 = kinematic_state->getGlobalLinkTransform("link_3_tip");
    const Eigen::Affine3d& state_fingertip_1 = kinematic_state->getGlobalLinkTransform("link_7_tip");
    const Eigen::Affine3d& state_fingertip_2 = kinematic_state->getGlobalLinkTransform("link_11_tip");
    const Eigen::Affine3d& state_fingertip_3 = kinematic_state->getGlobalLinkTransform("link_15_tip");

    X0_current_inRef = state_fingertip_0.translation();
    X1_current_inRef = state_fingertip_1.translation();
    X2_current_inRef = state_fingertip_2.translation();
    X3_current_inRef = state_fingertip_3.translation();

   //  ROS_INFO_STREAM("Rotation: \n" << state_fingertip_0.rotation() << "\n");
}

void HandManip::updateJacobians()
{
   // We can also get the Jacobian from the :moveit_core:`RobotState`.

      kinematic_state->getJacobian(_joint_model_finger_0,
                                    kinematic_state->getLinkModel(_joint_model_finger_0->getLinkModelNames().back()),
                                    reference_point_position, 
                                    jacobian_finger_0);
      
      kinematic_state->getJacobian(_joint_model_finger_1,
                                    kinematic_state->getLinkModel(_joint_model_finger_1->getLinkModelNames().back()),
                                    reference_point_position, 
                                    jacobian_finger_1);
      
      kinematic_state->getJacobian(_joint_model_finger_2,
                                    kinematic_state->getLinkModel(_joint_model_finger_2->getLinkModelNames().back()),
                                    reference_point_position, 
                                    jacobian_finger_2);
      
      kinematic_state->getJacobian(_joint_model_finger_3,
                                    kinematic_state->getLinkModel(_joint_model_finger_3->getLinkModelNames().back()),
                                    reference_point_position, 
                                    jacobian_finger_3);
      
      // ROS_INFO_STREAM("Jacobian: \n" << jacobian_finger_0 << "\n");
   //
}

void HandManip::nullSpaceControl(){

   for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _temp_joint_torque_0[j] = (double)(-1 * nullGainController * (_current_joint_position[j]    - _null_joint_position[j]));
      _temp_joint_torque_1[j] = (double)(-1 * nullGainController * (_current_joint_position[j+4]  - _null_joint_position[j+4]));
      _temp_joint_torque_2[j] = (double)(-1 * nullGainController * (_current_joint_position[j+8]  - _null_joint_position[j+8]));
      _temp_joint_torque_3[j] = (double)(-1 * nullGainController * (_current_joint_position[j+12] - _null_joint_position[j+12]));
   }

   Eigen::MatrixXd tempMat_0 = JF_0 * JF_0.transpose();
   Eigen::MatrixXd tempMat_1 = JF_1 * JF_1.transpose();
   Eigen::MatrixXd tempMat_2 = JF_2 * JF_2.transpose();
   Eigen::MatrixXd tempMat_3 = JF_3 * JF_3.transpose();

   Eigen::MatrixXd nullMat_0 =  Eigen::MatrixXd::Identity(4,4) - (JF_0.transpose() * tempMat_0.inverse() * JF_0);
   Eigen::MatrixXd nullMat_1 =  Eigen::MatrixXd::Identity(4,4) - (JF_1.transpose() * tempMat_1.inverse() * JF_1);
   Eigen::MatrixXd nullMat_2 =  Eigen::MatrixXd::Identity(4,4) - (JF_2.transpose() * tempMat_2.inverse() * JF_2);
   Eigen::MatrixXd nullMat_3 =  Eigen::MatrixXd::Identity(4,4) - (JF_3.transpose() * tempMat_3.inverse() * JF_3);
   
   for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _null_joint_torque[j]   = nullMat_0.row(j) * _temp_joint_torque_0;
      _null_joint_torque[j+4] = nullMat_1.row(j) * _temp_joint_torque_1;
      _null_joint_torque[j+8] = nullMat_2.row(j) * _temp_joint_torque_2;
      _null_joint_torque[j+12]= nullMat_3.row(j) * _temp_joint_torque_3;
   }

   for (int j =0; j < DOF_JOINTS; j++){
      _desired_joint_torque[j] += _null_joint_torque[j]; 
   }

}

void HandManip::gravityCompensation()
{
   // state
	Cvector pos = Cvector::Zero(AIR_N_U+1); 
	Cvector vel = Cvector::Zero(AIR_N_U);

	// random base quaternion 
	pos.segment(3,3) = Cvector::Zero(3);
	pos[AIR_N_U] = 1;

	//random joint angles
       for (int j = 0; j < DOF_JOINTS/4; j++) 
       { 
           pos[j+6] = (double)_current_joint_position[j];
           pos[j+6+4] = (double)_current_joint_position[j+12];
           pos[j+6+8] = (double)_current_joint_position[j+4];
           pos[j+6+12] = (double)_current_joint_position[j+8];
        }

	

	//definitions
	Model model;
	model.init();
	model.set_state(0, pos, vel);
	Cvector gravity0 = model.get_frcmat();
   gravity = gravity0;

      for (int j = 0; j < DOF_JOINTS/4; j++) 
   { 
      gravity[j+6]      = gravity0[j+6];
      gravity[j+6+12]   = gravity0[j+6+4];
      gravity[j+6+4]    = gravity0[j+6+8];
      gravity[j+6+8]    = gravity0[j+6+12];
   }
   /*
   std::cout << std::setprecision( 3 ) << std::endl << std::fixed;
	std::cout << "  joint      pos        vel       torque  " << std::endl;
	for(int i=0;i<AIR_N_U;i++)
		std::cout << std::setw( 5 ) << i << ":"  <<
			std::setprecision( 2 ) <<std::setw( 11 ) << pos[i] * (i>=6?180/M_PI:1) <<
			std::setprecision( 2 ) <<std::setw( 11 ) << vel[i] <<
			std::setprecision( 2 ) <<std::setw( 11 ) << gravity[i] <<
			std::endl;
	std::cout << std::setw( 5 ) << AIR_N_U << ":"  <<
		std::setprecision( 2 ) <<std::setw( 11 ) << pos[AIR_N_U] <<
		std::endl;
*/
}

/*
void HandManip::updateInverseKinematic(){
   std::size_t attempts = 10;
   double timeout = 0.1;

   bool found_ik0 = kinematic_state->setFromIK(_joint_model_finger_0, X0_dsGenerated_inRef, attempts, timeout);
   bool found_ik1 = kinematic_state->setFromIK(_joint_model_finger_1, X1_dsGenerated_inRef, attempts, timeout);
   bool found_ik2 = kinematic_state->setFromIK(_joint_model_finger_2, X2_dsGenerated_inRef, attempts, timeout);
   bool found_ik3 = kinematic_state->setFromIK(_joint_model_finger_3, X3_dsGenerated_inRef, attempts, timeout);

   if (found_ik0)
    {
     kinematic_state->copyJointGroupPositions(_joint_model_finger_0, _joint_values_finger_0);
    }
    else
    {
      ROS_INFO("Did not find IK0 solution");
   }

   if (found_ik1)
    {
    kinematic_state->copyJointGroupPositions(_joint_model_finger_1, _joint_values_finger_1);
    }
    else
    {
      ROS_INFO("Did not find IK1 solution");
   }

   if (found_ik2)
    {
    kinematic_state->copyJointGroupPositions(_joint_model_finger_2, _joint_values_finger_2);
    }
    else
    {
      ROS_INFO("Did not find IK2 solution");
   }

   if (found_ik3)
    {
    kinematic_state->copyJointGroupPositions(_joint_model_finger_3, _joint_values_finger_3);
    }
    else
    {
      ROS_INFO("Did not find IK3 solution");
   }

}
*/

