#ifndef __HAND_MANIP2_H__
#define __HAND_MANIP2_H__

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
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int8.h"
#include "sensor_msgs/JointState.h"
#include "nav_msgs/Path.h"

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

// Gustav
#include <tf/transform_broadcaster.h>
#include <math.h>

// #include "sg_filter.h"
// #include "Workspace.h"

#define DOF_JOINTS 16
#define NB_Fingers 4
#define TOTAL_NB_MARKERS 1
#define AVERAGE_COUNT 300



//-------------------------------
//------- To Do List on Code----
//--commenting variables
//--1
//--2
//-------------------------------

typedef Eigen::Matrix<realtype,Eigen::Dynamic,1> Vec;
enum AttractorType { Stabilizer = 0 , Contributor = 1, Workspace = 2 };

struct Finger
{
    std::string name;                     // finger name
    //-Position Controller
    double dsGain;                     // for Ds generation
    Eigen::Matrix3d dsGainMatrix;         // Matrix Gain of Ds
    Eigen::VectorXd joint_command_finger; // joint Command for finger
    
    // Control
    DSController * dsController;          // Passive Ds controller
    float eigenValue;                     // Passive Ds gain
    float eigenValue_dissipative;         // Dissipative gain
    Eigen::VectorXd torque_command;       // Torquw Command
    Eigen::Vector4d temp_joint_torque;    //
    double desired_force;        // desired force for the torque


    //-Position
    Eigen::Vector3d X_inRef;              // fingertip positions in reference fram at hand root
    Eigen::Vector3d X_target_inRef;       // fingertip target position in the reference frame 
    Eigen::Vector3d X_target_inRef_orig;  // original fingertip target position in the reference frame 
    Eigen::Vector3d X_dsGenerated_inRef;  //
    Eigen::Vector3d X_rel_inRef;
    // Eigen::Vector3d X_inObj;

    //-Velocity
    Eigen::Vector3d V_inRef;              // fingertip velocity in reference fram at hand root
    Eigen::Vector3d V_ds_inRef;           // velocity of the fingertip derived from the DS model
    
    //for filter
    Eigen::Vector3d xp;                   // previous position
    Eigen::Vector3d vp;                   // previous velocity

    //-Jacobian

    robot_state::JointModelGroup* joint_model_finger;
    std::vector<double> joint_values_finger;
    Eigen::MatrixXd jacobian_finger;
    Eigen::MatrixXd JF;                   // Jacobian Matrix

};

class HandManip 
{

  public:
    // ============================ General Parameters ============================

    // I might use some enum here to classify the type of the motion 
    // like: num Mode {REACHING_GRASPING = 0, REACHING_GRASPING_MANIPULATING = 1};
    enum ControllerMode {Position_Mode = 0 , Torque_Mode = 1};
  
  private:
    // ============================ Node Declaration ===============================
    // ROS Variables:
    ros::NodeHandle _n;
    ros::Rate _loopRate;
    float _dt;

    // ============================ Subscriber Declaration ==========================
    ros::Subscriber _subJointSates;                   // Joint States of Allegro Hand
    ros::Subscriber _subGrab;                         // Subscriber for grab topic for hand
    //ros::Subscriber _subJointCmd;                   // Joint Commands of Allegro Hand
    // ros::Subscriber _subOptitrack[TOTAL_NB_MARKERS];  // optitrack markers pose

    // =========================== Publisher Declaration ============================
    ros::Publisher _pubDesiredJointSates;         //  Joint States of Allegro Hand
    ros::Publisher _pubJointCmd;                  // Joint Commands of Allegro Hand for Position Mode
    ros::Publisher _pubTorqueCmd;                 // Torque Command for the Torque mode control

    // ============================ Messeges Declaration ============================

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
    bool _optitrackOK;                                  // Check if all markers position is received
    bool _stop;                                         // Check for CTRL+C
    bool _seqFlag;
    bool _seqTempAtt;
    bool _seq3Temp;
    //============================  Optitrack variables ============================
    Eigen::Matrix<float,3,TOTAL_NB_MARKERS> _markersPosition;       // Markers position in optitrack frame
    Eigen::Matrix<float,3,TOTAL_NB_MARKERS> _markersPosition0;      // Initial markers position in opittrack frame
    Eigen::Matrix<uint32_t,TOTAL_NB_MARKERS,1> _markersSequenceID;  // Markers sequence ID
    Eigen::Matrix<uint16_t,TOTAL_NB_MARKERS,1> _markersTracked;     // Markers tracked state
    Eigen::Vector3f _p1;                                            // marker position in the base frame
    
    Eigen::Matrix<float,4,TOTAL_NB_MARKERS> _markersOrientation;    // Markers orientation in optitrack frame
    Eigen::Matrix<float,4,TOTAL_NB_MARKERS> _markersOrientation0;   // Markers orientation in optitrack frame
    // Eigen::Vector3f _p2;                                         // marker position in th    
    
    Eigen::Vector3f _p1f;                                           // marker position in the base frame
    // Eigen::Vector3f _p2f;                                        // marker position in th    

    Eigen::Matrix3f base2handRotation;                              // tranform matrix from base to hand frame

    Eigen::Vector3d offsetHandOfBase;                               //
    Eigen::Vector3f _baseOriginPosition;                            //
    Eigen::Vector4f _baseOriginOrientation;                         //

    Eigen::Vector4f _qo;                                            // object orientation world frame
    Eigen::Vector4f _qb;                                            // base   orientation world frame
    Eigen::Vector4f _qb2h;                                          // base to hand orientation world frame
    Eigen::Vector4f _qo2h;                                          // object to hand orientation world frame
 
    uint32_t _averageCount = 0;                                     //
    
    Eigen::Vector3d _objectCenter;                                  //
    // ============================ Other Variables ============================
    std::mutex _mutex;

    static HandManip* me;

    ControllerMode _controllerMode;
    Eigen::Vector3f _gravity;                   // Gravity vector [m/s^2] (3x1)
    
    Eigen::Vector3d reference_point_position;
    
    double filterGain;

    // Fingers:
    std::vector<Finger> _finger;

    //-Torque Controller
    float EPSILON_FORCE;
    float LIMIT_FORCE;
    float nullGainController;

    float _null_joint_torque[DOF_JOINTS]       = {0.0};
    float _null_joint_position[DOF_JOINTS]     = {0.0};

    Cvector gravity;

    int _dimX;

    //-Jacobian
    robot_state::RobotStatePtr kinematic_state;
    robot_model::RobotModelPtr kinematic_model;
    double jacobPsudoInvGain;


    // Object Variables
    // Eigen::Vector3d X_Object_inRef;                                     // Object position
    // Eigen::Vector3d V_Object_inRef;                                     // Object velocity
    // Eigen::Vector4d Q_Object_inRef;                                     // Object orientation
    // Eigen::Vector4d W_Object_inRef;                                     // Object angular velocity
    // Eigen::Matrix3d objectRotationMatrix;
    // Eigen::Vector3d objectGraspPosition;
    // Eigen::Vector3d deltaObject;

    // Eigen::Vector3d _objectInitialX;
    // double regionMargin;
    // int SEQ;
    // uint32_t _seqCount = 0;

     // ============================ Gustav Variables ============================
    double _theta,_theta_circle;
    tf::TransformBroadcaster _br;
    double _next_x, _next_y, _next_z;
    tf::Vector3 _next_vec;
    Eigen::Vector2d _new_ds;
    Eigen::Vector3d _next_vec_e;
    Eigen::Vector3d _old_vec_e;
    Eigen::Vector3d _dif;
    int _grab, _grab_received, _count;
    double _admittance, _x_error, _f_error, _target_force;
    bool start_circle, _start;
    std_msgs::Float64MultiArray _thumb_msg;
    ros::Publisher _pubThumb; 
    Eigen::Vector3d _filtered_thumb_pos;
    Eigen::Vector3d _contact_force;
    double _force_term;
    
    nav_msgs::Path _msg_DesiredPath;
    ros::Publisher _pub_DesiredPath;
    int _MAX_FRAME = 100;
    // float _old_effort[DOF_JOINTS] = {0.0};
    Eigen::Vector2d _new_ds_simulation;


    // Grasping
    double _grasp_offset;
    bool _target_grasped, _grasp_published;
    ros::Publisher _pubGrasp;
    int _count_grasp;
    std_msgs::Int8 _grasped_msg;
    Eigen::Vector3d _target_0,_target_1,_target_2,_target_3;
    Eigen::Vector3d _target_dir;

    // For the Grasp Matrix:
  public:

    HandManip(ros::NodeHandle &n,double frequency, ControllerMode controllerMode);
    // initialize node
    bool init();
    // run node
    void run();

  private:
    //============================ Function Declaration ============================

    // Compute command to be sent to the DS-impedance controller
    void computeCommand();
    void computeCommandPsMode();
    void computeCommandTqMode();
    

    // => Dit: Log data to text file
    //void logData();

    void updateHandStates(const sensor_msgs::JointState &msg);
    void updateFingersPosVel();

    // Computing the Desired States; or Dyn
    void computeDS();
    
    // Publish data to topics
    void publishData();

    //=> Dit: Compute inital markers positon
    void optitrackInitialization();
    void updateOptitrack(const geometry_msgs::PoseStamped::ConstPtr& msg, int k);
    uint16_t checkTrackedMarker(float a, float b);
    
    void initializeKinematic();
    void updateForwardKinematic();
    void updateJacobians();
    void gravityCompensation();
    void nullSpaceControl();
    // void updateInverseKinematic();

    // New additions - Gustav
    void updateTarget();
    void updateTargetGrasp();
    void ds(Eigen::Vector2d x, double r_value);
    void updateGrabState(const std_msgs::Int8 &msg);

    float deadzone(float input, float disturbance, float threshold);


    // Object related functions
    // void getObjectPose();
    // Eigen::Vector4d getObjectOrientation();

};



#endif