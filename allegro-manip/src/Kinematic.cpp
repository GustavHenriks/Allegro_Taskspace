#include "Kinematic.h"


// ################     Note On this Code #############################
// PI at kdl/utility.h is commented
// The Coriolis Force Has not been considered Yet
//#####################################################################


Kinematic::Kinematic(){
}

void Kinematic::initKinematic( float v_curr_position[NB_DOF_TOT]){

    ROS_INFO("Initialize Started");
    // We will start by instantiating a
    // `RobotModelLoader`_
    // object, which will look up
    // the robot description on the ROS parameter server and construct a
    // :moveit_core:`RobotModel` for us to use.
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());

    /* Using the :moveit_core:`RobotModel`, we can construct a
      :moveit_core:`RobotState` that maintains the configuration
       of the robot. 
       We will set all joints in the state to their default values. 
       We can then get a :moveit_core:`JointModelGroup`, which represents the robot
       model for a particular group, e.g. the "finger_0" of the AllegroHand robot.
    */
    robot_state::RobotStatePtr kinematic_state(new robot_state::RobotState(kinematic_model));
    kinematic_state->setToDefaultValues();

    const robot_state::JointModelGroup* joint_model_finger_0 = kinematic_model->getJointModelGroup("finger_0");
    const robot_state::JointModelGroup* joint_model_finger_1 = kinematic_model->getJointModelGroup("finger_1");
    const robot_state::JointModelGroup* joint_model_finger_2 = kinematic_model->getJointModelGroup("finger_2");
    const robot_state::JointModelGroup* joint_model_finger_3 = kinematic_model->getJointModelGroup("finger_3");
    
    
    const std::vector<std::string>& joint_names_finger_0 = joint_model_finger_0->getVariableNames();
    const std::vector<std::string>& joint_names_finger_1 = joint_model_finger_1->getVariableNames();
    const std::vector<std::string>& joint_names_finger_2 = joint_model_finger_2->getVariableNames();
    const std::vector<std::string>& joint_names_finger_3 = joint_model_finger_3->getVariableNames();

    std::vector<double> joint_values_finger_0;
    std::vector<double> joint_values_finger_1;
    std::vector<double> joint_values_finger_2;
    std::vector<double> joint_values_finger_3;

    kinematic_state->copyJointGroupPositions(joint_model_finger_0, joint_values_finger_0);
    kinematic_state->copyJointGroupPositions(joint_model_finger_1, joint_values_finger_1);
    kinematic_state->copyJointGroupPositions(joint_model_finger_2, joint_values_finger_2);
    kinematic_state->copyJointGroupPositions(joint_model_finger_3, joint_values_finger_3);

    for (std::size_t i = 0; i < joint_names_finger_0.size(); ++i)
    {
        ROS_INFO("Joint %s: %f", joint_names_finger_0[i].c_str(), joint_values_fingeer_0[i]);
    }

    // // Joint Limits
    // // ^^^^^^^^^^^^
    // // setJointGroupPositions() does not enforce joint limits by itself, but a call to enforceBounds() will do it.
    // /* Set one joint in the Panda arm outside its joint limit */
    // joint_values[0] = 5.57;
    // kinematic_state->setJointGroupPositions(joint_model_group, joint_values);

    // /* Check whether any joint is outside its joint limits */
    // ROS_INFO_STREAM("Current state is " << (kinematic_state->satisfiesBounds() ? "valid" : "not valid"));

    // /* Enforce the joint limits for this state and check again*/
    // kinematic_state->enforceBounds();
    // ROS_INFO_STREAM("Current state is " << (kinematic_state->satisfiesBounds() ? "valid" : "not valid"));

    //========================================= Forward Kinematics ===========================================//
    // ^^^^^^^^^^^^^^^^^^
    // Now, we can compute forward kinematics for a set of random joint values. (not necessary)
    // kinematic_state->setToRandomPositions(joint_model_group);
 
    // Note that we would like to find the pose of the "fingerTip"
    const Eigen::Affine3d& state_fingertip_0 = kinematic_state->getGlobalLinkTransform("link_3_tip");
    const Eigen::Affine3d& state_fingertip_1 = kinematic_state->getGlobalLinkTransform("link_7_tip");
    const Eigen::Affine3d& state_fingertip_2 = kinematic_state->getGlobalLinkTransform("link_11_tip");
    const Eigen::Affine3d& state_fingertip_3 = kinematic_state->getGlobalLinkTransform("link_15_tip");

    /* Print end-effector pose. Remember that this is in the model frame */
    ROS_INFO_STREAM("Translation: \n" << state_fingertip_0.translation() << "\n");
    ROS_INFO_STREAM("Rotation: \n" << state_fingertip_0.rotation() << "\n");


    // ======================================== Inverse Kinematics ===========================================//
    // ^^^^^^^^^^^^^^^^^^
    // We can now solve inverse kinematics (IK) for the Allegro.
    // To solve IK, we will need the following:
    //
    //  * The desired pose of the end-effector (by default, this is the last link in the "finger" chain):
    //    state_fingertip_? that we computed in the step above. or any desired position
    //  * The number of attempts to be made at solving IK: 10
    //  * The timeout for each attempt: 0.1 s
    /*
    std::size_t attempts = 10;
    double timeout = 0.1;

    bool found_ik = kinematic_state->setFromIK(joint_model_finger_0, state_fingertip_0, attempts, timeout);
    if (found_ik)
    {
        kinematic_state->copyJointGroupPositions(joint_model_finger_0, joint_values_finger_0);
    for (std::size_t i = 0; i < joint_names_finger_0.size(); ++i)
    {
        ROS_INFO("Joint %s: %f", joint_names_finger_0[i].c_str(), joint_values_finger_0[i]);
    }
    }
    else
    {
        ROS_INFO("Did not find IK solution");
    }
    */

    // ====================================== Get the Jacobian ============================================//
    // ^^^^^^^^^^^^^^^^
    // We can also get the Jacobian from the :moveit_core:`RobotState`.
    Eigen::Vector3d reference_point_position(0.0, 0.0, 0.0);
    Eigen::MatrixXd jacobian_finger_0;
    Eigen::MatrixXd jacobian_finger_1;
    Eigen::MatrixXd jacobian_finger_2;
    Eigen::MatrixXd jacobian_finger_3;
    
    
    kinematic_state->getJacobian(joint_model_finger_0,
                                 kinematic_state->getLinkModel(joint_model_finger_0->getLinkModelNames().back()),
                                 reference_point_position, 
                                 jacobian_finger_0);
    
    kinematic_state->getJacobian(joint_model_finger_1,
                                 kinematic_state->getLinkModel(joint_model_finger_1->getLinkModelNames().back()),
                                 reference_point_position, 
                                 jacobian_finger_1);
    
    kinematic_state->getJacobian(joint_model_finger_2,
                                 kinematic_state->getLinkModel(joint_model_finger_2->getLinkModelNames().back()),
                                 reference_point_position, 
                                 jacobian_finger_2);
    
    kinematic_state->getJacobian(joint_model_finger_3,
                                 kinematic_state->getLinkModel(joint_model_finger_3->getLinkModelNames().back()),
                                 reference_point_position, 
                                 jacobian_finger_3);
    
    ROS_INFO_STREAM("Jacobian: \n" << jacobian_finger_0 << "\n");













}


//====================================================================================================================
//====================================================================================================================
//############################ UpdateJacobianAndFk(list_links, NB_DOF_TOT, v_curr_position) ##########################
void Kinematic::updateKinematic(std::vector<Fingers *>& fingers, float v_curr_position[NB_DOF_TOT] ){

    ROS_INFO("Update Started");



}

