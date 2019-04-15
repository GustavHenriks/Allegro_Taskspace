#include "HandManip.h"

HandManip* HandManip::me = NULL;
//=============== Class Condtruction
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
   _gravity << 0.0f, 0.0f, -9.80665f;
}


bool HandManip::init()
{
   // subscriber definition
   _subJointSates = _n.subscribe("/allegroHand_0/joint_states",1,
      &HandManip::updateHandStates,this,ros::TransportHints().reliable().tcpNoDelay());

   //publisher definition
   _pubDesiredJointSates = _n.advertise<sensor_msgs::JointState>("desiredJointState",1);
   _pubJointCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/joint_cmd",  1);
   _pubTorqueCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/torque_cmd",1);

   //initialize the kinematic and jacobian solver
   initializeKinemtic();

   _x0p = {0.0 , 0.0 , 0.0};
   _x1p = {0.0 , 0.0 , 0.0};
   _x2p = {0.0 , 0.0 , 0.0};
   _x3p = {0.0 , 0.0 , 0.0};

   _v0p = {0.0 , 0.0 , 0.0};
   _v1p = {0.0 , 0.0 , 0.0};
   _v2p = {0.0 , 0.0 , 0.0};
   _v3p = {0.0 , 0.0 , 0.0};

   filterGain = 0.2;
   // attractor of each ds
   X0_target_inRef = {0.0795334, -0.02275253, 0.0836488};
   X1_target_inRef = {0.0789154,  0.00851324, 0.10631  };
   X2_target_inRef = {0.0607702,  0.0478584,  0.0563102};
   X3_target_inRef = {0.0778476, -0.0575216,  0.0390766};

   alphaGain = 15; //7000
   dsGainMatrix_0 = alphaGain * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_1 = alphaGain * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_2 = 3 * alphaGain * Eigen::Matrix3d::Identity(3,3);
   dsGainMatrix_3 = 3 * alphaGain * Eigen::Matrix3d::Identity(3,3);

   // initializing the passive Ds Controller
   _dimX = 3;
   _eigenValue_0 = 2.50;
   _eigenValue_1 = 2.50;
   _eigenValue_2 = 3.0;
   _eigenValue_3 = 4.0;

   _eigenValue_dissipative_0 = 5.0;
   _eigenValue_dissipative_1 = 5.0;
   _eigenValue_dissipative_2 = 5.0;
   _eigenValue_dissipative_3 = 5.0;

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
    // if(!_optitrackOK)
    //  {
    //   optitrackInitialization();
    //  }
    //  else
    // {What is BELOW }


    //-----------------------------------------//
    //------------ Body of th Code ------------//
    //-----------------------------------------//
    
    computeCommand();

    publishData();
    
    
    //-----------------------------------------//
    //------------Save for Output--------------//
    //-----------------------------------------//
    
    //=> Dit: Log Data
    //logData

    ros::spinOnce();
    _loopRate.sleep();

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

void HandManip::computeCommand()
{
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  //0- Compute the Jacobians:
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  
  updateRefPosVel();
  updateJacobians();
  JF_0 = jacobian_finger_0.topRows(3);
  JF_1 = jacobian_finger_1.topRows(3);
  JF_2 = jacobian_finger_2.topRows(3);
  JF_3 = jacobian_finger_3.topRows(3);
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  //1- Compute the Ds
  //~~~~~~~~~~~~~~~~~~~~~~~~~
  computeDS();
   // Compute the last degre of freedom, orientatin 

  //~~~~~~~~~~~~~~~~~~~~~~~~~
  //2- Compute the Command
  //~~~~~~~~~~~~~~~~~~~~~~~~~
   if (_controllerMode == Position_Mode){
      computeCommandPsMode();
   }
   else if(_controllerMode == Torque_Mode){
      computeCommandTqMode();
   }


}

//======================================================================================================//
//====================================== Control  Function =============================================//
//======================================================================================================//

void HandManip::computeDS()
{

   V0_ds_inRef = dsGainMatrix_0 * (X0_target_inRef - X0_current_inRef);
   V1_ds_inRef = dsGainMatrix_1 * (X1_target_inRef - X1_current_inRef);
   V2_ds_inRef = dsGainMatrix_2 * (X2_target_inRef - X2_current_inRef);
   V3_ds_inRef = dsGainMatrix_3 * (X3_target_inRef - X3_current_inRef);
   
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
   // ---------------------------Gravity Compensation
   // update the passive Ds
   // update ensuring passivity
   // control_force = my_passive_ds->UpdatePassive(actual_velocity, desired_velocity, dt);

   // update ignoring the passivity 
   dsController_0->Update(V0_current_inRef, V0_ds_inRef);
   dsController_1->Update(V1_current_inRef, V1_ds_inRef);
   dsController_2->Update(V2_current_inRef, V2_ds_inRef);
   dsController_3->Update(V3_current_inRef, V3_ds_inRef);

   _torque_command_0 =  JF_0.transpose() * dsController_0->control_output();
   _torque_command_1 =  JF_1.transpose() * dsController_1->control_output();
   _torque_command_2 =  JF_2.transpose() * dsController_2->control_output();
   _torque_command_3 =  JF_3.transpose() * dsController_3->control_output();

   gravityCompensation();

   for (int j = 0; j < DOF_JOINTS/4; j++) { 
      _desired_joint_torque[j]   = _torque_command_0[j];
      _desired_joint_torque[j+4] = _torque_command_1[j];
      _desired_joint_torque[j+8] = _torque_command_2[j];
      _desired_joint_torque[j+12]= _torque_command_3[j];
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

void HandManip::updateRefPosVel()
{
   // get positions in Ref
   updateForwardKinematic();

   // get velocity in Ref
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

void HandManip::publishData()
{

 for (int i = 0; i < DOF_JOINTS; i++) {
   _msgDesiredJointStates.position[i] = _desired_joint_position[i];
   // _msgDesiredJointStates.velocity[i] = _desired_joint_velocity[i];
    _msgDesiredJointStates.effort[i] = _desired_joint_torque[i];
  }

   //  _pubDesiredJointSates.publish(_msgDesiredJointStates);
   if(_controllerMode == Torque_Mode)
   {
      _pubTorqueCmd.publish(_msgDesiredJointStates);
   }
   else if(_controllerMode == Position_Mode){
      _pubJointCmd.publish(_msgDesiredJointStates); 
   }

 
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
    
     
   
    /* Print end-effector pose. Remember that this is in the model frame */
   //  ROS_INFO_STREAM("Rotation: \n" << state_fingertip_0.rotation() << "\n");
   // ROS_INFO_STREAM("Translation finger_1: \n" << X0_current_inRef << "\n");
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

void HandManip:: gravityCompensation()
{

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