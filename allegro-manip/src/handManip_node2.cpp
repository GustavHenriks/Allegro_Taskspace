#include "HandManip2.h"

// ################     Note On this Code #############################
// Zero file of the allegro Hand has to be updated and corrected
// The Torque mode Controller has no energy tank; for non-conservative Ds you may need this par
// The gravity direction needs to be adjusted
// cleaning the gravity compensation part
//
//#####################################################################

int main (int argc, char **argv)
{
    ros::init(argc,argv, "hand_manip2");
    ros::NodeHandle n;
    float frequency = 300.0f; //200.0f;
    HandManip::ControllerMode controllerMode;
    controllerMode =  HandManip::ControllerMode::Torque_Mode;
    // controllerMode =  HandManip::ControllerMode::Position_Mode;
    // std::string filename;

    // you can use some if statements for having diffrent modes

    HandManip HandManip (n,frequency,controllerMode);
 
    // if (!HandManip.init())
    // {
    //     return -1;
    // }
    // else
    // {
    //     HandManip.run();
    // }

    HandManip.init();
    HandManip.run();


    
    return 0;
}