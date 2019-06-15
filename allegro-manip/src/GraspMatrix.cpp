#include "GraspMatrix.h"
#include <iostream>

GraspMatrix::GraspMatrix(double mu)
{   _mu = mu;
    _cn = 4;

    _Xobj.setConstant(0.0);
    for (int i =0; i<_cn; i++){

        _contact.push_back(Contact());
        _contact[i].Xcont.setConstant(0.0);
        
        _contact[i].r.setConstant(0.0);
        _contact[i].n.setConstant(0.0);
        _contact[i].t.setConstant(0.0);
        _contact[i].o.setConstant(0.0);
        
        _contact[i].skew.setConstant(0.0);
        _contact[i].R.setConstant(0.0);
        _contact[i].RR.setConstant(0.0);
        _contact[i].P.setConstant(0.0);

        _contact[i].HF.setConstant(0.0);
        _contact[i].HF(0,0) = 1.0;
        _contact[i].HF(1,1) = 1.0;
        _contact[i].HF(2,2) = 1.0;

        _contact[i].SF.setConstant(0.0);
        _contact[i].SF(0,0) = 1.0;
        _contact[i].SF(1,1) = 1.0;
        _contact[i].SF(2,2) = 1.0;
        _contact[i].SF(3,3) = 1.0;
        
        _contact[i].G_hf.setConstant(0.0);
        _contact[i].G_sf.setConstant(0.0);
    }

   
    _Fc.setConstant(0.0);
    
    Eigen::Vector3d _v0;
    Eigen::Vector3d _v1;
    Eigen::Vector3d _v2;
    Eigen::Vector3d _v3;
    Eigen::Vector3d _v4;
    Eigen::Vector3d _v5;
    Eigen::Vector3d _v6;
    Eigen::Vector3d _v7;

    _v0 << 1.0, _mu * 0.2121  , _mu * 0.2121;
    _v1 << 1.0, _mu * 0.0     , _mu * 0.3;
    _v2 << 1.0, _mu * -0.2121 , _mu * 0.2121;
    _v3 << 1.0, _mu * -0.3    , _mu * 0.0;
    _v4 << 1.0, _mu * -0.2121 , _mu * -0.2121;
    _v5 << 1.0, _mu * 0.0     , _mu * -0.3;
    _v6 << 1.0, _mu * 0.2121  , _mu * -0.2121; 
    _v7 << 1.0, _mu * 0.3     , _mu * 0.0;

    Eigen::Vector3d _c0;
    Eigen::Vector3d _c1;
    Eigen::Vector3d _c2;
    Eigen::Vector3d _c3;
    Eigen::Vector3d _c4;
    Eigen::Vector3d _c5;
    Eigen::Vector3d _c6;
    Eigen::Vector3d _c7;

    _c0 = _v0.cross(_v1);
    _c1 = _v1.cross(_v2);
    _c2 = _v2.cross(_v3);
    _c3 = _v3.cross(_v4);
    _c4 = _v4.cross(_v5);
    _c5 = _v5.cross(_v6);
    _c6 = _v6.cross(_v7);
    _c7 = _v7.cross(_v0);

    _c0 = _c0.normalized();
    _c1 = _c1.normalized();
    _c2 = _c2.normalized();
    _c3 = _c3.normalized();
    _c4 = _c4.normalized();
    _c5 = _c5.normalized();
    _c6 = _c6.normalized();
    _c7 = _c7.normalized();
    
    // std::cout << " c0" << _c0 << std::endl <<std::endl;
    
    _Fc.row(0) = _c0.transpose();
    _Fc.row(1) = _c1.transpose();
    _Fc.row(2) = _c2.transpose();
    _Fc.row(3) = _c3.transpose();
    _Fc.row(4) = _c4.transpose();
    _Fc.row(5) = _c5.transpose();
    _Fc.row(6) = _c6.transpose();
    _Fc.row(7) = _c7.transpose();

    //  std::cout << " Fc" << _Fc << std::endl <<std::endl;


}



void GraspMatrix::setObjectPosition(Eigen::Vector3d xobj)
{
    _Xobj = xobj;
}

void GraspMatrix::setContatcPosition(Eigen::Vector3d x0, Eigen::Vector3d x1, Eigen::Vector3d x2,Eigen::Vector3d x3)
{
    _contact[0].Xcont = x0;
    _contact[1].Xcont = x1;
    _contact[2].Xcont = x2;
    _contact[3].Xcont = x3;
    
    _contact[0].r = _contact[0].Xcont - _Xobj;
    _contact[1].r = _contact[1].Xcont - _Xobj;
    _contact[2].r = _contact[2].Xcont - _Xobj;
    _contact[3].r = _contact[3].Xcont - _Xobj;


    // std::cout << " Skew" << _ske0 << std::endl <<std::endl;

}

void GraspMatrix::setContatcNormal(Eigen::Vector3d n0, Eigen::Vector3d n1, Eigen::Vector3d n2, Eigen::Vector3d n3)
{
    _contact[0].n = n0;
    _contact[1].n = n1;
    _contact[2].n = n2;
    _contact[3].n = n3;

    
    for (int i =0; i<_cn; i++){
        _contact[0].n = _contact[0].n.normalized();
        _contact[i].t[0] = -1 * _contact[i].n[1];
        _contact[i].t[1] =      _contact[i].n[0];
        _contact[i].t[2] =      _contact[i].n[2];
        _contact[i].t = _contact[i].t - ( _contact[i].n *_contact[i].t.transpose()) * _contact[i].n;

        if (_contact[i].t.norm() < 1e-2)
        {
            _contact[i].t[0] = -1 * _contact[i].n[2];
            _contact[i].t[1] =  _contact[i].n[1];
            _contact[i].t[2] =  _contact[i].n[0];
            _contact[i].t    = _contact[i].t - (_contact[i].n * _contact[i].t.transpose()) * _contact[i].n;
        }

        _contact[i].t = _contact[i].t.normalized();
        _contact[i].o = _contact[i].n.cross(_contact[i].t);
        _contact[i].o = _contact[i].o.normalized();

        _contact[i].R.col(0) = _contact[i].n;
        _contact[i].R.col(1) = _contact[i].t;
        _contact[i].R.col(2) = _contact[i].o;

        _contact[i].RR.block(0,0,3,3) = _contact[i].R;
        _contact[i].RR.block(3,3,3,3) = _contact[i].R;

        // Grasp Matrix 
        _contact[i].G_hf = _contact[i].P * _contact[i].RR * _contact[i].HF.transpose();
        _contact[i].G_sf = _contact[i].P * _contact[i].RR * _contact[i].SF.transpose();

    }


}



/*
void GraspMatrix::solveGrasp()
{
    for(int i = 0 ; i < 6; i++){
        for (int j =0 ; j<3; j++){
            params.G1[i+j*6] = _G0(i,j);
            params.G2[i+j*6] = _G1(i,j);
            params.G3[i+j*6] = _G2(i,j);
            params.G4[i+j*6] = _G3(i,j);
        }
    }

    int num_iters = solve();

}
*/