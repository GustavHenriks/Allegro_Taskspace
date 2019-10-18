#include "HandManip2.h"

HandManip *HandManip::me = NULL;

//======================================================================================================//
//=================================== Condtruction & Initialization ====================================//
//======================================================================================================//

HandManip::HandManip(ros::NodeHandle &n, double frequency, ControllerMode controllerMode) : _n(n),
                                                                                            _loopRate(frequency),
                                                                                            _dt(1.0f / frequency),
                                                                                            _controllerMode(controllerMode)
{
   me = this;
   //---------------------------------
   // Define the parameter that you will use later
   //-------------------------------
   _current_joint_position[DOF_JOINTS] = {0.0};
   _current_joint_velocity[DOF_JOINTS] = {0.0};
   _current_joint_torque[DOF_JOINTS] = {0.0};
   _desired_joint_position[DOF_JOINTS] = {0.0};
   _desired_joint_velocity[DOF_JOINTS] = {0.0};
   _desired_joint_torque[DOF_JOINTS] = {0.0};

   _msgJointCmd.position.resize(DOF_JOINTS);
   _msgJointCmd.velocity.resize(DOF_JOINTS);
   _msgJointCmd.effort.resize(DOF_JOINTS);

   _msgRealJointStates.position.resize(DOF_JOINTS);
   _msgRealJointStates.velocity.resize(DOF_JOINTS);
   _msgRealJointStates.effort.resize(DOF_JOINTS);

   _msgDesiredJointStates.position.resize(DOF_JOINTS);
   _msgDesiredJointStates.velocity.resize(DOF_JOINTS);
   _msgDesiredJointStates.effort.resize(DOF_JOINTS);

   _stop = false;

   reference_point_position = {0.0, 0.0, 0.0};
   // reference pose
   _gravity << 9.80665f, 0.0f, 0.0f;

   // Optitrack
   for (int k = 0; k < TOTAL_NB_MARKERS; k++)
      _firstOptitrackPose[k] = true;

   _optitrackOK = true;
   _markersPosition.setConstant(0.0f);
   _markersPosition0.setConstant(0.0f);
   _markersOrientation0.setConstant(0.0f);
   _markersOrientation.setConstant(0.0f);

   _markersSequenceID.setConstant(0);
   _markersTracked.setConstant(0);
   _averageCount = 0;
   _p1 << 0.0f, 0.0f, 0.0f;

   // Quaternion [w, x, y, z]
   _qo << 0.0f, 0.0f, 0.0f, 0.0f;
   _qb << 0.0f, 0.0f, 0.0f, 0.0f;
   _qb2h << 0.0f, 0.0f, 1.0f, 0.0f;
   _qo2h << 0.0f, 0.0f, 0.0f, 0.0f;

   // _p2 << 0.0f, 0.0f, 0.0f;
   base2handRotation.setIdentity();
   base2handRotation(0, 0) = -1;
   base2handRotation(2, 2) = -1;

   offsetHandOfBase << -0.015, 0.0020, -0.2654; // x : -0.023
   // Object
   _baseOriginPosition.setConstant(0.0f);
   _baseOriginOrientation.setConstant(0.0f);
}

bool HandManip::init()
{
   // subscriber definition
   _subJointSates = _n.subscribe("/allegroHand_0/joint_states", 1,
                                 &HandManip::updateHandStates, this, ros::TransportHints().reliable().tcpNoDelay());
   _subGrab = _n.subscribe("/grab", 1, &HandManip::updateGrabState, this);
   // _subRobotPos = _n.subscribe("/grab", 1, &HandManip::updateGrabState, this);

   // _subOptitrack[0] = _n.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/baseHand/pose", 1,
   //    boost::bind(&HandManip::updateOptitrack,this,_1,0),ros::VoidPtr(),ros::TransportHints().reliable().tcpNoDelay());

   //publisher definition
   _pubDesiredJointSates = _n.advertise<sensor_msgs::JointState>("desiredJointState", 1);
   _pubJointCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/joint_cmd", 1);
   _pubTorqueCmd = _n.advertise<sensor_msgs::JointState>("/allegroHand_0/torque_cmd", 1);
   _pubThumb = _n.advertise<std_msgs::Float64MultiArray>("/thumb_forces", 1);
   _pub_DesiredPath = _n.advertise<nav_msgs::Path>("/thumb_desired_path", 1);
   _pubGrasp = _n.advertise<std_msgs::Int8>("/grasped", 1);

   //initialize the kinematic and jacobian solver

   for (int i = 0; i < NB_Fingers; i++)
   {
      _finger.push_back(Finger());

      _finger[i].name = "N";

      _finger[i].dsGain = 0.0;
      _finger[i].dsGainMatrix.setConstant(0.0);
      _finger[i].joint_command_finger.setConstant(0.0);

      _finger[i].eigenValue = 0.0;
      _finger[i].eigenValue_dissipative = 0.0;
      _finger[i].temp_joint_torque.setConstant(0.0);
      _finger[i].torque_command.setConstant(0.0);

      _finger[i].X_inRef.setConstant(0.0);
      _finger[i].X_target_inRef.setConstant(0.0);
      _finger[i].X_dsGenerated_inRef.setConstant(0.0);

      _finger[i].V_inRef.setConstant(0.0);
      _finger[i].V_ds_inRef.setConstant(0.0);

      _finger[i].xp.setConstant(0.0);
      _finger[i].vp.setConstant(0.0);

      _finger[i].jacobian_finger.setConstant(0.0);
      _finger[i].JF.setConstant(0.0);
   }
   _finger[0].name = "index";
   _finger[1].name = "midle";
   _finger[2].name = "pinky";
   _finger[3].name = "thumb";

   // filter section:
   filterGain = 0.2;

   _finger[0].X_target_inRef = {0.0795334, -0.02275253, 0.0836488};
   _finger[1].X_target_inRef = {0.0789154, 0.00851324, 0.0836488};
   _finger[2].X_target_inRef = {0.0607702, 0.0478584, 0.0563102};
   _finger[3].X_target_inRef = {0.0898508, -0.0586293, 0.0595195};

   // Ds:
   _finger[0].dsGain = 12; //5; //7000 for position Mode Controller
   _finger[1].dsGain = 7;  //10;
   _finger[2].dsGain = 7;  //12;
   _finger[3].dsGain = 7;  //20 used for admittance, 50 for circular motions

   // Sending a minimun force

   EPSILON_FORCE = 0.1; //Previously 0.0001
   LIMIT_FORCE = 5.00;
   jacobPsudoInvGain = 0.5;
   nullGainController = 1.5;
   // Null Space Equib Joint Position
   // _null_joint_position[1] = 0.25;
   // _null_joint_position[5] = 0.75;
   // _null_joint_position[9] = 0.75;
   // _null_joint_position[12] = 1.254631573194332;
   // _null_joint_position[13] = 0.03;
   // _null_joint_position[14] = 0.21883507832878082;
   // _null_joint_position[15] = 1.13;

   // Null Space Equib Joint Position for one finger grasp
   _null_joint_position[1] = 0.75;
   _null_joint_position[2] = 0.2;
   _null_joint_position[3] = -0.2;

   _null_joint_position[13] = 1.58;
   _null_joint_position[13] = -0.2;
   _null_joint_position[14] = 0.55;
   _null_joint_position[15] = 0.2;

   // Null Space Equib Joint Position for all fingers
   // _null_joint_position[1] = 0.75;
   // _null_joint_position[2] = 0.2;
   // _null_joint_position[3] = 0.0;

   // _null_joint_position[13] = 1.68;
   // _null_joint_position[13] = 0.2;
   // _null_joint_position[14] = 0.55;
   // _null_joint_position[15] = 0.55;

   // _null_joint_position[0] = -0.1;
   // _null_joint_position[4] = -0.1;
   // _null_joint_position[8] = -0.1;

   // initializing the passive Ds Controller
   _dimX = 3;

   _finger[0].eigenValue = 5.0;
   _finger[1].eigenValue = 10.0;
   _finger[2].eigenValue = 7.0;
   _finger[3].eigenValue = 5.0;

   _finger[0].eigenValue_dissipative = 7.0;
   _finger[1].eigenValue_dissipative = 10.0;
   _finger[2].eigenValue_dissipative = 10.0;
   _finger[3].eigenValue_dissipative = 5.0;

   for (int i = 0; i < NB_Fingers; i++)
      _finger[i].dsController = new DSController(_dimX, _finger[i].eigenValue, _finger[i].eigenValue_dissipative);

   initializeKinematic();

   // Gustav variables
   _theta = 0;
   _target_force = 1;
   _old_vec_e = _finger[3].X_target_inRef;
   _filtered_thumb_pos = _finger[3].X_target_inRef;
   _grab = 0;
   _start = false;
   _contact_force.setZero();

   _grasp_offset = 0;
   _grasp_offset_2 = 0;
   _grasp_offset0 = 0;
   _grasp_offset1 = 0;
   _grasp_offset2 = 0;
   _grasp_offset3 = 0;
   _target_grasped = false;
   _grasp_published = false;
}

//======================================================================================================//
//========================================= Main Function ==============================================//
//======================================================================================================//

void HandManip::run()
{
   while (!_stop && ros::ok())
   {
      if (_firstOptitrackPose[0] && _firstOptitrackPose[1])
      {
         _mutex.lock();

         //-----------------------------------------//
         //--------- Check for prerequisits --------//
         //-----------------------------------------//

         // Initialize optitrack

         if (!_optitrackOK)
         {
            optitrackInitialization();
         }
         else
         {
            //-----------------------------------------//
            //------------ Body of th Code ------------//
            //-----------------------------------------//

            updateTargetGrasp();
            // updateTargetGraspAll();
            computeCommand();
            publishData();
            // publishOnTF();
            // publishTargetOnTF();
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
void HandManip::computeCommand()
{
   //~~~~~~~~~~~~~~~~~~~~~~~~~
   //0- Update position and velocity in the desired frame
   //1- Compute the Jacobians:
   //2- Compute the DS
   //3- From the DS then Compute the Desired command
   //~~~~~~~~~~~~~~~~~~~~~~~~~

   updateFingersPosVel(); // update position and velocity of fingertips all in the reference frame
   updateJacobians();     // get the jacobian of the current pose

   for (int i = 0; i < NB_Fingers; i++)
      _finger[i].JF = _finger[i].jacobian_finger.topRows(3);

   computeDS(); // Get the desired velocity

   if (_controllerMode == Position_Mode)
      computeCommandPsMode();
   else if (_controllerMode == Torque_Mode)
      computeCommandTqMode();
}

void HandManip::computeDS()
{
   // This is a simple Ds just to test the functionality of the controller
   // which later will be replaced by a  practical ds
   //-> to be corrected
   for (int i = 0; i < NB_Fingers; i++)
   {

      _finger[i].dsGainMatrix = _finger[i].dsGain * Eigen::Matrix3d::Identity(3, 3);
      _finger[i].V_ds_inRef = _finger[i].dsGainMatrix * (_finger[i].X_target_inRef - _finger[i].X_inRef);
   }
}

void HandManip::computeCommandPsMode()
{
   for (int i = 0; i < NB_Fingers; i++)
   {
      _finger[i].X_dsGenerated_inRef = _dt * _finger[i].V_ds_inRef; //+ X0_inRef; //X0_target_inRef ;
      _finger[i].joint_command_finger = jacobPsudoInvGain * _finger[i].JF.transpose() * _finger[i].X_dsGenerated_inRef;
      for (int j = 0; j < DOF_JOINTS / 4; j++)
         _desired_joint_position[j + 4 * i] = _finger[i].joint_command_finger[j] + _current_joint_position[j + 4 * i];
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

void HandManip::computeCommandTqMode()
{

   // -> update the passive Ds
   // -> update ensuring passivity
   // -> update ignoring the passivity (energy tank) : not now

   for (int i = 0; i < NB_Fingers; i++)
   {
      _finger[i].dsController->Update(_finger[i].V_inRef, _finger[i].V_ds_inRef);
      _finger[i].torque_command = _finger[i].JF.transpose() * _finger[i].dsController->control_output();
   }

   for (int i = 0; i < NB_Fingers; i++)
      for (int j = 0; j < DOF_JOINTS / 4; j++)
      {
         // _desired_joint_torque[j + 4 * i] =_finger[i].torque_command[j] - _current_joint_velocity[j + 4 * i] / 20000;
         _desired_joint_torque[j + 4 * i] = _finger[i].torque_command[j];
         // std::cout << _current_joint_velocity[j + 4 * i] / 10000 << std::endl;
      }
   // ------Jacobian null space  method to cover the redundancy
   nullSpaceControl();
   // Compensate for the gravity on each joint
   gravityCompensation();

   //----Gravity and Limits:
   // torque Command Limits + Allways send a minimum torque
   // gravity compensation tunning gain

   // hand tunning: Because of joint hystersis friction
   // gravity[1 + 6] = gravity[1 + 6] * 1.5;   // index finger
   // gravity[5 + 6] = gravity[5 + 6] * 2.5;   // middle finger
   // gravity[9 + 6] = gravity[9 + 6] * 3.5;   // pinky finger
   // gravity[14 + 6] = gravity[14 + 6] * 2.0; // thumb finger
   // Updated gains for gravity compensation.
   gravity[1 + 6] = gravity[1 + 6] * 3;     // index finger
   gravity[5 + 6] = gravity[5 + 6] * 3.2;   // middle finger
   gravity[9 + 6] = gravity[9 + 6] * 3.5;   // pinky finger
   gravity[12 + 6] = gravity[12 + 6] * 1.5; // thumb finger
   gravity[13 + 6] = gravity[13 + 6] * 1.2; // thumb finger
   gravity[14 + 6] = gravity[14 + 6] * 4;   // thumb finger

   for (int i = 0; i < DOF_JOINTS; i++)
   {
      _desired_joint_torque[i] -= gravity[i + 6];

      // if (fabs(_desired_joint_torque[i]) < EPSILON_FORCE)
      //    _desired_joint_torque[i] = EPSILON_FORCE;
      // else if (_desired_joint_torque[i] > LIMIT_FORCE)
      //    _desired_joint_torque[i] = LIMIT_FORCE;
      // else if (_desired_joint_torque[i] < -LIMIT_FORCE)
      //    _desired_joint_torque[i] = -LIMIT_FORCE;

      _desired_joint_torque[i] = deadzone(_desired_joint_torque[i], EPSILON_FORCE, LIMIT_FORCE);
   }
}

void HandManip::gravityCompensation()
{
   // state
   Cvector pos = Cvector::Zero(AIR_N_U + 1);
   Cvector vel = Cvector::Zero(AIR_N_U);

   // random base quaternion
   pos.segment(3, 3) = Cvector::Zero(3);
   pos[3] = 1;
   pos[AIR_N_U] = 0;

   //random joint angles
   for (int j = 0; j < DOF_JOINTS / 4; j++)
   {
      pos[j + 6] = (double)_current_joint_position[j];
      pos[j + 6 + 4] = (double)_current_joint_position[j + 12];
      pos[j + 6 + 8] = (double)_current_joint_position[j + 4];
      pos[j + 6 + 12] = (double)_current_joint_position[j + 8];
   }

   //definitions
   Model model;
   model.init();
   model.set_state(0, pos, vel);
   Cvector gravity0 = model.get_frcmat();
   gravity = gravity0;

   for (int j = 0; j < DOF_JOINTS / 4; j++)
   {
      gravity[j + 6] = gravity0[j + 6];
      gravity[j + 6 + 12] = gravity0[j + 6 + 4];
      gravity[j + 6 + 4] = gravity0[j + 6 + 8];
      gravity[j + 6 + 8] = gravity0[j + 6 + 12];
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
void HandManip::nullSpaceControl()
{
   for (int i = 0; i < NB_Fingers; i++)
      for (int j = 0; j < DOF_JOINTS / 4; j++)
      {
         _finger[i].temp_joint_torque[j] = (double)(-1 * nullGainController * (_current_joint_position[j + 4 * i] - _null_joint_position[j + 4 * i]));
         // _finger[i].temp_joint_torque[j] += (double)(-1 * nullGainController / 10000 * (_current_joint_velocity[j + 4 * i]));
      }

   Eigen::MatrixXd tempMat_0 = _finger[0].JF * _finger[0].JF.transpose();
   Eigen::MatrixXd tempMat_1 = _finger[1].JF * _finger[1].JF.transpose();
   Eigen::MatrixXd tempMat_2 = _finger[2].JF * _finger[2].JF.transpose();
   Eigen::MatrixXd tempMat_3 = _finger[3].JF * _finger[3].JF.transpose();

   Eigen::MatrixXd nullMat_0 = Eigen::MatrixXd::Identity(4, 4) - (_finger[0].JF.transpose() * tempMat_0.inverse() * _finger[0].JF);
   Eigen::MatrixXd nullMat_1 = Eigen::MatrixXd::Identity(4, 4) - (_finger[1].JF.transpose() * tempMat_1.inverse() * _finger[1].JF);
   Eigen::MatrixXd nullMat_2 = Eigen::MatrixXd::Identity(4, 4) - (_finger[2].JF.transpose() * tempMat_2.inverse() * _finger[2].JF);
   Eigen::MatrixXd nullMat_3 = Eigen::MatrixXd::Identity(4, 4) - (_finger[3].JF.transpose() * tempMat_3.inverse() * _finger[3].JF);

   for (int j = 0; j < DOF_JOINTS / 4; j++)
   {
      _null_joint_torque[j] = nullMat_0.row(j) * _finger[0].temp_joint_torque;
      _null_joint_torque[j + 4] = nullMat_1.row(j) * _finger[1].temp_joint_torque;
      _null_joint_torque[j + 8] = nullMat_2.row(j) * _finger[2].temp_joint_torque;
      _null_joint_torque[j + 12] = nullMat_3.row(j) * _finger[3].temp_joint_torque;
   }

   for (int j = 0; j < DOF_JOINTS; j++)
      // if (j==13)
      //    _desired_joint_torque[j] += 0;
      // else
      _desired_joint_torque[j] += _null_joint_torque[j];
}

//======================================================================================================//
//================================ Subscriber and Publisher Function ===================================//
//======================================================================================================//
void HandManip::updateHandStates(const sensor_msgs::JointState &msg)
{
   for (int i = 0; i < DOF_JOINTS; i++)
   {
      if (i == 13)
      {
         _current_joint_position[i] = msg.position[i];
         _current_joint_velocity[i] = 0.01 * msg.velocity[i] + 0.99 * _current_joint_velocity[i];
         _current_joint_torque[i] = 0.01 * msg.effort[i] + 0.99 * _current_joint_torque[i]; //Filtering since oscillations occur for higher gains
      }
      else
      {
         _current_joint_position[i] = msg.position[i];
         _current_joint_velocity[i] = 0.01 * msg.velocity[i] + 0.99 * _current_joint_velocity[i];
         if ((msg.effort[i] != msg.effort[i]) == false)
         {
            _current_joint_torque[i] = 0.01 * msg.effort[i] + 0.99 * _current_joint_torque[i]; //Filtering since oscillations occur for higher gains
         }
         // _old_effort[i]=_current_joint_torque[i];
      }
   }
}

void HandManip::publishData()
{

   for (int i = 0; i < DOF_JOINTS; i++)
   {
      _msgDesiredJointStates.position[i] = _desired_joint_position[i];
      // _msgDesiredJointStates.velocity[i] = _desired_joint_velocity[i];
      // if (i==12 | i==13)
      //    _msgDesiredJointStates.effort[i]=0;
      // else
      _msgDesiredJointStates.effort[i] = _desired_joint_torque[i];
   }
   //  _pubDesiredJointSates.publish(_msgDesiredJointStates);

   if (_controllerMode == Torque_Mode)
      _pubTorqueCmd.publish(_msgDesiredJointStates);
   else if (_controllerMode == Position_Mode)
      _pubJointCmd.publish(_msgDesiredJointStates);
}

//------------------------------------ Optitrack System ------------------------------------

void HandManip::optitrackInitialization()
{
   // ROS_INFO("[ObjectGrasping]: Optitrack Initialization First ...");
   if (_averageCount < AVERAGE_COUNT)
   {
      if (_markersTracked(0))
      {
         _markersPosition0 = (_averageCount * _markersPosition0 + _markersPosition) / (_averageCount + 1);

         _markersOrientation0 = (_averageCount * _markersOrientation0 + _markersOrientation) / (_averageCount + 1);
         _averageCount++;
         // std::cout << _averageCount << std::endl;
      }
      //  std::cerr << "[ObjectGrasping]: Optitrack Initialization count: " << _averageCount << std::endl;
      if (_averageCount == 1)
      {
         ROS_INFO("Optitrack Initialization starting ...");
      }
      else if (_averageCount == AVERAGE_COUNT)
      {
         ROS_INFO("Optitrack Initialization done !");
         // ----------------Now set the origin
         // _leftRobotOrigin = _markersPosition0.col(ROBOT_BASIS_LEFT)-_markersPosition0.col(ROBOT_BASIS_RIGHT);
         //  _baseOriginPosition = (_markersPosition0.col(0)+_markersPosition0.col(1))/2.0f;
         _baseOriginPosition = _markersPosition0.col(0);
         _baseOriginOrientation = _markersOrientation0.col(0);
      }
   }
   else
   {
      _optitrackOK = true;
   }
}

void HandManip::updateOptitrack(const geometry_msgs::PoseStamped::ConstPtr &msg, int k)
{
   if (!_firstOptitrackPose[k])
   {
      _firstOptitrackPose[k] = true;
      //  ROS_INFO("[ObjectGrasping]: Optitrack first pose ...");
   }
   // ROS_INFO("[ObjectGrasping]: Optitrack Update ...");
   _markersSequenceID(k) = msg->header.seq;
   _markersTracked(k) = checkTrackedMarker(_markersPosition.col(k)(0), msg->pose.position.x);
   // _markersTracked(k) = 1;
   // std::cout <<  _markersTracked(k) << std::endl;
   _markersPosition.col(k) << msg->pose.position.x, msg->pose.position.y, msg->pose.position.z;
   _markersOrientation.col(k) << msg->pose.orientation.w, msg->pose.orientation.x, msg->pose.orientation.y, msg->pose.orientation.z;
}

uint16_t HandManip::checkTrackedMarker(float a, float b)
{
   if (fabs(a - b) < FLT_EPSILON)
   {
      return 0;
   }
   else
   {
      return 1;
   }
}

//======================================================================================================//
//================================ Kinematic and Dynamic Function ======================================//
//======================================================================================================//
//----------- Hand ------------//
void HandManip::initializeKinematic()
{
   //  ROS_INFO("Initialize Started");
   // We will start by instantiating a
   // `RobotModelLoader`_
   // object, which will look up
   // the robot description on the ROS parameter server and construct a
   // :moveit_core:`RobotModel` for us to use.
   robot_model_loader::RobotModelLoader robot_model_loader("robot_description_2");
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

   const std::vector<std::string> &joint_names_finger_0 = _finger[0].joint_model_finger->getVariableNames();
   const std::vector<std::string> &joint_names_finger_1 = _finger[1].joint_model_finger->getVariableNames();
   const std::vector<std::string> &joint_names_finger_2 = _finger[2].joint_model_finger->getVariableNames();
   const std::vector<std::string> &joint_names_finger_3 = _finger[3].joint_model_finger->getVariableNames();

   for (int i = 0; i < NB_Fingers; i++)
   {
      kinematic_state->copyJointGroupPositions(_finger[i].joint_model_finger, _finger[i].joint_values_finger);
   }

   for (std::size_t i = 0; i < joint_names_finger_0.size(); ++i)
      ROS_INFO("Joint %s: %f", joint_names_finger_0[i].c_str(), _finger[0].joint_values_finger[i]);
}

void HandManip::updateForwardKinematic()
{
   // Now, we can compute forward kinematics for a set of random joint values. (not necessary)
   // kinematic_state->setToRandomPositions(joint_model_group);
   // Note that we would like to find the pose of the "fingerTip"
   for (int i = 0; i < NB_Fingers; i++)
   {
      for (int j = 0; j < DOF_JOINTS / 4; j++)
         _finger[i].joint_values_finger[j] = (double)_current_joint_position[j + 4 * i];

      kinematic_state->setJointGroupPositions(_finger[i].joint_model_finger, _finger[i].joint_values_finger);
   }
   const Eigen::Affine3d &state_fingertip_0 = kinematic_state->getGlobalLinkTransform("link_3_tip");
   const Eigen::Affine3d &state_fingertip_1 = kinematic_state->getGlobalLinkTransform("link_7_tip");
   const Eigen::Affine3d &state_fingertip_2 = kinematic_state->getGlobalLinkTransform("link_11_tip");
   const Eigen::Affine3d &state_fingertip_3 = kinematic_state->getGlobalLinkTransform("link_15_tip");

   _finger[0].X_inRef = state_fingertip_0.translation();
   _finger[1].X_inRef = state_fingertip_1.translation();
   _finger[2].X_inRef = state_fingertip_2.translation();
   _finger[3].X_inRef = state_fingertip_3.translation();

   //  ROS_INFO_STREAM("Rotation: \n" << state_fingertip_0.rotation() << "\n");
}

void HandManip::updateJacobians()
{
   // We can also get the Jacobian from the :moveit_core:`RobotState`.
   for (int i = 0; i < NB_Fingers; i++)
      kinematic_state->getJacobian(_finger[i].joint_model_finger,
                                   kinematic_state->getLinkModel(_finger[i].joint_model_finger->getLinkModelNames().back()),
                                   reference_point_position,
                                   _finger[i].jacobian_finger);
   // ROS_INFO_STREAM("Jacobian: \n" << jacobian_finger_0 << "\n");
   //
}

void HandManip::updateFingersPosVel()
{
   // get positions in Ref
   updateForwardKinematic();

   // get velocity in Ref
   // to filter : V_filtered_t = alpha*V_t + (1-alpha)*V_filtered_previous
   for (int i = 0; i < NB_Fingers; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         _finger[i].V_inRef[j] = filterGain * ((_finger[i].X_inRef[j] - _finger[i].xp[j]) / _dt) + (1 - filterGain) * _finger[i].vp[j];
         _finger[i].vp[j] = _finger[i].V_inRef[j];
         _finger[i].xp[j] = _finger[i].X_inRef[j];
      }
   }
}

// Test for DS for circular motions.
void HandManip::updateTargetGrasp()
{
   // _target_0 = {0.029216, -0.04275253, 0.1877781};
   _target_0 = {0.0601682, -0.04275253, 0.1877781};
   _target_1 = {0.029216, 0.00851324, 0.1877781};
   _target_2 = {0.029216, 0.0478584, 0.1877781};
   _target_3 = {0.1201682+0.03, 0.0286293, -0.0046098};
   _offset = {0,0.025,0};
   _target_dir = (_target_0 + _offset - _target_3) * 10;

   if (_grab == 1 && _grab_received == 1)
   {
      _finger[0].X_target_inRef = _target_0;
      _finger[1].X_target_inRef = _target_1;
      _finger[2].X_target_inRef = _target_2;
      _finger[3].X_target_inRef = _target_3;
      _grab_received = 0;
      _start = false;
      _grasp_published = false;
      _target_grasped = false;
      _count = 0;
      _count_2 = 0;
      _count_grasp = 0;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == false)
   {
      _count++;
      if (_count >= 100)
      {
         _start = true;
         _grasp_offset = 0;
         _grasp_offset_2 = 0;
      }
   }
   else if (_grab == 0)
   {
      _finger[0].X_target_inRef = _target_0;
      _finger[1].X_target_inRef = _target_1;
      _finger[2].X_target_inRef = _target_2;
      _finger[3].X_target_inRef = _target_3;
      ROS_INFO_STREAM_THROTTLE(1, _finger[3].X_inRef[2]);
      _start = false;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == true && _target_grasped == false)
   {
      // // METHOD 1
      // if (_current_joint_torque[15] < 0.15)
      // {
      //    if (_count >= 10)
      //    {
      //       _grasp_offset += 0.0005;
      //       _count = 0;
      //    }
      //    _finger[0].X_target_inRef = _target_0 - _target_dir * _grasp_offset;
      //    _finger[1].X_target_inRef = _target_1;
      //    _finger[2].X_target_inRef = _target_2;
      //    _finger[3].X_target_inRef = _target_3 + _target_dir * _grasp_offset;

      //    ROS_INFO_STREAM_THROTTLE(0.1, _finger[3].X_inRef[2] << " " << _finger[3].X_target_inRef[2]);
      //    ROS_INFO_STREAM_THROTTLE(0.1, _current_joint_torque[3] << " " << _current_joint_torque[15]);
      //    _count += 1;
      // }
      // // METHOD 2
      if (_current_joint_torque[3] < 0.25 || _current_joint_torque[15] < 0.25)
      {
         if (_current_joint_torque[3] < 0.25)
         {
            if (_count >= 10)
            {
               _grasp_offset += 0.001;
               _count = 0;
            }
            _finger[0].X_target_inRef = _target_0 - _target_dir * _grasp_offset;

            // ROS_INFO_STREAM_THROTTLE(0.1, _finger[3].X_inRef[2] << " " << _finger[3].X_target_inRef[2]);
            // ROS_INFO_STREAM_THROTTLE(0.1, _current_joint_torque[3] << " " << _current_joint_torque[15]);
            _count += 1;
         }
         if (_current_joint_torque[15] < 0.25)
         {
            if (_count_2 >= 10)
            {
               _grasp_offset_2 += 0.002;
               _count_2 = 0;
            }
            _finger[1].X_target_inRef = _target_1;
            _finger[2].X_target_inRef = _target_2;
            _finger[3].X_target_inRef = _target_3 + _target_dir * _grasp_offset_2;

            // ROS_INFO_STREAM_THROTTLE(0.1, _finger[3].X_inRef[2] << " " << _finger[3].X_target_inRef[2]);
            // ROS_INFO_STREAM_THROTTLE(0.1, _current_joint_torque[3] << " " << _current_joint_torque[15]);
            _count_2 += 1;
         }
            ROS_INFO_STREAM_THROTTLE(0.1, _current_joint_torque[3] << " " << _grasp_offset << " " << _current_joint_torque[15] << " " << _grasp_offset_2);
      }
      else
      {
         _target_grasped = true;
      }
   }
   else if (_grab == 1 && _grab_received == 0 && _start == true && _target_grasped == true)
   {
      if (_grasp_published == false)
      {
         if (_count_grasp <= 50)
         {
            _grasped_msg.data = 1;
            _pubGrasp.publish(_grasped_msg);
            _count_grasp += 1;
         }
         else
         {
            _grasp_published = true;
            _count_grasp = 0;
         }
      }
   }
}

void HandManip::updateTargetGraspAll()
{
   _target_0 = {0.029216, -0.04275253, 0.1877781};
   _target_1 = {0.029216, 0.00851324, 0.1877781};
   _target_2 = {0.029216, 0.0478584, 0.1877781};
   _target_3 = {0.1201682, -0.0286293, -0.0046098 + 0.05};
   _center = {0.07, -0.02, 0.12};
   // All fingers goes to the middle of the hand
   // _target_dir_0 = (_target_0 - _center) * 10;
   // _target_dir_1 = (_target_1 - _center) * 10;
   // _target_dir_2 = (_target_2 - _center) * 10;
   // _target_dir_3 = (_target_3 - _center) * 10;
   // Outside fingers go towards thumb initial position
   _target_dir_0 = (_target_0 - _target_3) * 10;
   _target_dir_1 = (_target_1 - _target_3) * 10;
   _target_dir_2 = (_target_2 - _target_3) * 10;
   _target_dir_3 = (_target_3 - _center) * 10;

   if (_grab == 1 && _grab_received == 1)
   {
      _finger[0].X_target_inRef = _target_0;
      _finger[1].X_target_inRef = _target_1;
      _finger[2].X_target_inRef = _target_2;
      _finger[3].X_target_inRef = _target_3;
      _grab_received = 0;
      _start = false;
      _grasp_published = false;
      _target_grasped = false;
      _count0 = 0;
      _count1 = 0;
      _count2 = 0;
      _count3 = 0;
      _grasp_offset0 = 0;
      _grasp_offset1 = 0;
      _grasp_offset2 = 0;
      _grasp_offset3 = 0;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == false)
   {
      // ROS_INFO_STREAM_THROTTLE(1, "first loop");
      _count++;
      if (_count >= 100)
      {
         _start = true;
         _grasp_offset0 = 0;
         _grasp_offset1 = 0;
         _grasp_offset2 = 0;
         _grasp_offset3 = 0;
      }
   }
   else if (_grab == 0)
   {
      _finger[0].X_target_inRef = _target_0;
      _finger[1].X_target_inRef = _target_1;
      _finger[2].X_target_inRef = _target_2;
      _finger[3].X_target_inRef = _target_3;
      ROS_INFO_STREAM_THROTTLE(1, _finger[3].X_inRef[2]);
      _start = false;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == true && _target_grasped == false)
   {
      // ROS_INFO_STREAM_THROTTLE(1, "second loop");

      if (_current_joint_torque[3] < 0.1 || _current_joint_torque[7] < 0.1 || _current_joint_torque[11] < 0.1 || _current_joint_torque[15] < 0.1)
      {
         if (_current_joint_torque[3] < 0.1)
         {
            if (_count0 >= 10)
            {
               _grasp_offset0 += 0.001;
               _count0 = 0;
            }
            _finger[0].X_target_inRef = _target_0 - _target_dir_0 * _grasp_offset0;

            _count0 += 1;
         }
         if (_current_joint_torque[7] < 0.1)
         {
            if (_count1 >= 10)
            {
               _grasp_offset1 += 0.001;
               _count1 = 0;
            }
            _finger[1].X_target_inRef = _target_1 - _target_dir_1 * _grasp_offset1;

            _count1 += 1;
         }
         if (_current_joint_torque[11] < 0.1)
         {
            if (_count2 >= 10)
            {
               _grasp_offset2 += 0.001;
               _count2 = 0;
            }
            _finger[2].X_target_inRef = _target_2 - _target_dir_2 * _grasp_offset2;
            _count2 += 1;
         }
         if (_current_joint_torque[15] < 0.1)
         {
            if (_count3 >= 10)
            {
               _grasp_offset3 += 0.001;
               _count3 = 0;
            }
            _finger[3].X_target_inRef = _target_3 - _target_dir_3 * _grasp_offset3;

            // ROS_INFO_STREAM_THROTTLE(0.1, _finger[3].X_inRef[2] << " " << _finger[3].X_target_inRef[2]);
            // ROS_INFO_STREAM_THROTTLE(0.1, _current_joint_torque[3] << " " << _current_joint_torque[15]);
            _count3 += 1;
         }
         ROS_INFO_STREAM_THROTTLE(0.1, _current_joint_torque[3] << " " << _current_joint_torque[7] << " " << _current_joint_torque[11] << " " << _current_joint_torque[15]);
      }
      else
      {
         _target_grasped = true;
      }
   }
   else if (_grab == 1 && _grab_received == 0 && _start == true && _target_grasped == true)
   {
      if (_grasp_published == false)
      {
         if (_count_grasp <= 50)
         {
            _grasped_msg.data = 1;
            _pubGrasp.publish(_grasped_msg);
            _count_grasp += 1;
         }
         else
         {
            _grasp_published = true;
            _count_grasp = 0;
         }
      }
   }
}

void HandManip::updateGrabState(const std_msgs::Int8 &msg)
{
   _grab = msg.data;
   _grab_received = 1;
}

float HandManip::deadzone(float input, float disturbance, float threshold)
{
   if (input > 0)
   {
      input = input - disturbance;
      input = (input < 0) ? 0 : input;
      input = (input > threshold) ? threshold : input;
   }
   else if (input < 0)
   {
      input = input + disturbance;
      input = (input > 0) ? 0 : input;
      input = (input < -threshold) ? -threshold : input;
   }

   return input;
}


void HandManip::publishOnTF()
{
   for (int i = 3; i < NB_Fingers; i++)
   {
      tf::Transform transform, transform2, transform3;
      tf::Quaternion q;
      q.setRotation(tf::Vector3(1, 0, 0), M_PI);
      transform2.setRotation(q);
      q.setRotation(tf::Vector3(0, 1, 0), -M_PI / 2);
      transform3.setRotation(q);
      transform.setOrigin(tf::Vector3(_finger[i].X_inRef[0], _finger[i].X_inRef[1], _finger[i].X_inRef[2]));
      q.setRotation(tf::Vector3(1, 0, 0), M_PI);
      transform = transform3 * transform2 * transform;
      transform.setRotation(q);
      transform.setOrigin(transform.getOrigin() + tf::Vector3(0, 0, 0.081));
      _br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "iiwa_link_ee", "finger" + std::to_string(i)));
      // _br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "hand_root", "finger" + std::to_string(i)));
   }
}

void HandManip::publishTargetOnTF()
{
   tf::Transform transform, transform2, rot;
   tf::Quaternion q;
   q.setRotation(tf::Vector3(1, 0, 0), M_PI);
   rot.setRotation(q);
   transform.setOrigin(tf::Vector3(_finger[3].X_target_inRef[0], _finger[3].X_target_inRef[1], _finger[3].X_target_inRef[2]));
   transform = rot * transform;
   transform.setRotation(tf::Quaternion(0, 0, 0, 1));
   _br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "palm_link", "thumbtarget"));
   transform2.setOrigin(tf::Vector3(_finger[3].X_inRef[0], _finger[3].X_inRef[1], _finger[3].X_inRef[2]));
   transform2 = rot * transform2;
   transform2.setRotation(tf::Quaternion(0, 0, 0, 1));
   _br.sendTransform(tf::StampedTransform(transform2, ros::Time::now(), "palm_link", "thumbpos"));
   // std::cout<< _finger[3].X_inRef[0] << std::endl;
   // _br.sendTransform(tf::StampedTransform(transform2, ros::Time::now(), "iiwa_link_ee", "thumbpos"));
}