#ifndef FINGERS_H_
#define FINGERS_H_


#include <iostream>
#include <string>

#include <kdl/chain.hpp>
#include <kdl/jacobian.hpp>
#include "MathLib.h"

class Fingers{
public:
    Fingers();
    //double d_pressure;

    int finger_ind; // it was i_finger_n

    string s_link_name_urdf;

    KDL::Chain kdlchain_kinchain;
    KDL::Jacobian kld_jacobian;
    KDL::Frame    kdl_frame;


    // finger Current Position
    MathLib::Vector v_desired_joint_position;
    Eigen::Vector3d v_desired_cart_position;


private:

};

#endif