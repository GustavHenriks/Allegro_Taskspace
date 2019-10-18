#include "HandManip.h"

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
   _gravity << 0.0f, 0.0f, -9.80665f;

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

   // To be Updated
   // attractor of each ds -> will be reoved later as the ds should be defined from out side of this node
   _finger[0].X_target_inRef = {0.0795334, -0.02275253, 0.0836488};
   _finger[1].X_target_inRef = {0.0789154, 0.00851324, 0.0836488};
   _finger[2].X_target_inRef = {0.0607702, 0.0478584, 0.0563102};
   // _finger[3].X_target_inRef = {0.0186801, -0.153905, -0.0230309};
   _finger[3].X_target_inRef = {0.0898508, -0.0586293, 0.0595195};

   // original attractor of each ds
   _finger[0].X_target_inRef_orig = _finger[0].X_target_inRef;
   _finger[1].X_target_inRef_orig = _finger[1].X_target_inRef;
   _finger[2].X_target_inRef_orig = _finger[2].X_target_inRef;
   _finger[3].X_target_inRef_orig = _finger[3].X_target_inRef;

   // Ds:
   _finger[0].dsGain = 10; //5; //7000 for position Mode Controller
   _finger[1].dsGain = 10; //10;
   _finger[2].dsGain = 10; //12;
   _finger[3].dsGain = 20; //20 used for admittance, 50 for circ

   // Sending a minimun force

   EPSILON_FORCE = 0.001;
   LIMIT_FORCE = 5.00;
   jacobPsudoInvGain = 0.5;
   nullGainController = 0.1;
   // Null Space Equib Joint Position
   _null_joint_position[1] = 0.25;
   _null_joint_position[5] = 0.75;
   _null_joint_position[9] = 0.75;
   _null_joint_position[12] = 1.254631573194332;
   _null_joint_position[13] = 0.03;
   _null_joint_position[14] = 0.21883507832878082;
   _null_joint_position[15] = 1.13;

   // _finger[i].temp_joint_torque[j] += (double)(-1 * nullGainController / 10000 * (_current_joint_velocity[j + 4 * i]));

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
   start_circle = false;
   _start = false;
   _contact_force.setZero();
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
            // ROS_INFO("[ObjectGrasping]: Optitrack Initialization ...");
            optitrackInitialization();
         }
         else
         {
            //-----------------------------------------//
            //------------ Body of th Code ------------//
            //-----------------------------------------//
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 current : " << _finger[3].X_inRef[0] << " " << _finger[3].X_inRef[1] << " " << _finger[3].X_inRef[2]);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 orig    : " << _finger[3].X_target_inRef_orig[0] << " " << _finger[3].X_target_inRef_orig[1] << " " << _finger[3].X_target_inRef_orig[2]);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 angles  : " << cos(_theta)/40 << " " << sin(_theta)/20 << " ");
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 next    : " << _next_x << " " << _next_y << " " << _next_z);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 target  : " << _finger[3].X_target_inRef[0] << " " << _finger[3].X_target_inRef[1] << " " << _finger[3].X_target_inRef[2]);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 vels  : " << _finger[3].V_ds_inRef[0] << " " << _finger[3].V_ds_inRef[1] << " " << _finger[3].V_ds_inRef[2]);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 ds  : " << _new_ds[0] << " " << _new_ds[1]);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 force  : " << _finger[3].desired_force);
            // ROS_INFO_STREAM_THROTTLE(1, "Finger 4 admittance: " << _x_error << " " << _f_error << " " << _admittance);
            // ROS_INFO_STREAM_THROTTLE(0.05, "Finger 4 X target : " << _finger[3].X_inRef[0] << _finger[3].X_inRef[1] << _finger[3].X_inRef[2] << " " << _force_term << " " << _theta_circle);
            // ROS_INFO_STREAM_THROTTLE(1, "Gain increased : " << _start);


            // updateTarget();
            updateTargetCirc();
            computeCommand();
            publishData();
            // publishPosition();
            // publishOnTF();
            // publishTargetOnTF();
            computeForce();
            publishThumb();
            // PublishFuturePath();

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
      // std::cout << _finger[i].V_ds_inRef << std::endl;
      // if (_finger[i].V_ds_inRef.norm()>0.4)
      // {
      //    _finger[i].V_ds_inRef=_finger[i].V_ds_inRef/_finger[i].V_ds_inRef.norm()*0.4;
      // }
   }
   if (start_circle)
   {
      // std::cout << "Overwriting" << std::endl;
      _force_term = 0.015 * cos((_theta_circle)/ 2);
      // std::cout << _force_term << std::endl;
      _finger[3].V_ds_inRef << 10 * (_finger[3].X_target_inRef[0] - _force_term - _finger[3].X_inRef[0]), _new_ds;
      // _finger[3].V_ds_inRef << 10 * (_finger[3].X_target_inRef[0] - _force_term + _current_joint_torque[15] * 5.1385/30 - _finger[3].X_inRef[0]), _new_ds;


      // _contact_force[0] =   (.1/ 5.1385);// * cos(_theta_circle+M_PI);
      // if(_contact_force[0] < 0)
      //     _contact_force[0] = 0;

      // _finger[3].V_ds_inRef << _finger[3].V_ds_inRef;
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

   for (int i = 0; i < NB_Fingers - 1; i++)
   {
      _finger[i].dsController->Update(_finger[i].V_inRef, _finger[i].V_ds_inRef);
      _finger[i].torque_command = _finger[i].JF.transpose() * _finger[i].dsController->control_output();
      // Eigen::Vector3d force_tmp = _finger[i].dsController->control_output();
      // _finger[i].desired_force = force_tmp.norm();
      // std::cout<<_finger[i].desired_force<<std::endl;
   }

   if (_start == true)
   {
      // _finger[3].torque_command = 0.8 * _finger[3].torque_command;
      // _finger[3].torque_command += 0.2 * _finger[3].JF.transpose() * (-16 * (_finger[3].V_inRef - _finger[3].V_ds_inRef));

      // _finger[3].torque_command = _finger[3].JF.transpose() * ((-40-5*cos(_theta_circle / 2+M_PI/4)) * (_finger[3].V_inRef - _finger[3].V_ds_inRef) + _contact_force); //-32 used before
      // std::cout<<(-40-5*cos(_theta_circle / 2+M_PI/4))<<std::endl;
      _finger[3].torque_command = _finger[3].JF.transpose() * (-50* (_finger[3].V_inRef - _finger[3].V_ds_inRef) + _contact_force); //-32 used before
   }
   else
   {
      _finger[3].torque_command = _finger[3].JF.transpose() * (-5 * (_finger[3].V_inRef - _finger[3].V_ds_inRef));
   }
   // correcting for the motor gain

   _finger[3].torque_command[0] = 0.4 * _finger[3].torque_command[0];
   _finger[3].torque_command[1] = 0.5 * _finger[3].torque_command[1];
   _finger[3].torque_command[2] = 0.75 * _finger[3].torque_command[2];
   _finger[3].torque_command[3] = 2 * _finger[3].torque_command[3];
   // for (int i = 0; i < 4; i++)
   // {
   //    if (fabs(_finger[3].torque_command[i]) < 0.01)
   //    {
   //       _finger[3].torque_command[i] = 0;
   //    }
   // }

   // _finger[3].torque_command = 0.1*_finger[3].JF.transpose() * (-20 * (_finger[3].V_inRef - _finger[3].V_ds_inRef)) + 0.9*_finger[3].torque_command;
   // Eigen::Vector3d force_tmp = _finger[3].dsController->control_output();
   // _finger[3].desired_force = force_tmp.norm();
   // std::cout<<_finger[i].desired_force<<std::endl;

   // for(int i =0; i< NB_Fingers; i++)
   //       _finger[i].dsController->set_damping_eigval(_finger[i].eigenValue,_finger[i].eigenValue_dissipative);

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
   gravity[1 + 6] = gravity[1 + 6] * 1.5;   // index finger
   gravity[5 + 6] = gravity[5 + 6] * 2.5;   // middle finger
   gravity[9 + 6] = gravity[9 + 6] * 3.5;   // pinky finger
   gravity[14 + 6] = gravity[14 + 6] * 2.0; // thumb finger

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
// -------------Object------------//
/*
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
*/

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

// Test for circular motions. Works well
void HandManip::updateTarget()
{
   if (_grab == 1 && _grab_received == 1)
   {
      _finger[3].X_target_inRef = {0.139412, -0.0466971, 0.0169195};
      _grab_received = 0;
      _start = false;
      _count = 0;
      std::cout << "Pos 2 " << _grab << std::endl;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == false)
   {
      _count++;
      if (_count >= 50)
      {
         _start = true;
      }
      std::cout << "Pos 3 " << _start << " " << _count << std::endl;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == true)
   {
      _finger[3].X_target_inRef_orig = {0.1028476, -0.0575216, 0.0490766};
      tf::Transform transform, transform2;
      tf::Quaternion q;
      // _next_x = _finger[3].X_target_inRef_orig[0] - sin(_theta / 10) * sin(_theta / 10) / 40;
      // _next_y = _finger[3].X_target_inRef_orig[1] + sin(_theta) / 30;
      // _next_z = _finger[3].X_target_inRef_orig[2] + sin(_theta) / 30;
      // _next_x = _finger[3].X_target_inRef_orig[0] + _admittance;
      _next_x = _finger[3].X_target_inRef_orig[0];
      _next_y = _finger[3].X_target_inRef_orig[1];
      _next_z = _finger[3].X_target_inRef_orig[2];

      // std::cout << _next_x <<" "<<_next_y<<" "<<_next_z<<std::endl;
      _next_vec = tf::Vector3(_next_x, _next_y, _next_z);
      _next_vec = _next_vec.rotate(tf::Vector3(0, 1, 0), -M_PI / 12);
      // transform.setOrigin(_next_vec);
      // std::cout << transform.getOrigin().z() << std::endl;
      // q.setRotation(tf::Vector3(0, 1, 0), 0);
      // transform2.setRotation(q);
      // transform2.setOrigin(_next_vec);
      // transform = transform2 * transform;
      // std::cout << _current_joint_torque[15] << " " << _current_joint_velocity[15] << " " << _current_joint_position[15] << std::endl;
      _finger[3].X_target_inRef[0] = _next_vec[0];
      _finger[3].X_target_inRef[1] = _next_vec[1];
      _finger[3].X_target_inRef[2] = _next_vec[2];

      _theta = _theta + 0.01;
      admittanceControl();
      std::cout << "Pos 4" << std::endl;
   }
   else if (_grab == 0)
   {
      _start = false;
      _finger[3].X_target_inRef = {0.0286801, -0.153905, -0.0230309};
      // _count=0;
      _grab_received = 0;
      std::cout << "Pos 1 " << _grab << std::endl;
   }
}

void HandManip::admittanceControl()
{

   _x_error = (_finger[3].X_inRef[2] - _finger[3].X_target_inRef_orig[2]);
   _f_error = _target_force - _current_joint_torque[15] * 5.1385;
   _admittance = -1 * (1.0 / 100) * (2 * _x_error + 5 * _f_error);

   //   std::cout<<"Admittance "<<_admittance<<std::endl;
   //   self.q_error = (self.joint_target-self.joints[15])
   //   # self.b_error = (self.target_force-self.biotac)
   //   self.f_error = (self.target_force*0.065-self.efforts[15]*0.3340025) #4.66 4.9853
   //   # if self.q_error>0.2:
   //   #     self.q_error=0.2
   //   # if self.q_error<-0.2:
   //   #     self.q_error=-0.2

   //   rospy.loginfo_throttle(1,str([self.q_error, self.f_error, self.efforts[15]*5.1385]))
   //   rospy.loginfo_throttle(1,'Targets '+str([self.joint_target, self.target_force]))
   //   # print(self.q_error, self.f_error, self.efforts[15]*5.1385) #4.66 4.9853

   //   self.current_time = time.time()
   //   # delta_time = self.current_time - self.last_time
   //   # delta_error = self.q_error-self.last_error

   //   # self.Derivator = delta_error/delta_time
   //   # self.D = self.Kd*self.Derivator
   //   # self.admittance = (self.q_error*0.08+self.D*0.03 +
   //   #                    self.f_error*0.08+self.b_error*0)/10
   //   # self.admittance = delta_time/0.1*(self.q_error*0.08 + self.f_error*0.08)

   //   self.admittance = 1*(1.0/333)*(1*self.q_error + 5*self.f_error) # 0.05 and 1
   //   # self.admittance = 0.8*(1.0/333)*(0.1*self.q_error + self.b_error)

   //   if 0.5+self.joint_offset2+self.admittance > self.joint_max:
   //       self.admittance = self.joint_max-self.joint_offset2-0.5
   //   elif 0.5+self.joint_offset2+self.admittance < self.joint_min:
   //       self.admittance = self.joint_min-self.joint_offset2-0.5
   //   rospy.loginfo_throttle(0.1,["Admittance ",str(self.joint_offset2),str(self.admittance),str(self.joint_max)])
   //   self.joint_offset2 = self.joint_offset2+self.admittance
   //   # print(self.joint_offset2)
   //   # print(self.joint_target)

   //   # self.last_time = self.current_time
   //   # self.last_error = self.q_error
   //   self.pub_forces_vec.data=[self.target_force,self.efforts[15]*5.1385,self.joint_target,self.joints[15]]
   //   self.pub_forces.publish(self.pub_forces_vec)
}
// Test for DS for circular motions.
void HandManip::updateTargetCirc()
{
   if (_grab == 1 && _grab_received == 1)
   {
      _finger[0].X_target_inRef = {0.15334-0.12, -0.02275253, 0.14836488};
      _finger[1].X_target_inRef = {0.1109154-0.05, 0.00851324, 0.146488};
      _finger[2].X_target_inRef = {0.1407702-0.11, 0.0478584, 0.1463102};
      _finger[3].X_target_inRef = {0.1586801, -0.03905, -0.0230309};
      _grab_received = 0;
      _start = false;
      start_circle = false;
      _count = 0;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == false)
   {
      _count++;
      if (_count >= 50)
      {
         _finger[3].X_target_inRef = {0.1038508, -0.0586293, 0.0595195};
         if (_count >= 100)
         {
            _start = true;
         }
      }
   }
   else if (_grab == 0)
   {
      _finger[0].X_target_inRef = {0.15334, -0.02275253, 0.14836488};
      _finger[1].X_target_inRef = {0.1109154, 0.00851324, 0.146488};
      _finger[2].X_target_inRef = {0.1407702, 0.0478584, 0.1463102};
      _finger[3].X_target_inRef = {0.0086801, -0.153905, -0.0230309};
      ;
      start_circle = false;
      _start = false;
   }
   else if (_grab == 1 && _grab_received == 0 && _start == true)
   { 
      // _finger[0].X_target_inRef = {0.0795334, -0.02275253, 0.0836488};
      // _finger[1].X_target_inRef = {0.0789154, 0.00851324, 0.0836488};
      // _finger[2].X_target_inRef = {0.0607702, 0.0478584, 0.0563102};
      start_circle = true;
      tf::Transform transform, transform2;
      tf::Quaternion q;
      Eigen::Vector2d x;
      // x = Eigen::Vector2d(_finger[3].X_inRef[1] - _finger[3].X_target_inRef_orig[1], _finger[3].X_inRef[2] - _finger[3].X_target_inRef_orig[2]);
      _filtered_thumb_pos = 0.99 * _filtered_thumb_pos + 0.01 * _finger[3].X_inRef;
      x = Eigen::Vector2d(_filtered_thumb_pos[1] - _finger[3].X_target_inRef_orig[1], _filtered_thumb_pos[2] - _finger[3].X_target_inRef_orig[2]);
      // x =Eigen::Vector2d(_finger[3].X_inRef[1] - _finger[3].X_target_inRef_orig[1], _finger[3].X_inRef[2] - _finger[3].X_target_inRef_orig[2]);
      // std::cout << "X" << x << std::endl;
      ds(x, 0.005);
      // _new_ds(0)=0;
      // _new_ds(1)=0;
      _next_x = _finger[3].X_target_inRef_orig[0];
      // _next_y = _finger[3].X_target_inRef_orig[1];
      // _next_z = _finger[3].X_target_inRef_orig[2];
      _next_y = _finger[3].X_target_inRef_orig[1] + _new_ds(0);
      _next_z = _finger[3].X_target_inRef_orig[2] + _new_ds(1);
      // std::cout << _next_x <<" "<<_next_y<<" "<<_next_z<<std::endl;
      // std::cout << "New_Ds " << _new_ds(0) <<" "<<_new_ds(1)<<std::endl;

      _next_vec = tf::Vector3(_next_x, _next_y, _next_z);
      _next_vec = _next_vec.rotate(tf::Vector3(0, 1, 0), 0);
      _next_vec_e = Eigen::Vector3d(_next_vec);
      // transform.setOrigin(_next_vec);
      // q.setRotation(tf::Vector3(0, 1, 0), 0);
      // transform2.setRotation(q);
      // transform2.setOrigin(_next_vec);
      // transform = transform2 * transform;
      _dif = _next_vec_e - _old_vec_e;
      // std::cout<<_dif[0]<<_dif[1]<<_dif[2]<<std::endl;
      // _dif=_dif.norm();
      // std::cout<<_dif.norm()<<std::endl;
      double cutoff = 0.1;
      if (_dif.norm() > cutoff)
      {
         _next_vec_e = _next_vec_e / _next_vec_e.norm() * cutoff;
      }
      _old_vec_e = _next_vec_e;

      // std::cout<<_dif[0]<<_dif[1]<<_dif[2]<<std::endl;
      // _finger[3].X_target_inRef[0] = _next_vec_e[0];
      // _finger[3].X_target_inRef[1] = _next_vec_e[1];
      // _finger[3].X_target_inRef[2] = _next_vec_e[2];
      // std::cout << _finger[3].X_target_inRef[0] <<" "<<_finger[3].X_target_inRef[1]<<" "<<_finger[3].X_target_inRef[2]<<std::endl;

      _theta = _theta + 0.01;
   }
}
void HandManip::ds(Eigen::Vector2d x, double r_value)
{

   double r, theta_circle_dot, r_dot, x_dot, y_dot, limit;
   Eigen::Vector2d v;
   _theta_circle = atan2(x(1), x(0));
   r = sqrt(pow(x(0), 2) + pow(x(1), 2));

   theta_circle_dot = -0.5;
   r_dot = -1 * (r - r_value);

   x_dot = r_dot * cos(_theta_circle) - r * theta_circle_dot * sin(_theta_circle);
   y_dot = r_dot * sin(_theta_circle) + r * theta_circle_dot * cos(_theta_circle);
   // cout << "_theta_circle" << _theta_circle << endl;
   // cout << "r" << r << endl;
   // cout << "r_dot" << r_dot << endl;
   // cout << "x_dot" << x_dot << endl;

   v(0) = x_dot * 100;
   v(1) = y_dot * 100;
   limit = 0.1;
   if (v.norm() > limit)
   {
      v = v / v.norm() * limit;
   }
   // _new_ds = v;
   _new_ds = 0.1 * v + 0.9 * _new_ds;
   // ROS_INFO_STREAM_THROTTLE(1, "v norm : " << v.norm());
}

void HandManip::publishPosition()
{
   // fingerPub.publish(X_target_inRef[3])
}

void HandManip::publishThumb()
{
   std::vector<double> force = {_force_term*45, _current_joint_torque[15] * 5.1385, _finger[3].torque_command[0], _finger[3].torque_command[1], _finger[3].torque_command[2], _finger[3].torque_command[3]};
   // std::cout<<force[1]<<" "<<_current_joint_torque[15] * 5.1385<<std::endl;
   // set up dimensions
   // _thumb_msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
   // _thumb_msg.layout.dim[0].size = force.size();
   // _thumb_msg.layout.dim[0].stride = 1;
   // _thumb_msg.layout.dim[0].label = "x"; // or whatever name you typically use to index force

   // copy in the data
   _thumb_msg.data.clear();
   _thumb_msg.data.insert(_thumb_msg.data.end(), force.begin(), force.end());
   _pubThumb.publish(_thumb_msg);
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

void HandManip::computeForce()
{
   for (int i = 0; i < NB_Fingers; i++)
   {
      Eigen::Vector4d tmp_torque_vec;
      for (int j = 0; j < 4; j++)
      {
         tmp_torque_vec[i] = _current_joint_torque[4 * (i - 1) + j];
      }
      // std::cout<<tmp_torque_vec<<std::endl;
      // std::cout<<_finger[i].JF.transpose()<<std::endl;
      // std::cout<<tmp_torque_vec*_finger[i].JF.transpose()<<std::endl;
   }
}

void HandManip::updateGrabState(const std_msgs::Int8 &msg)
{
   _grab = msg.data;
   _grab_received = 1;
   // std::cout << "grab " << _grab << std::endl;
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

void HandManip::PublishFuturePath()
{



    // setting the header of the path
    _msg_DesiredPath.header.stamp = ros::Time::now();
    _msg_DesiredPath.header.frame_id = "palm_link";

    Eigen::Vector3d simulated_pose;
    Eigen::Vector3d simulated_vel;
    Eigen::Vector2d simulated_ds;

    simulated_vel.resize(3);
    simulated_pose.resize(3);

    simulated_ds=Eigen::Vector2d(_filtered_thumb_pos[1] - _finger[3].X_target_inRef_orig[1], _filtered_thumb_pos[2] - _finger[3].X_target_inRef_orig[2]);
    ds_simulation(simulated_ds,0.005);

   //  simulated_pose = real_pose_;
    // simulated_pose = Vector3d(transform_.getOrigin().x(),transform_.getOrigin().y(),transform_.getOrigin().z());
    simulated_pose <<0,0,0;


    for (int frame = 0; frame < _MAX_FRAME; frame++)
    {
       
        simulated_vel << (_finger[3].X_target_inRef[0] - _force_term - _finger[3].X_inRef[0]), _new_ds_simulation;

        if(simulated_vel.norm() > 0.15){
        	simulated_vel = simulated_vel / simulated_vel.norm()  * 0.15;
        }

        simulated_pose[0] +=  simulated_vel[0] * _dt * 4;
        simulated_pose[1] +=  simulated_vel[1] * _dt * 4;
        simulated_pose[2] +=  simulated_vel[2] * _dt * 4;

        _msg_DesiredPath.poses[frame].header.stamp = ros::Time::now();
      //   _msg_DesiredPath.poses[frame].header.stamp = ros::Time(0);
      //   _msg_DesiredPath.poses[frame].header.frame_id = "iiwa_link_ee";        
      // //   msg_DesiredPath_.poses[frame].header.frame_id = "SVR";
      // //   msg_DesiredPath_.poses[frame].header.frame_id = "finger3";
      //   _msg_DesiredPath.poses[frame].pose.position.x = simulated_pose[0];
      //   _msg_DesiredPath.poses[frame].pose.position.y = simulated_pose[1];
      //   _msg_DesiredPath.poses[frame].pose.position.z = simulated_pose[2];
         std::cout<<_msg_DesiredPath<<std::endl;
      //   _pub_DesiredPath.publish(_msg_DesiredPath);


    }


}


void HandManip::ds_simulation(Eigen::Vector2d x, double r_value)
{

   double r,theta_circle, theta_circle_dot, r_dot, x_dot, y_dot, limit;
   Eigen::Vector2d v;
   theta_circle = atan2(x(1), x(0));
   r = sqrt(pow(x(0), 2) + pow(x(1), 2));

   theta_circle_dot = -0.5;
   r_dot = -1 * (r - r_value);

   x_dot = r_dot * cos(theta_circle) - r * theta_circle_dot * sin(theta_circle);
   y_dot = r_dot * sin(theta_circle) + r * theta_circle_dot * cos(theta_circle);
   // cout << "_theta_circle" << _theta_circle << endl;
   // cout << "r" << r << endl;
   // cout << "r_dot" << r_dot << endl;
   // cout << "x_dot" << x_dot << endl;

   v(0) = x_dot * 100;
   v(1) = y_dot * 100;
   limit = 0.1;
   if (v.norm() > limit)
   {
      v = v / v.norm() * limit;
   }
   _new_ds_simulation = 0.1 * v + 0.9 * _new_ds_simulation;
}