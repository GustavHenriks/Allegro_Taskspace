#ifndef __HAND_MANIP_H__
#define __HAND_MANIP_H__

#include <mutex>
#include <fstream>
#include <pthread.h>
#include <vector>

#include "ros/ros.h"
#include <ros/package.h>

// #include "geometry_msgs/Pose.h"
// #include "geometry_msgs/Twist.h"
// #include "geometry_msgs/Quaternion.h"
// #include "geometry_msgs/WrenchStamped.h"
// #include "geometry_msgs/Wrench.h"
// #include "geometry_msgs/Twist.h"
// #include "geometry_msgs/PointStamped.h"
// #include "nav_msgs/Path.h"

// #include "visualization_msgs/Marker.h"
// #include <dynamic_reconfigure/server.h>

// #include "force_based_ds_modulation/objectGrasping_paramsConfig.h"

#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float64.h"
#include "sensor_msgs/JointState.h"


#include "Eigen/Eigen"

// #include "Kinematic.h"
// #include "Fingers.h"

// MoveIt!
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>

// Passive Ds 
#include <passive_ds_controller.h>

#include "Model.h"



// #include "sg_filter.h"
// #include "Workspace.h"

#define DOF_JOINTS 16
#define TOTAL_NB_MARKERS 2
#define AVERAGE_COUNT 100


//-------------------------------
//------- To Do List on Code----
//--commenting variables
//--1
//--2
//-------------------------------

typedef Eigen::Matrix<realtype,Eigen::Dynamic,1> Vec;

class HandManip 
{

  public:
    // ============================ General Parameters ============================

    // I might use some enum here to classify the type of the motion 
    // like: num Mode {REACHING_GRASPING = 0, REACHING_GRASPING_MANIPULATING = 1};
    enum ControllerMode {Position_Mode = 0 , Torque_Mode = 1};
    enum AttractorType { Stabilizer = 0 , Contributor = 1, Workspace = 2 };
  
  private:
    // ============================ Node Declaration ===============================
    // ROS Variables:
    ros::NodeHandle _n;
    ros::Rate _loopRate;
    float _dt;

    // ============================ Subscriber Declaration ==========================
    ros::Subscriber _subJointSates;         //  Joint States of Allegro Hand
    //ros::Subscriber _subJointCmd;           // Joint Commands of Allegro Hand
    ros::Subscriber _subOptitrack[TOTAL_NB_MARKERS];  // optitrack markers pose


    // =========================== Publisher Declaration ============================
    ros::Publisher _pubDesiredJointSates;         //  Joint States of Allegro Hand
    ros::Publisher _pubJointCmd;                  // Joint Commands of Allegro Hand for Position Mode
    ros::Publisher _pubTorqueCmd;                 // Torque Command for the Torque mode control


    // ============================ Messeges Declaration ============================

    // geometry_msgs::Pose _msgRealPose;
    // geometry_msgs::Pose _msgDesiredPose;
    sensor_msgs::JointState _msgRealJointStates;
    sensor_msgs::JointState _msgDesiredJointStates;
    sensor_msgs::JointState _msgJointCmd;


    // ============================ Variables Declartion ============================
    


    float _current_joint_position[DOF_JOINTS] = {0.0};
    float _current_joint_velocity[DOF_JOINTS] = {0.0};
    float _current_joint_torque[DOF_JOINTS]   = {0.0};
    float _desired_joint_position[DOF_JOINTS] = {0.0};
    float _desired_joint_velocity[DOF_JOINTS] = {0.0};
    float _desired_joint_torque[DOF_JOINTS]   = {0.0};




    //============================  Booleans ============================
    
    bool _firstOptitrackPose[TOTAL_NB_MARKERS];         // Monitor first optitrack markers update
    // bool _firstDampingMatrix[NB_ROBOTS];                // Monitor first damping matrix update
    // bool _firstObjectPose;                              // Monitor first object pose update
    bool _optitrackOK;                                  // Check if all markers position is received
    // bool _wrenchBiasOK[NB_ROBOTS];                      // Check if computation of force/torque sensor bias is OK
    bool _stop;                                         // Check for CTRL+C
    // bool _objectGrasped;                                // Check if the object is grasped
    // bool _objectReachable;                              // Check if object is reachable by both robots
    // bool _goHome;                                       // check for goHome state (object not reachable+ not grasped)


    //============================  Optitrack variables ============================
    Eigen::Matrix<float,3,TOTAL_NB_MARKERS> _markersPosition;       // Markers position in optitrack frame
    Eigen::Matrix<float,3,TOTAL_NB_MARKERS> _markersPosition0;      // Initial markers position in opittrack frame
    Eigen::Matrix<uint32_t,TOTAL_NB_MARKERS,1> _markersSequenceID;  // Markers sequence ID
    Eigen::Matrix<uint16_t,TOTAL_NB_MARKERS,1> _markersTracked;     // Markers tracked state
    Eigen::Vector3f _p1;                                            // marker position in the right robot frame
    
    Eigen::Vector3f _baseRobotOrigin;
    uint32_t _averageCount = 0;
    
    // ============================ Other Variables ============================
    std::mutex _mutex;

    static HandManip* me;

    ControllerMode _controllerMode;
    Eigen::Vector3f _gravity;                   // Gravity vector [m/s^2] (3x1)
    
    Eigen::Vector3d reference_point_position;
    
    double filterGain;

    //-Position Controller
    double alphaGain0;
    double alphaGain1;
    double alphaGain2;
    double alphaGain3;

    Eigen::Matrix3d dsGainMatrix_0;
    Eigen::Matrix3d dsGainMatrix_1;
    Eigen::Matrix3d dsGainMatrix_2;
    Eigen::Matrix3d dsGainMatrix_3;

    Eigen::VectorXd joint_command_finger_0;
    Eigen::VectorXd joint_command_finger_1;
    Eigen::VectorXd joint_command_finger_2;
    Eigen::VectorXd joint_command_finger_3;

    //-Torque Controller
    float EPSILON_FORCE;
    float LIMIT_FORCE;
    float nullGainController;

    Eigen::Vector4d _temp_joint_torque_0;
    Eigen::Vector4d _temp_joint_torque_1;
    Eigen::Vector4d _temp_joint_torque_2;
    Eigen::Vector4d _temp_joint_torque_3;

    float _null_joint_torque[DOF_JOINTS]       = {0.0};
    float _null_joint_position[DOF_JOINTS]     = {0.0};

    Cvector gravity;


    DSController * dsController_0;
    DSController * dsController_1;
    DSController * dsController_2;
    DSController * dsController_3;

    int _dimX;
    float _eigenValue_0 , _eigenValue_1 ,_eigenValue_2 ,_eigenValue_3;
    float _eigenValue_dissipative_0;
    float _eigenValue_dissipative_1;
    float _eigenValue_dissipative_2;
    float _eigenValue_dissipative_3;

    Eigen::VectorXd _torque_command_0;
    Eigen::VectorXd _torque_command_1;
    Eigen::VectorXd _torque_command_2;
    Eigen::VectorXd _torque_command_3;


    //-Position
    Eigen::Vector3d X0_current_inRef; // fingertip positions in reference fram at hand root
    Eigen::Vector3d X1_current_inRef; // fingertip positions in reference fram at hand root
    Eigen::Vector3d X2_current_inRef; // fingertip positions in reference fram at hand root
    Eigen::Vector3d X3_current_inRef; // fingertip positions in reference fram at hand root

    Eigen::Vector3d X0_target_inRef; // fingertip target position in the reference frame at hand root 
    Eigen::Vector3d X1_target_inRef; // fingertip target position in the reference frame at hand root
    Eigen::Vector3d X2_target_inRef; // fingertip target position in the reference frame at hand root
    Eigen::Vector3d X3_target_inRef; // fingertip target position in the reference frame at hand root

    Eigen::Vector3d X0_dsGenerated_inRef;
    Eigen::Vector3d X1_dsGenerated_inRef;
    Eigen::Vector3d X2_dsGenerated_inRef;
    Eigen::Vector3d X3_dsGenerated_inRef;
    
    Eigen::Vector3d _x0p;
    Eigen::Vector3d _x1p;
    Eigen::Vector3d _x2p;
    Eigen::Vector3d _x3p;

    //-Velocity
    Eigen::Vector3d V0_current_inRef; // fingertip velocity in reference fram at hand root
    Eigen::Vector3d V1_current_inRef; // fingertip velocity in reference fram at hand root
    Eigen::Vector3d V2_current_inRef; // fingertip velocity in reference fram at hand root
    Eigen::Vector3d V3_current_inRef; // fingertip velocity in reference fram at hand root

    Eigen::Vector3d V0_ds_inRef;     // velocity of the fingertip derived from the DS model
    Eigen::Vector3d V1_ds_inRef;     // velocity of the fingertip derived from the DS model
    Eigen::Vector3d V2_ds_inRef;     // velocity of the fingertip derived from the DS model
    Eigen::Vector3d V3_ds_inRef;     // velocity of the fingertip derived from the DS model 

    Eigen::Vector3d _v0p;
    Eigen::Vector3d _v1p;
    Eigen::Vector3d _v2p;
    Eigen::Vector3d _v3p;

    //-Jacobian
    robot_state::RobotStatePtr kinematic_state;
    robot_model::RobotModelPtr kinematic_model;

    robot_state::JointModelGroup* _joint_model_finger_0;
    robot_state::JointModelGroup* _joint_model_finger_1;
    robot_state::JointModelGroup* _joint_model_finger_2;
    robot_state::JointModelGroup* _joint_model_finger_3;

    std::vector<double> _joint_values_finger_0;
    std::vector<double> _joint_values_finger_1;
    std::vector<double> _joint_values_finger_2;
    std::vector<double> _joint_values_finger_3;

    Eigen::MatrixXd jacobian_finger_0;
    Eigen::MatrixXd jacobian_finger_1;
    Eigen::MatrixXd jacobian_finger_2;
    Eigen::MatrixXd jacobian_finger_3;

    Eigen::MatrixXd JF_0;
    Eigen::MatrixXd JF_1;
    Eigen::MatrixXd JF_2;
    Eigen::MatrixXd JF_3;

    // Object Variables
    AttractorType attractorType_0;
    AttractorType attractorType_1;
    AttractorType attractorType_2;
    AttractorType attractorType_3;

    Eigen::Vector3d X_Object_inRef;// Object position
    Eigen::Vector3d V_Object_inRef;// Object velocity
    Eigen::Vector4d Q_Object_inRef;// Object orientation
    Eigen::Vector4d W_Object_inRef;// Object angular velocity


  public:

    HandManip(ros::NodeHandle &n,double frequency, ControllerMode controllerMode);

    // initialize node
    bool init();

    // run node
    void run();


  private:
    //============================ Function Declaration ============================

    // Callback called when CTRL is detected to stop the node		
	  //static void stopNode(int sig);
    
    // Compute command to be sent to the DS-impedance controller
    void computeCommand();
    void computeCommandPsMode();
    void computeCommandTqMode();
    

    // => Dit: Log data to text file
    //void logData();

    void updateHandStates(const sensor_msgs::JointState &msg);
    void updateRefPosVel();

    // Computing the Desired States; or Dyn
    void typeAttractors();
    void setAttractors();
    void computeDS();
    
    // Publish data to topics
    void publishData();

    //=> Dit: Compute inital markers positon
    void optitrackInitialization();
    void updateOptitrack(const geometry_msgs::PoseStamped::ConstPtr& msg, int k)
    uint16_t checkTrackedMarker(float a, float b);
    
    void initializeKinemtic();
    void updateForwardKinematic();
    void updateJacobians();
    void gravityCompensation();
    void nullSpaceControl();
    // void updateInverseKinematic();

    // Object related functions
    Eigen::Vector3d getObjectPosition();
    Eigen::Vector4d getObjectOrientation();

};



#endif