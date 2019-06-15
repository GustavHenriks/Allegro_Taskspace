#ifndef __GRASPM__
#define __GRASPM__


/* Filename: testsolver.c. */
/* Description: Basic test harness for solver.c. */
#include "Eigen/Eigen"

struct Contact
{
    Eigen::Vector3d Xcont;
	Eigen::Vector3d r; 
	Eigen::Vector3d n;
    Eigen::Vector3d t;
    Eigen::Vector3d o;

    Eigen::Matrix<double,3,3> R;
    Eigen::Matrix<double,6,6> RR;
    Eigen::Matrix<double,3,3> skew;
    Eigen::Matrix<double,6,6> P;

    Eigen::Matrix<double,3,6> HF;
    Eigen::Matrix<double,4,6> SF;

    Eigen::Matrix<double,6,3> G_hf;
    Eigen::Matrix<double,6,4> G_sf;

};


class GraspMatrix
{
    public:
        // Vars vars;
        // Params params;
        // Workspace work;
        // Settings settings;
        Eigen::Matrix<double,6,3> G0;
        Eigen::Matrix<double,6,3> G1;
        Eigen::Matrix<double,6,3> G2;
        Eigen::Matrix<double,6,3> G3;
    private:
        double _mu;
        int _cn;

        Eigen::Vector3d _Xobj;      // Object Position in Reference Frame
        
        std::vector<Contact> _contact;

        Eigen::Matrix<double,8,3> _Fc;
        Eigen::Matrix<double,8,4> _FcSF;

    public:
        GraspMatrix(double mu);
        
        void setObjectPosition(Eigen::Vector3d xobj);
        void setContatcPosition(Eigen::Vector3d x0, Eigen::Vector3d x1, Eigen::Vector3d x2,Eigen::Vector3d x3);
        void setContatcNormal(Eigen::Vector3d n0, Eigen::Vector3d n1, Eigen::Vector3d n2,Eigen::Vector3d n3);
        // void GraspMatrix::solveGrasp();
};



#endif
