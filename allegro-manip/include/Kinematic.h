#ifndef _KINEMATIC_H_
#define _KINEMATIC_H_

//=========
// Headers to be cleaned and moved to a new header file
#define NB_DOF_TOT 16
#define NB_DOF_HAND 16
#define NB_DOF_FINGER 4

#include <ros/ros.h>

// MoveIt!
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>


#include "Fingers.h"


//=================================================================
//=================================================================
//#include <joint_limits_interface/joint_limits_rosparam.h>
class Kinematic{
public:
    Kinematic();

    
    void initKinematic(float v_curr_position[NB_DOF_TOT]);


    void updateKinematic(std::vector<Fingers *>& fingers ,float v_curr_position[NB_DOF_TOT]);

private:


};

#endif