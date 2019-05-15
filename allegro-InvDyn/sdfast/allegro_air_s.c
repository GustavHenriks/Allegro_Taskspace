/*
Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
#include <math.h>

/* These routines are passed to allegro_air_root. */

void allegro_air_posfunc(double vars[22],
    double param[1],
    double resid[22])
{
    int i;
    double pos[23],vel[22];

    for (i = 0; i < 22; i++) {
        vel[i] = 0.;
    }
    allegro_air_ang2st(vars,pos);
    allegro_air_state(param[0],pos,vel);
    allegro_air_umotion(param[0],pos,vel);
    allegro_air_perr(resid);
}

void allegro_air_velfunc(double vars[22],
    double param[24],
    double resid[22])
{

    allegro_air_state(param[23],param,vars);
    allegro_air_umotion(param[23],param,vars);
    allegro_air_verr(resid);
}

void allegro_air_statfunc(double vars[22],
    double param[23],
    double resid[44])
{
    double pos[23],qdotdum[23];

    allegro_air_ang2st(vars,pos);
    allegro_air_state(param[22],pos,param);
    allegro_air_umotion(param[22],pos,param);
    allegro_air_uforce(param[22],pos,param);
    allegro_air_perr(resid);
    allegro_air_deriv(qdotdum,&resid[22]);
}

void allegro_air_stdyfunc(double vars[44],
    double param[1],
    double resid[66])
{
    double pos[23],qdotdum[23];

    allegro_air_ang2st(vars,pos);
    allegro_air_state(param[0],pos,&vars[22]);
    allegro_air_umotion(param[0],pos,&vars[22]);
    allegro_air_uforce(param[0],pos,&vars[22]);
    allegro_air_perr(resid);
    allegro_air_verr(&resid[22]);
    allegro_air_deriv(qdotdum,&resid[44]);
}

/* This routine is passed to the integrator. */

void allegro_air_motfunc(double time,
    double state[45],
    double dstate[45],
    double param[1],
    int *status)
{
    double err[22];
    int i;

    allegro_air_state(time,state,&state[23]);
    allegro_air_umotion(time,state,&state[23]);
    allegro_air_uforce(time,state,&state[23]);
    allegro_air_deriv(dstate,&dstate[23]);
    *status = 1;
    allegro_air_verr(err);
    for (i = 0; i < 22; i++) {
        if (fabs(err[i]) > param[0]) {
            return;
        }
    }
    allegro_air_perr(err);
    for (i = 0; i < 22; i++) {
        if (fabs(err[i]) > param[0]) {
            return;
        }
    }
    *status = 0;
}

/* This routine performs assembly analysis. */

void allegro_air_assemble(double time,
    double state[45],
    int lock[22],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double perrs[22],param[1];
    int i;
    double jw[484],dw[3872],rw[352];
    int iw[176],rooterr;

    allegro_air_gentime(&i);
    if (i != 142810) {
        allegro_air_seterr(50,42);
    }
    param[0] = time;
    allegro_air_st2ang(state,state);
    allegro_air_root(allegro_air_posfunc,state,param,22,22,0,lock,tol,tol,maxevals,
      jw,dw,rw,iw,perrs,fcnt,&rooterr);
    allegro_air_posfunc(state,param,perrs);
    *fcnt = *fcnt+1;
    allegro_air_ang2st(state,state);
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs initial velocity analysis. */

void allegro_air_initvel(double time,
    double state[45],
    int lock[22],
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double verrs[22],param[24];
    int i;
    double jw[484],dw[3872],rw[352];
    int iw[176],rooterr;

    allegro_air_gentime(&i);
    if (i != 142810) {
        allegro_air_seterr(51,42);
    }
    for (i = 0; i < 23; i++) {
        param[i] = state[i];
    }
    param[23] = time;
    allegro_air_root(allegro_air_velfunc,&
      state[23],param,22,22,0,lock,tol,tol,maxevals,jw,dw,rw,iw,verrs,fcnt,&
      rooterr);
    allegro_air_velfunc(&state[23],param,verrs);
    *fcnt = *fcnt+1;
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs static analysis. */

void allegro_air_static(double time,
    double state[45],
    int lock[22],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[44],param[23],jw[968],dw[8712],rw[506];
    int iw[264],rooterr,i;

    allegro_air_gentime(&i);
    if (i != 142810) {
        allegro_air_seterr(52,42);
    }
    for (i = 0; i < 22; i++) {
        param[i] = state[23+i];
    }
    param[22] = time;
    allegro_air_st2ang(state,state);
    allegro_air_root(allegro_air_statfunc,state,param,44,22,22,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    allegro_air_statfunc(state,param,resid);
    *fcnt = *fcnt+1;
    allegro_air_ang2st(state,state);
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs steady motion analysis. */

void allegro_air_steady(double time,
    double state[45],
    int lock[44],
    double ctol,
    double tol,
    int maxevals,
    int *fcnt,
    int *err)
{
    double resid[66],param[1],vars[44];
    double jw[2904],dw[24200],rw[858];
    int iw[440],rooterr,i;

    allegro_air_gentime(&i);
    if (i != 142810) {
        allegro_air_seterr(53,42);
    }
    param[0] = time;
    allegro_air_st2ang(state,vars);
    for (i = 0; i < 22; i++) {
        vars[22+i] = state[23+i];
    }
    allegro_air_root(allegro_air_stdyfunc,vars,param,66,44,22,lock,
      ctol,tol,maxevals,jw,dw,rw,iw,resid,fcnt,&rooterr);
    allegro_air_stdyfunc(vars,param,resid);
    *fcnt = *fcnt+1;
    allegro_air_ang2st(vars,state);
    for (i = 0; i < 22; i++) {
        state[23+i] = vars[22+i];
    }
    if (rooterr == 0) {
        *err = 0;
    } else {
        if (*fcnt >= maxevals) {
            *err = 2;
        } else {
            *err = 1;
        }
    }
}

/* This routine performs state integration. */

void allegro_air_motion(double *time,
    double state[45],
    double dstate[45],
    double dt,
    double ctol,
    double tol,
    int *flag,
    int *err)
{
    static double step;
    double work[270],ttime,param[1];
    int vintgerr,which,ferr,i;

    allegro_air_gentime(&i);
    if (i != 142810) {
        allegro_air_seterr(54,42);
    }
    param[0] = ctol;
    ttime = *time;
    if (*flag != 0) {
        allegro_air_motfunc(ttime,state,dstate,param,&ferr);
        step = dt;
        *flag = 0;
    }
    if (step <= 0.) {
        step = dt;
    }
    allegro_air_vinteg(allegro_air_motfunc,&ttime,state,dstate,param,dt,&
      step,45,tol,work,&vintgerr,&which);
    *time = ttime;
    *err = vintgerr;
}

/* This routine performs state integration with a fixed-step integrator. */

void allegro_air_fmotion(double *time,
    double state[45],
    double dstate[45],
    double dt,
    double ctol,
    int *flag,
    double *errest,
    int *err)
{
    double work[180],ttime,param[1];
    int ferr,i;

    allegro_air_gentime(&i);
    if (i != 142810) {
        allegro_air_seterr(55,42);
    }
    param[0] = ctol;
    *err = 0;
    ttime = *time;
    if (*flag != 0) {
        allegro_air_motfunc(ttime,state,dstate,param,&ferr);
        *flag = 0;
    }
    allegro_air_finteg(allegro_air_motfunc,&ttime,state,dstate,param,dt,45,
      work,errest,&ferr);
    if (ferr != 0) {
        *err = 1;
    }
    *time = ttime;
}
