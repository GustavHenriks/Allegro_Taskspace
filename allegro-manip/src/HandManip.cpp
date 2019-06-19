#include "HandManip.h"
#include "Utils.h"

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
      _firstOptitrackPose[k] = false;

   _optitrackOK = false;
   _markersPosition.setConstant(0.0f);
   _markersPosition0.setConstant(0.0f);
   _markersOrientation0.setConstant(0.0f);
   _markersOrientation.setConstant(0.0f);

   _markersSequenceID.setConstant(0);
   _markersTracked.setConstant(0);
   _averageCount = 0;
   _p1 << 0.0f, 0.0f, 0.0f;

// Quaternion [w, x, y, z] 
   _qo    << 0.0f, 0.0f, 0.0f, 0.0f;
   _qb    << 0.0f, 0.0f, 0.0f, 0.0f;
   _qb2h  << 0.0f, 0.0f, 1.0f, 0.0f;
   _qo2h  << 0.0f, 0.0f, 0.0f, 0.0f;

   // _p2 << 0.0f, 0.0f, 0.0f;
   base2handRotation.setIdentity();
   base2handRotation(0,0) = -1;
   base2handRotation(2,2) = -1;

   offsetHandOfBase << -0.015, 0.0020, -0.2654; // x : -0.023
   // Object
   _baseOriginPosition.setConstant(0.0f);
   _baseOriginOrientation.setConstant(0.0f);

}


bool HandManip::init(){
   // subscriber definition
   _subJointSates = _n.subscribe("/allegroHand_0/joint_states",1,
      &HandManip::updateHandStates,this,ros::TransportHints().reliable().tcpNoDelay());

   _subOptitrack[0] = _n.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/baseHand/pose", 1,
      boost::bind(&HandManip::updateOptitrack,this,_1,0),ros::VoidPtr(),ros::TransportHints().reliable().tcpNoDelay());

   // _subOptitrack[1] = _n.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/baseHand2/pose", 1,
   //    boost::bind(&HandManip::updateOptitrack,this,_1,1),ros::VoidPtr(),ros::TransportHints().reliable().tcpNoDelay());

   _subOptitrack[1] = _n.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/objectHand2/pose", 1,
      boost::bind(&HandManip::updateOptitrack,this,_1,1),ros::VoidPtr(),ros::TransportHints().reliable().tcpNoDelay());
   //fingertip subscriber to drive the offset
   // _subOptitrack[2] = _n.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/fingerHand/pose", 1,
   //    boost::bind(&HandManip::updateOptitrack,this,_1,2),ros::VoidPtr(),ros::TransportHints().reliable().tcpNoDelay());
   
   //publisher definition
   _pubDesiredJointSates = _n.advertise<sensor_msgs::JointState>("desiredJointState",1);
   _pubJointCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/joint_cmd",  1);
   _pubTorqueCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/torque_cmd",1);

   //initialize the kinematic and jacobian solver

   for (int i = 0; i< NB_Fingers; i++){
      _finger.push_back(Finger());
      
      _finger[i].name = "N";
      
      _finger[i].dsGain = 0.0;
      _finger[i].dsGainMatrix.setConstant(0.0);
      _finger[i].joint_command_finger.setConstant(0.0);

      _finger[i].eigenValue = 0.0;
      _finger[i].eigenValue_dissipative =0.0;
      _finger[i].temp_joint_torque.setConstant(0.0);
      _finger[i].torque_command.setConstant(0.0);
      
      _finger[i].X_inRef.setConstant(0.0);
      _finger[i].X_target_inRef.setConstant(0.0);
      _finger[i].X_dsGenerated_inRef.setConstant(0.0);
      _finger[i].X_rel_inRef.setConstant(0.0);
      _finger[i].X_inObj.setConstant(0.0);

      _finger[i].V_inRef.setConstant(0.0);
      _finger[i].V_ds_inRef.setConstant(0.0);
      
      _finger[i].xp.setConstant(0.0);
      _finger[i].vp.setConstant(0.0);
      
      _finger[i].jacobian_finger.setConstant(0.0);
      _finger[i].JF.setConstant(0.0);

      _finger[i].attractorType = AttractorType::Stabilizer;
      _finger[i].TargRelToObj.setConstant(0.0);
      _finger[i].attractor.onCall.setConstant(0.0);
      _finger[i].attractor.grasp.setConstant(0.0);
      _finger[i].attractor.updator.setConstant(0.0);

      _finger[i].inContact = false; // -> has to be edited

      _finger[i].inForceDir.setConstant(0.0);
   }
   _finger[0].name = "index";
   _finger[1].name = "midle";
   _finger[2].name = "pinky";
   _finger[3].name = "thumb";


   // filter section:
   filterGain = 0.2;
   // Object papram
   _objectCenter = {-0.023  , 0.023   , -0.02}; // object center in Object Frame, Given Optitrack frame
   //             x ^      ________@
   //               |      | o   o |
   //               |      |   C o |
   //         y<----@z     |_o_____|

   // attractor of each ds -> will be reoved later as the ds should be defined from out side of this node
   // _finger[0].X_target_inRef = {0.0795334, -0.02275253, 0.0836488};
   // _finger[1].X_target_inRef = {0.0789154,  0.00851324, 0.0836488};
   // _finger[2].X_target_inRef = {0.0607702,  0.0478584,  0.0563102};
   // _finger[3].X_target_inRef = {0.0778476, -0.0575216,  0.0390766};

   objectGraspPosition =  {0.070, 0.00, 0.100};
   deltaObject.setConstant(0.0);
   regionMargin = 0.06;
   _seqFlag = false;
   _seq2Temp = false;
   SEQ = 0;
   _seqCount = 0;

   // Ds:
   _finger[0].dsGain = 5; //7000 for position Mode Controller
   _finger[1].dsGain = 10;
   _finger[2].dsGain = 12;
   _finger[3].dsGain = 10;
   
   // Sending a minimun force

   EPSILON_FORCE           = 0.0001;
   LIMIT_FORCE             = 1000.00;
   jacobPsudoInvGain        = 0.5;
   nullGainController      = 1.00;
   _null_joint_position[1] = 0.75;
   _null_joint_position[5] = 0.75;
   _null_joint_position[9] = 0.75;
   _null_joint_position[12]= 0.80;
   _null_joint_position[13]= 0.45;
   _null_joint_position[14]= 0.25;
   _null_joint_position[15]= 1.0;

   intForceContributor  = 3.0;
   intForceSrablizer    = 1.5;

   // initializing the passive Ds Controller
   _dimX = 3;

   _finger[0].eigenValue = 5.0;
   _finger[1].eigenValue = 10.0;
   _finger[2].eigenValue = 7.0;
   _finger[3].eigenValue = 7.0;

   _finger[0].eigenValue_dissipative = 7.0;
   _finger[1].eigenValue_dissipative = 10.0;
   _finger[2].eigenValue_dissipative = 10.0;
   _finger[3].eigenValue_dissipative = 10.0;

   for (int i=0; i< NB_Fingers;i++)
      _finger[i].dsController = new DSController(_dimX, _finger[i].eigenValue,_finger[i].eigenValue_dissipative);
   
   initializeKinematic();

   graspInit();

   _mu = 0.3;
   GraspMatrix graspMatrix(_mu);
}

//======================================================================================================//
//========================================= Main Function ==============================================//
//======================================================================================================//

void HandManip::run(){
 while(!_stop && ros::ok()){ 
   if (_firstOptitrackPose[0]&&_firstOptitrackPose[1]){
      _mutex.lock();

      //-----------------------------------------//
      //--------- Check for prerequisits --------//
      //-----------------------------------------//

      // Initialize optitrack
      
      if(!_optitrackOK){
         // ROS_INFO("[ObjectGrasping]: Optitrack Initialization ...");
         optitrackInitialization();
      }
      else{
         //-----------------------------------------//
         //------------ Body of th Code ------------//
         //-----------------------------------------//

         getObjectPose();

         computeCommand();
         publishData();
         
         //-----------------------------------------//
         //------------Save for Output--------------//
         //-----------------------------------------//
         
         //=> Dit: Log Data
         //logData
      }
      _mutex.unlock();
   }
   ros::spinOnce();
   _loopRate.sleep();

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
void HandManip::computeCommand(){
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  //0- Update position and velocity in the desired frame
  //1- Compute the Jacobians:
  //2- Compute the DS
  //3- From the DS then Compute the Desired command 
  //~~~~~~~~~~~~~~~~~~~~~~~~~

  updateFingersPosVel(); // update position and velocity of fingertips all in the reference frame
  updateJacobians(); // get the jacobian of the current pose

  for(int i =0; i<NB_Fingers; i++)
      _finger[i].JF = _finger[i].jacobian_finger.topRows(3);

  attractorsType();
  setAttractors();
  //set internal force:

  computeDS(); // Get the desired velocity

   if (_controllerMode == Position_Mode)
      computeCommandPsMode();
   else if(_controllerMode == Torque_Mode)
      computeCommandTqMode();
}

void HandManip::computeDS(){
   // This is a simple Ds just to test the functionality of the controller
   // which later will be replaced by a  practical ds
   //-> to be corrected
   for (int i=0; i< NB_Fingers;i++){

      _finger[i].dsGainMatrix = _finger[i].dsGain * Eigen::Matrix3d::Identity(3,3);
      _finger[i].V_ds_inRef   = _finger[i].dsGainMatrix * (_finger[i].X_target_inRef - _finger[i].X_inRef);
   }
}

void HandManip::computeCommandPsMode(){
   for (int i=0; i< NB_Fingers;i++){
      _finger[i].X_dsGenerated_inRef = _dt * _finger[i].V_ds_inRef ;//+ X0_inRef; //X0_target_inRef ;
      _finger[i].joint_command_finger =  jacobPsudoInvGain * _finger[i].JF.transpose() * _finger[i].X_dsGenerated_inRef;
      for (int j = 0; j < DOF_JOINTS/4; j++) 
         _desired_joint_position[j+4*i] = _finger[i].joint_command_finger[j] + _current_joint_position[j+4*i];
   }
   // ------Jacobian psudo inverse method 
   // Eigen::MatrixXd tempMat_0 = JF_0.transpose() * JF_0;
   // Eigen::MatrixXd tempMat_1 = JF_1.transpose() * JF_1;
   // Eigen::MatrixXd tempMat_2 = JF_2.transpose() * JF_2;
   // Eigen::MatrixXd tempMat_3 = JF_3.transpose() * JF_3;

   // joint_command_finger_0 = tempMat_0.inverse() * JF_0.transpose() * X0_dsGenerated_inRef;
   // joint_command_finger_1 = tempMat_1.inverse() * JF_1.transpose() * X1_dsGenerated_inRef;
   // joint_command_finger_2 = tempMat_2.inverse() * JF_2.transpose() * X2_dsGenerated_inRef;
   // joint_command_finger_3 = tempMat_3.inverse() * JF_3.transpose() * X3_dsGenerated_inRef;
}

void HandManip::computeCommandTqMode(){

   // -> update the passive Ds
   // -> update ensuring passivity
   // -> update ignoring the passivity (energy tank) : not now

   for (int i = 0; i < NB_Fingers; i++){
      _finger[i].dsController->Update(_finger[i].V_inRef, _finger[i].V_ds_inRef); 
      _finger[i].torque_command =  _finger[i].JF.transpose() * _finger[i].dsController->control_output();
   }

   internalForceControl();

   for (int i = 0; i < NB_Fingers; i++)
      for (int j = 0; j < DOF_JOINTS/4; j++)
         _desired_joint_torque[j+4*i] =   _finger[i].torque_command[j];
   
   // ------Jacobian null space  method to cover the redundancy
   nullSpaceControl();
   // Compensate for the gravity on each joint
   gravityCompensation(); 

   //----Gravity and Limits:
   // torque Command Limits + Allways send a minimum torque
   // gravity compensation tunning gain

   gravity[1+6]  =  gravity[1+6]  * 1.5; // index finger
   gravity[5+6]  =  gravity[5+6]  * 2.5; // middle finger
   gravity[9+6]  =  gravity[9+6]  * 3.5; // pinky finger
   gravity[14+6] =  gravity[14+6] * 2.0; // thumb finger

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

void HandManip::graspInit(){
   
   // Support Fingers Index , Middle:

   // for stabilizing
   // supporter fingers
   _finger[0].attractor.onCall << 0.0  ,-0.05 , 0.03 ;
   _finger[1].attractor.onCall << 0.0  , 0.0 , 0.05 ;

   _finger[0].attractor.grasp <<-0.01  , -0.025, -0.01 ; //0.0  , -0.0275, -0.01 ;
   _finger[1].attractor.grasp << -0.01 , -0.010  , 0.0275;

   _finger[0].attractor.updator << -0.015  , -0.035  , 0.0275; // y was -0.025
   _finger[1].attractor.updator << -0.015  ,  -0.010  , 0.0275;


   // contributor finger
   _finger[2].attractor.onCall << 0.0  , 0.04 , 0.05 ;
   _finger[3].attractor.onCall <<-0.05 ,-0.10 ,-0.08 ;

   _finger[2].attractor.grasp << 0.015, 0.005  , 0.025 ;
   _finger[3].attractor.grasp << 0.015, -0.010 , -0.025;

   _finger[2].attractor.updator << 0.005, 0.035  , 0.09;
   _finger[3].attractor.updator << -0.04 ,-0.10 ,-0.1;

}

void HandManip::attractorsType(){
   deltaObject = X_Object_inRef - objectGraspPosition;
   
   if (deltaObject.norm() > regionMargin )
   {
      SEQ =0;
      _seqCount =0;

   }else if( _seqFlag && SEQ == 0 && ( _seqCount > AVERAGE_COUNT) )
   {
      
      SEQ = 1;
      _seqCount =0;
      _seqFlag =false;

      _finger[0].attractorType = AttractorType::Workspace;
      _finger[1].attractorType = AttractorType::Workspace;
      _finger[2].attractorType = AttractorType::Contributor;
      _finger[3].attractorType = AttractorType::Contributor;

   }else if( _seqFlag && SEQ == 1 )
   { 
      SEQ = 2;
      _seqCount =0;
      _objectInitialX = X_Object_inRef; 
      _seqFlag =false;
      _seq2Temp = false;

   }else if( _seqFlag && SEQ == 2 )
   { 
      SEQ = 3;
      _seqCount =0;
      _seqFlag =false;
      _seq2Temp = false;
      _finger[0].attractorType = AttractorType::Stabilizer;
      _finger[1].attractorType = AttractorType::Stabilizer;
      _finger[2].attractorType = AttractorType::Contributor;
      _finger[3].attractorType = AttractorType::Stabilizer;
   
   }else if( _seqFlag && SEQ == 3 && ( _seqCount > AVERAGE_COUNT) )
   { 
      SEQ = 4;
      _seqCount =0;
      _seqFlag =false;
      _seq2Temp = false;

      _finger[2].attractorType = AttractorType::Stabilizer;

   }else if( _seqFlag && SEQ == 4 && ( _seqCount > AVERAGE_COUNT) )
   { 
      SEQ =0;
      _seqCount =0;
      _seqFlag =false;
   }
   //--------------------------------------------------------------------
   //--------SEQ 0
   //--------------------------------------------------------------------
   if (SEQ == 0){

      _finger[0].dsGain = 10; //7000 for position Mode Controller
      _finger[1].dsGain = 10;
      _finger[2].dsGain = 10;
      _finger[3].dsGain = 10;

      _finger[0].eigenValue = 5.0;
      _finger[1].eigenValue = 7.5;
      _finger[2].eigenValue = 10.0;
      _finger[3].eigenValue = 10.0;

      _finger[0].eigenValue_dissipative = 5.0;
      _finger[1].eigenValue_dissipative = 7.5;
      _finger[2].eigenValue_dissipative = 10.0;
      _finger[3].eigenValue_dissipative = 10.0;

      for(int i =0; i< NB_Fingers; i++)
         _finger[i].attractorType = AttractorType::Stabilizer;

   }
   //--------------------------------------------------------------------
   //--------SEQ 1
   //--------------------------------------------------------------------
   if (SEQ == 1){
      _finger[0].dsGain = 4; //7000 for position Mode Controller
      _finger[1].dsGain = 4;
      _finger[2].dsGain = 8;
      _finger[3].dsGain = 8;

      _finger[0].eigenValue = 3.0;
      _finger[1].eigenValue = 5.0;
      _finger[2].eigenValue = 10.0;
      _finger[3].eigenValue = 10.0;

      _finger[0].eigenValue_dissipative = 3.0;
      _finger[1].eigenValue_dissipative = 5.0;
      _finger[2].eigenValue_dissipative = 10.0;
      _finger[3].eigenValue_dissipative = 10.0;

   }
   //--------------------------------------------------------------------
   //--------SEQ 2
   //--------------------------------------------------------------------
   if (SEQ == 2){
      _finger[0].dsGain = 8; //7000 for position Mode Controller
      _finger[1].dsGain = 8;
      _finger[2].dsGain = 4;
      _finger[3].dsGain = 8;

      _finger[0].eigenValue = 5.0;
      _finger[1].eigenValue = 7.5;
      _finger[2].eigenValue = 2;
      _finger[3].eigenValue = 10.0;

      _finger[0].eigenValue_dissipative = 5.0;
      _finger[1].eigenValue_dissipative = 7.5;
      _finger[2].eigenValue_dissipative = 2;
      _finger[3].eigenValue_dissipative = 10.0;

   }
   //--------------------------------------------------------------------
   //--------SEQ 3
   //--------------------------------------------------------------------
   if (SEQ == 3){
      _finger[0].dsGain = 8; //7000 for position Mode Controller
      _finger[1].dsGain = 8;
      _finger[2].dsGain = 4;
      _finger[3].dsGain = 8;

      _finger[0].eigenValue = 7.5;
      _finger[1].eigenValue = 10.0;
      _finger[2].eigenValue = 2;
      _finger[3].eigenValue = 12.0;

      _finger[0].eigenValue_dissipative = 7.5;
      _finger[1].eigenValue_dissipative = 10.0;
      _finger[2].eigenValue_dissipative = 2;
      _finger[3].eigenValue_dissipative = 12.0;

   }
   //--------------------------------------------------------------------
   //--------SEQ 4
   //--------------------------------------------------------------------
   if (SEQ == 4){
      _finger[2].dsGain = 8;
      _finger[2].eigenValue = 12.0;
      _finger[2].eigenValue_dissipative = 12.0;

   }

   for(int i =0; i< NB_Fingers; i++)
         _finger[i].dsController->set_damping_eigval(_finger[i].eigenValue,_finger[i].eigenValue_dissipative);
   
}

void HandManip::setAttractors(){
   deltaObject = X_Object_inRef - objectGraspPosition;
   // std::cout << X_Object_inRef << std::endl << std::endl;
   
   //----------------Computing for the regions of action------------:
   // std::cout << " Norm Distance =   "<< deltaObject.norm() << std::endl << std::endl;

   int seqFlacgCount = 0;
   if (SEQ == 0){

      for(int i =0; i< NB_Fingers; i++){
         _finger[i].dsController->set_damping_eigval(_finger[i].eigenValue,_finger[i].eigenValue_dissipative);

         if (deltaObject.norm() > 2.5 * regionMargin ){
            ROS_INFO("First region of grasp ...");
            _finger[i].TargRelToObj = _finger[i].attractor.onCall ;
            _finger[i].inContact = false;

         }else if (deltaObject.norm() > regionMargin ){
            ROS_INFO("Second region of grasp ...");
            _finger[i].TargRelToObj = 1.5 * (deltaObject.norm() / regionMargin) * _finger[i].attractor.grasp ;
            _finger[i].inContact = false;

         }else{
            ROS_INFO("Third region of grasp ...");
            _finger[i].inContact = true;
            _finger[i].TargRelToObj =_finger[i].attractor.grasp ;
            // -> In the case of object frame to refrence frame transformation
         }
         _finger[i].X_target_inRef = objectGraspPosition + _finger[i].TargRelToObj;

         if ((_finger[i].X_rel_inRef - _finger[i].TargRelToObj).norm() < 0.05 ){
            seqFlacgCount ++;
            _seqCount ++;
            // std::cout << "seqFlacgCount =  " << seqFlacgCount << std::endl;
            // std::cout << "seq counter   =  " << _seqCount << std::endl;
         }
      }

   //--------------------------------------------------------------------
   //--------SEQ 1
   //--------------------------------------------------------------------
   } else if (SEQ == 1){
      
      for(int i =0; i< NB_Fingers; i++)
      {
         if (_finger[i].attractorType == Contributor)
         {
            // will be updated
            Eigen::Vector3d _wrench = {0.0, _finger[i].X_rel_inRef[1], _finger[i].X_rel_inRef[2]};
            _wrench = _wrench.normalized();
            Eigen::Vector3d _rotAxis= {-1.0, 0.0, 0.0 };
            Eigen::Vector3d _ta = _rotAxis.cross(_wrench);
            _ta = _ta.normalized();
            _ta = 0.75 * _ta - 0.25 * _wrench;
            _ta = _ta.normalized();
            
            _finger[i].X_target_inRef = objectGraspPosition  + 0.12 *_ta; //0.05


            if ( _finger[i].V_inRef.norm() < 0.0075 ){
               seqFlacgCount +=2;
            } 
         }else if (_finger[i].attractorType == Workspace){
            _finger[i].X_target_inRef = objectGraspPosition + _finger[i].attractor.updator;
            // std::cout << "in the loop " << std::endl << std::endl;
         }
      }
      // -> Dummy Condition just for testing
      Eigen::Vector3d deltaFing = _finger[3].X_rel_inRef - _finger[2].X_rel_inRef;
      deltaFing = deltaFing.normalized();
      Eigen::Vector3d zdir = {0.0,0.0,-1.0};
      if (  deltaFing.transpose() * zdir > 0.3)
         seqFlacgCount --;
   //--------------------------------------------------------------------
   //--------SEQ 2
   //--------------------------------------------------------------------
   }else if (SEQ == 2)
   {
      for(int i =0; i< NB_Fingers; i++)
      {
         _finger[i].inContact = true;
         if (  _finger[1].X_rel_inRef[1] < 0)
         {
            if (i == 3 ){
               //===> inc
               _finger[i].TargRelToObj = 0.025 * ( X_Object_inRef - _finger[i].X_inRef).normalized();
            
            }else{

               _finger[i].TargRelToObj =_finger[i].attractor.grasp ;
               seqFlacgCount ++;

            }
            // -> To be corrected

         }else if ( (X_Object_inRef - _objectInitialX ).norm() > 0.01 )
         {
               seqFlacgCount ++;
               _seqCount ++;
         }else{
            seqFlacgCount +=4;
         }
         _finger[i].X_target_inRef = objectGraspPosition + _finger[i].TargRelToObj;

      }
   //--------------------------------------------------------------------
   //--------SEQ 3
   //--------------------------------------------------------------------
   }else if (SEQ == 3){
      // -> HERE a learned Ds has to be implemented 
      // but just to tes this situation
      seqFlacgCount ++;
      for(int i =0; i< NB_Fingers; i++){
         if (i != 2){
            _finger[i].inContact = true;

            if (i==3 && !_seq2Temp){
               _finger[i].inContact = false;
               _finger[i].TargRelToObj =  _finger[i].attractor.updator;
               if ((_finger[i].X_rel_inRef -_finger[i].TargRelToObj).norm() < 0.04){
                  // std::cout << "SEQ 2 Flasg of the Attractor  " << std::endl;
                  if ( _finger[i].V_inRef.norm() < 0.004)
                     _seq2Temp = true;
               }
            }else {
               _finger[i].TargRelToObj =_finger[i].attractor.grasp ;
               if (i == 3 && ((_finger[i].X_rel_inRef - _finger[i].TargRelToObj).norm() < 0.04) ){
                  seqFlacgCount ++;
                  _seqCount ++;
               }else if (i != 3){
                  seqFlacgCount ++;
                  _seqCount ++;

               }
            }
            _finger[i].X_target_inRef = objectGraspPosition + _finger[i].TargRelToObj;

         }
      }
   //--------------------------------------------------------------------
   //--------SEQ 4
   //--------------------------------------------------------------------
   }else if (SEQ == 4){
      for(int i =0; i< NB_Fingers; i++){
         _finger[i].inContact = true;
   
         if (i==2 && !_seq2Temp){
            _finger[i].inContact = false;
            _finger[i].TargRelToObj =  _finger[i].attractor.updator ;
            if ((_finger[i].X_rel_inRef -_finger[i].TargRelToObj).norm() < 0.03){
               // std::cout << "SEQ 2 Flasg of the Attractor  " << std::endl;
               if ( _finger[i].V_inRef.norm() < 0.0075)
                  _seq2Temp = true;
            }
   
            // _firstTraget = (_finger[i].X_rel_inRef - _finger[i].TargRelToObj).norm();
            // if (_firstTraget > 0.02)
         }else {
            _finger[i].TargRelToObj =_finger[i].attractor.grasp ;
         }
         _finger[i].X_target_inRef = objectGraspPosition + _finger[i].TargRelToObj;

      if ((_finger[i].X_rel_inRef - _finger[i].TargRelToObj).norm() < 0.05 ){
            seqFlacgCount ++;
            _seqCount ++;
            // std::cout << "seqFlacgCount =  " << seqFlacgCount << std::endl;
            // std::cout << "seq counter   =  " << _seqCount << std::endl;
      }
      
      }
   }

   if (seqFlacgCount > 3){
      _seqFlag = true;
   }
   std::cout << "SEQ Flasg =  " << SEQ << std::endl;
}

void HandManip::gravityCompensation(){
   // state
	Cvector pos = Cvector::Zero(AIR_N_U+1); 
	Cvector vel = Cvector::Zero(AIR_N_U);

	// random base quaternion 
	pos.segment(3,3) = Cvector::Zero(3);
   pos[3] = 1;
	pos[AIR_N_U] = 0;

	//random joint angles
       for (int j = 0; j < DOF_JOINTS/4; j++) 
       { 
           pos[j+6]     = (double)_current_joint_position[j];
           pos[j+6+4]   = (double)_current_joint_position[j+12];
           pos[j+6+8]   = (double)_current_joint_position[j+4];
           pos[j+6+12]  = (double)_current_joint_position[j+8];
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
void HandManip::nullSpaceControl(){
   for (int i = 0; i < NB_Fingers; i++)
      for (int j = 0; j < DOF_JOINTS/4; j++)
         _finger[i].temp_joint_torque[j] = (double)(-1 * nullGainController * (_current_joint_position[j+4*i]  - _null_joint_position[j+4*i]));

   Eigen::MatrixXd tempMat_0 = _finger[0].JF * _finger[0].JF.transpose();
   Eigen::MatrixXd tempMat_1 = _finger[1].JF * _finger[1].JF.transpose();
   Eigen::MatrixXd tempMat_2 = _finger[2].JF * _finger[2].JF.transpose();
   Eigen::MatrixXd tempMat_3 = _finger[3].JF * _finger[3].JF.transpose();

   Eigen::MatrixXd nullMat_0 =  Eigen::MatrixXd::Identity(4,4) - (_finger[0].JF.transpose() * tempMat_0.inverse() * _finger[0].JF);
   Eigen::MatrixXd nullMat_1 =  Eigen::MatrixXd::Identity(4,4) - (_finger[1].JF.transpose() * tempMat_1.inverse() * _finger[1].JF);
   Eigen::MatrixXd nullMat_2 =  Eigen::MatrixXd::Identity(4,4) - (_finger[2].JF.transpose() * tempMat_2.inverse() * _finger[2].JF);
   Eigen::MatrixXd nullMat_3 =  Eigen::MatrixXd::Identity(4,4) - (_finger[3].JF.transpose() * tempMat_3.inverse() * _finger[3].JF);

   for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _null_joint_torque[j]   = nullMat_0.row(j) * _finger[0].temp_joint_torque;
      _null_joint_torque[j+4] = nullMat_1.row(j) * _finger[1].temp_joint_torque;
      _null_joint_torque[j+8] = nullMat_2.row(j) * _finger[2].temp_joint_torque;
      _null_joint_torque[j+12]= nullMat_3.row(j) * _finger[3].temp_joint_torque;
   }

   for (int j =0; j < DOF_JOINTS; j++)
      _desired_joint_torque[j] += _null_joint_torque[j]; 

}

void HandManip::internalForceControl(){
   // intForceSrablizer;
   float _intForceGain =  intForceSrablizer;
   for (int i = 0; i < NB_Fingers; i++)
   {
      _finger[i].inForceDir = X_Object_inRef - _finger[i].X_inRef;
      _finger[i].inForceDir = _finger[i].inForceDir.normalized();
   }

   if (SEQ == 1)
   {
      _finger[0].inForceDir = 0.001 * _finger[0].inForceDir;
      _finger[1].inForceDir = 0.01 * _finger[1].inForceDir;
      _finger[2].inForceDir = _finger[3].X_rel_inRef - _finger[2].X_rel_inRef;
      _finger[3].inForceDir = _finger[2].X_rel_inRef - _finger[3].X_rel_inRef;
      _intForceGain = intForceContributor;
   }
   if (SEQ == 3)
      _finger[3].inForceDir.setConstant(0.0);
   
   if (SEQ == 4)
      _finger[2].inForceDir.setConstant(0.0);

   if ( deltaObject.norm() > regionMargin )
      _intForceGain = 0.0;

   for (int i = 0; i < NB_Fingers; i++)
      _finger[i].torque_command += _intForceGain * _finger[i].JF.transpose() *  _finger[i].inForceDir;
   

}


//======================================================================================================//
//================================ Subscriber and Publisher Function ===================================//
//======================================================================================================//
void HandManip::updateHandStates(const sensor_msgs::JointState &msg){
   for (int i = 0; i < DOF_JOINTS; i++){
      _current_joint_position[i] = msg.position[i];
      _current_joint_velocity[i] = msg.velocity[i];
      _current_joint_torque[i]   = msg.effort[i];
   }
}

void HandManip::publishData(){

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

void HandManip::optitrackInitialization(){
   // ROS_INFO("[ObjectGrasping]: Optitrack Initialization First ...");
  if(_averageCount< AVERAGE_COUNT){
    if( _markersTracked(0) ){
      _markersPosition0 = (_averageCount*_markersPosition0+_markersPosition)/(_averageCount+1);

      _markersOrientation0 = (_averageCount*_markersOrientation0+_markersOrientation)/(_averageCount+1);
      _averageCount++;
      // std::cout << _averageCount << std::endl;
    }
   //  std::cerr << "[ObjectGrasping]: Optitrack Initialization count: " << _averageCount << std::endl;
    if(_averageCount == 1){
      ROS_INFO("Optitrack Initialization starting ...");
    }
    else if(_averageCount == AVERAGE_COUNT){
      ROS_INFO("Optitrack Initialization done !");
      // ----------------Now set the origin
      // _leftRobotOrigin = _markersPosition0.col(ROBOT_BASIS_LEFT)-_markersPosition0.col(ROBOT_BASIS_RIGHT);
      //  _baseOriginPosition = (_markersPosition0.col(0)+_markersPosition0.col(1))/2.0f;
       _baseOriginPosition = _markersPosition0.col(0);
       _baseOriginOrientation = _markersOrientation0.col(0) ;
    }
  }
  else{
    _optitrackOK = true;
  }
}

void HandManip::updateOptitrack(const geometry_msgs::PoseStamped::ConstPtr& msg, int k){
    if(!_firstOptitrackPose[k]){
    _firstOptitrackPose[k] = true;
   //  ROS_INFO("[ObjectGrasping]: Optitrack first pose ...");
  }
   // ROS_INFO("[ObjectGrasping]: Optitrack Update ...");
   _markersSequenceID(k) = msg->header.seq;
   _markersTracked(k) = checkTrackedMarker(_markersPosition.col(k)(0),msg->pose.position.x);
   // _markersTracked(k) = 1;
   // std::cout <<  _markersTracked(k) << std::endl;
   _markersPosition.col(k) << msg->pose.position.x, msg->pose.position.y, msg->pose.position.z;
   _markersOrientation.col(k) <<  msg->pose.orientation.w, msg->pose.orientation.x, msg->pose.orientation.y, msg->pose.orientation.z;

}

uint16_t HandManip::checkTrackedMarker(float a, float b){
  if(fabs(a-b)< FLT_EPSILON){
    return 0;
  }
  else{
    return 1;
  }
}



//======================================================================================================//
//================================ Kinematic and Dynamic Function ======================================//
//======================================================================================================//
// -------------Object------------//
void HandManip::getObjectPose(){
   if(_markersTracked.sum() == TOTAL_NB_MARKERS){
      // Compute markers position in the hand robot frame
      _p1 = filterGain * (_markersPosition.col(1) - _baseOriginPosition ) + (1-filterGain)*_p1;

      _qb = _baseOriginOrientation.normalized();

      _qo = filterGain * (_markersOrientation.col(1)) + (1- filterGain)*_qo;
      _qo = _qo.normalized();

      Eigen::Vector4f _qbinv;
      _qbinv[0] = _qb[0];
      _qbinv.segment(1,3) = -1 * _qb.segment(1,3);
      _qbinv = _qbinv.normalized();
      
      Eigen::Matrix3f _qbR = Utils<float>::quaternionToRotationMatrix(_qbinv);
      Eigen::Matrix3f _opti2handR = base2handRotation * _qbR;
      _p1f =  _opti2handR * _p1;

      // fingertip to find the offset
         // _p2 = filterGain * (_markersPosition.col(2)-_markersPosition0.col(0)) + (1-filterGain)*_p2;
         // _p2f = base2handRotation * _p2;
         //offsetHandOfBase = filterGain*( _p2f.cast <double> () - X0_current_inRef) + (1-filterGain)*offsetHandOfBase;
         //std::cout << offsetHandOfBase << std::endl  << std::endl;
      //
      X_Object_inRef = _p1f.cast <double> () - offsetHandOfBase;

      //----------->>>>> The visualization market will be added later.

      //----> object orientation also
      Eigen::Vector4f _qo2b = Utils<float>::quaternionProduct(_qbinv.normalized(),_qo.normalized());
      _qo2b = _qo2b.normalized();
      _qo2h = Utils<float>::quaternionProduct(_qb2h.normalized(),_qo2b);
  
      Q_Object_inRef = _qo2h.cast <double> ();
      Q_Object_inRef =  Q_Object_inRef.normalized();

      // objectRotationMatrix =  _opti2handR.cast <double> ();
      Eigen::Matrix3f _obj2handR = _opti2handR *  Utils<float>::quaternionToRotationMatrix(_qo);

      objectRotationMatrix =  _obj2handR.cast <double>();            // From Object Frame to Reference Frame
      // std::cout << objectRotationMatrix << std::endl << std::endl;
      X_Object_inRef = X_Object_inRef + objectRotationMatrix * _objectCenter;
   }
}
/*
Eigen::Vector4d HandManip::getObjectOrientation(){
   
   if(_markersTracked.sum() == TOTAL_NB_MARKERS)
   {
   //----> object orientation also
   _qb = filterGain * (_markersOrientation.col(0)) + (1-filterGain)*_qb;
   _qo = filterGain * (_markersOrientation.col(1)) + (1-filterGain)*_qo;

   Eigen::Vector4f _qbinv;
   _qbinv[0] = _qb[0];
   _qbinv.segment(1,3) = -1 * _qb.segment(1,3);

   Eigen::Vector4f _qo2b = Utils<float>::quaternionProduct(_qbinv,_qo);
   _qo2h = Utils<float>::quaternionProduct(_qb2h,_qo2b);
      
   Eigen::Vector4d _qobject = _qo2h.cast <double> ();
   return _qobject;
   }

}
*/
//----------- Hand ------------//
void HandManip::initializeKinematic(){
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
    
    _finger[0].joint_model_finger = kinematic_model->getJointModelGroup("finger_0");
    _finger[1].joint_model_finger = kinematic_model->getJointModelGroup("finger_1");
    _finger[2].joint_model_finger = kinematic_model->getJointModelGroup("finger_2");
    _finger[3].joint_model_finger = kinematic_model->getJointModelGroup("finger_3");
    
    const std::vector<std::string>& joint_names_finger_0 = _finger[0].joint_model_finger->getVariableNames();
    const std::vector<std::string>& joint_names_finger_1 = _finger[1].joint_model_finger->getVariableNames();
    const std::vector<std::string>& joint_names_finger_2 = _finger[2].joint_model_finger->getVariableNames();
    const std::vector<std::string>& joint_names_finger_3 = _finger[3].joint_model_finger->getVariableNames();

   for (int i =0; i< NB_Fingers; i++){
      kinematic_state->copyJointGroupPositions(_finger[i].joint_model_finger, _finger[i].joint_values_finger);

   }

    for (std::size_t i = 0; i < joint_names_finger_0.size(); ++i)
        ROS_INFO("Joint %s: %f", joint_names_finger_0[i].c_str(), _finger[0].joint_values_finger[i]);
}

void HandManip::updateForwardKinematic(){
    // Now, we can compute forward kinematics for a set of random joint values. (not necessary)
    // kinematic_state->setToRandomPositions(joint_model_group);
    // Note that we would like to find the pose of the "fingerTip"
    for (int i =0; i< NB_Fingers; i++){
       for (int j = 0; j < DOF_JOINTS/4; j++)
         _finger[i].joint_values_finger[j] = (double)_current_joint_position[j+4*i];
      
      kinematic_state->setJointGroupPositions(_finger[i].joint_model_finger,  _finger[i].joint_values_finger);

    }
    const Eigen::Affine3d& state_fingertip_0 = kinematic_state->getGlobalLinkTransform("link_3_tip");
    const Eigen::Affine3d& state_fingertip_1 = kinematic_state->getGlobalLinkTransform("link_7_tip");
    const Eigen::Affine3d& state_fingertip_2 = kinematic_state->getGlobalLinkTransform("link_11_tip");
    const Eigen::Affine3d& state_fingertip_3 = kinematic_state->getGlobalLinkTransform("link_15_tip");

    _finger[0].X_inRef = state_fingertip_0.translation();
    _finger[1].X_inRef = state_fingertip_1.translation();
    _finger[2].X_inRef = state_fingertip_2.translation();
    _finger[3].X_inRef = state_fingertip_3.translation();

   //  ROS_INFO_STREAM("Rotation: \n" << state_fingertip_0.rotation() << "\n");
}

void HandManip::updateJacobians(){
   // We can also get the Jacobian from the :moveit_core:`RobotState`.
      for (int i = 0; i < NB_Fingers; i++)
         kinematic_state->getJacobian(_finger[i].joint_model_finger,
                                    kinematic_state->getLinkModel(_finger[i].joint_model_finger->getLinkModelNames().back()),
                                    reference_point_position, 
                                    _finger[i].jacobian_finger);
      // ROS_INFO_STREAM("Jacobian: \n" << jacobian_finger_0 << "\n");
   //
}

void HandManip::updateFingersPosVel(){
   // get positions in Ref
   updateForwardKinematic();

   // get velocity in Ref 
   // to filter : V_filtered_t = alpha*V_t + (1-alpha)*V_filtered_previous
   for(int i =0; i< NB_Fingers; i++){
      for(int j =0; j<3; j++){
         _finger[i].V_inRef[j] = filterGain * ( (_finger[i].X_inRef[j] - _finger[i].xp[j])/_dt ) + (1-filterGain)*_finger[i].vp[j];
         _finger[i].vp[j] = _finger[i].V_inRef[j]; 
         _finger[i].xp[j] = _finger[i].X_inRef[j]; 
      }
      _finger[i].X_rel_inRef = _finger[i].X_inRef - X_Object_inRef;
      _finger[i].X_inObj = objectRotationMatrix.transpose() * _finger[i].X_rel_inRef;
   }
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

