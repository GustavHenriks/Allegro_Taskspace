#include "Model.h"
using namespace std;

int main()
{
	// state
	Cvector pos = Cvector::Zero(AIR_N_U+1); 
	Cvector vel = Cvector::Zero(AIR_N_U);

	// random base quaternion
	Cvector quat = (Cvector::Random(4)).normalized(); 
	pos.segment(3,3) = quat.segment(0,3);
	pos[AIR_N_U] = quat[3];

	//random joint angles
	pos.segment(6,AIR_N_U-6) = Cvector::Random(AIR_N_U-6);

	//definitions
	Model model;
	model.init();
	model.set_state(0, pos, vel);
	Cvector gravity = model.get_frcmat();

	cout << setprecision( 3 ) << endl << fixed;
	cout << "  joint      pos        vel       torque  " << endl;
	for(int i=0;i<AIR_N_U;i++)
		cout << std::setw( 5 ) << i << ":"  <<
			setprecision( 2 ) <<std::setw( 11 ) << pos[i] * (i>=6?180/M_PI:1) <<
			setprecision( 2 ) <<std::setw( 11 ) << vel[i] <<
			setprecision( 2 ) <<std::setw( 11 ) << gravity[i] <<
			endl;
	cout << std::setw( 5 ) << AIR_N_U << ":"  <<
		setprecision( 2 ) <<std::setw( 11 ) << pos[AIR_N_U] <<
		endl;

	return 0;
}
