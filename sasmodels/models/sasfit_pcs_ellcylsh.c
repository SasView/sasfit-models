///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double DUMMY1,  double DUMMY2,  double DUMMY3,  double ETA_CORE,
           double ETA_SHELL,  double ETA_SOLV,  double R,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB);
double Fq( double q,  double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double DUMMY1,  double DUMMY2,  double DUMMY3,  double ETA_CORE,
           double ETA_SHELL,  double ETA_SOLV,  double R,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB);
double form_volume(  double R0,  double SIGMA_R0,  double EPSILON,  double T,
                     double DUMMY1,  double DUMMY2,  double DUMMY3,  double ETA_CORE,
                     double ETA_SHELL,  double ETA_SOLV,  double R,  double Q,  double P0,
                     double LB,  double B,  double L,  double EXVOL,  double CLB);
double Iqxy( double qx, double qy, double R0, double SIGMA_R0, double EPSILON,
             double T, double DUMMY1, double DUMMY2, double DUMMY3, double ETA_CORE,
             double ETA_SHELL, double ETA_SOLV, double R, double Q, double P0, double LB,
             double B, double L, double EXVOL, double CLB);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R0, SIGMA_R0, EPSILON, T, DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLBeters/variables
double ell_r(double radius, double epsilo, double t, double theta)
{
    return sqrt(sas_pow_2((radius+t)*sin(theta))+sas_pow_2((radius*epsilo+t)*cos(
                    theta)));
}
double sasfit_ff_pcs_ellcylsh_I_core(double x, sasfit_param *param)
{
    double Ain, Aout,A,u1,u2,b1,b2;
    u1 = Q*ell_r(R,EPSILON,0,x);
    u2 = Q*ell_r(R,EPSILON,T,x);
    b1 = M_PI*R*R*EPSILON*(ETA_CORE-ETA_SHELL);
    b2 = M_PI*(R+T)*(R*EPSILON+T)*(ETA_SHELL-ETA_SOLV);
    if (u1==0)
    {
        Ain = 1.0;
    }
    else
    {
        Ain = 2.0*sas_J1(u1)/u1;
    }
    if (u2==0)
    {
        Aout = 1.0;
    }
    else
    {
        Aout = 2.0*sas_J1(u2)/u2;
    }
    A = b1*Ain+b2*Aout;
    return A*A;
}
double sasfit_ff_pcs_ellcylsh_Ampl_core(double x, sasfit_param *param)
{
    double Ain, Aout,A,u1,u2,b1,b2;
    u1 = Q*ell_r(R,EPSILON,0,x);
    u2 = Q*ell_r(R,EPSILON,T,x);
    b1 = M_PI*R*R*EPSILON*(ETA_CORE-ETA_SHELL);
    b2 = M_PI*(R+T)*(R*EPSILON+T)*(ETA_SHELL-ETA_SOLV);
    if (u1==0)
    {
        Ain = 1.0;
    }
    else
    {
        Ain = 2.0*sas_J1(u1)/u1;
    }
    if (u2==0)
    {
        Aout = 1.0;
    }
    else
    {
        Aout = 2.0*sas_J1(u2)/u2;
    }
    A = b1*Ain+b2*Aout;
    return A;
}
double sasfit_ff_pcs_ellcylsh_I_core_R0(double x, sasfit_param * param)
{
    double res, LNdistr;
    sasfit_param subParam;
    R=x;
    if (R==0 && T==0)
    {
        return 0.0;
    }
    if (EPSILON != 1)
    {
        res = 2.0/M_PI*sasfit_integrate(0.0,M_PI/2.0,&sasfit_ff_pcs_ellcylsh_I_core,R0,
                                        SIGMA_R0, EPSILON, T, DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R,
                                        Q, P0, LB, B, L, EXVOL, CLB);
    }
    else
    {
        res = sasfit_ff_pcs_ellcylsh_I_core(M_PI/2.0,R0, SIGMA_R0, EPSILON, T, DUMMY1,
                                            DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLB);
    }
    if (SIGMA_R0 == 0)
    {
        LNdistr = 1.0;
    }
    else
    {
        sasfit_init_param( &subParam );
        subParam.p[0] = 1.0;
        subParam.p[1] = SIGMA_R0;
        subParam.p[2] = 1.0;
        subParam.p[3] = R0;
        LNdistr = sasfit_sd_LogNorm(x, &subParam);
    }
    return LNdistr*res;
}
double sasfit_ff_pcs_ellcylsh_Ampl_core_R0(double x, sasfit_param * param)
{
    double res, LNdistr;
    sasfit_param subParam;
    R=x;
    if (R==0 && T==0)
    {
        return 0.0;
    }
    if (EPSILON != 1)
    {
        res = 2.0/M_PI*sasfit_integrate(0.0,M_PI/2.0,&sasfit_ff_pcs_ellcylsh_Ampl_core,
                                        R0, SIGMA_R0, EPSILON, T, DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV,
                                        R, Q, P0, LB, B, L, EXVOL, CLB);
    }
    else
    {
        res = sasfit_ff_pcs_ellcylsh_Ampl_core(M_PI/2.0,R0, SIGMA_R0, EPSILON, T,
                                               DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L,
                                               EXVOL, CLB);
    }
    if (SIGMA_R0 == 0)
    {
        LNdistr = 1.0;
    }
    else
    {
        sasfit_init_param( &subParam );
        subParam.p[0] = 1.0;
        subParam.p[1] = SIGMA_R0;
        subParam.p[2] = 1.0;
        subParam.p[3] = R0;
        LNdistr = sasfit_sd_LogNorm(x, &subParam);
    }
    return LNdistr*res;
}
double Iq( double q, double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double DUMMY1,  double DUMMY2,  double DUMMY3,  double ETA_CORE,
           double ETA_SHELL,  double ETA_SOLV,  double R,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB)
{
    double Pcs,Rstart, Rend;
// insert your code here
    Q = q;
    if (SIGMA_R0 == 0.0)
    {
        Pcs = sasfit_ff_pcs_ellcylsh_I_core_R0(R0,R0, SIGMA_R0, EPSILON, T, DUMMY1,
                                               DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLB);
    }
    else
    {
        find_LogNorm_int_range(4,R0,SIGMA_R0,&Rstart,&Rend,R0, SIGMA_R0, EPSILON, T,
                               DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L,
                               EXVOL, CLB);
        Pcs = sasfit_integrate(Rstart, Rend, &sasfit_ff_pcs_ellcylsh_I_core_R0, R0,
                               SIGMA_R0, EPSILON, T, DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R,
                               Q, P0, LB, B, L, EXVOL, CLB);
    }
    return Pcs;
}
double Fq( double q,  double R0,  double SIGMA_R0,  double EPSILON,  double T,
           double DUMMY1,  double DUMMY2,  double DUMMY3,  double ETA_CORE,
           double ETA_SHELL,  double ETA_SOLV,  double R,  double Q,  double P0,
           double LB,  double B,  double L,  double EXVOL,  double CLB)
{
    double Pcs,Rstart, Rend;
// insert your code here
    Q = q;
    if (SIGMA_R0 == 0.0)
    {
        Pcs = sasfit_ff_pcs_ellcylsh_Ampl_core_R0(R0,R0, SIGMA_R0, EPSILON, T, DUMMY1,
                DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLB);
    }
    else
    {
        find_LogNorm_int_range(4,R0,SIGMA_R0,&Rstart,&Rend,R0, SIGMA_R0, EPSILON, T,
                               DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L,
                               EXVOL, CLB);
        Pcs = sasfit_integrate(Rstart, Rend, &sasfit_ff_pcs_ellcylsh_Ampl_core_R0, R0,
                               SIGMA_R0, EPSILON, T, DUMMY1, DUMMY2, DUMMY3, ETA_CORE, ETA_SHELL, ETA_SOLV, R,
                               Q, P0, LB, B, L, EXVOL, CLB);
    }
    return Pcs;
}
double form_volume(  double R0,  double SIGMA_R0,  double EPSILON,  double T,
                     double DUMMY1,  double DUMMY2,  double DUMMY3,  double ETA_CORE,
                     double ETA_SHELL,  double ETA_SOLV,  double R,  double Q,  double P0,
                     double LB,  double B,  double L,  double EXVOL,  double CLB)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R0, double SIGMA_R0, double EPSILON,
             double T, double DUMMY1, double DUMMY2, double DUMMY3, double ETA_CORE,
             double ETA_SHELL, double ETA_SOLV, double R, double Q, double P0, double LB,
             double B, double L, double EXVOL, double CLB)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R0, SIGMA_R0, EPSILON, T, DUMMY1, DUMMY2, DUMMY3, ETA_CORE,
               ETA_SHELL, ETA_SOLV, R, Q, P0, LB, B, L, EXVOL, CLB);
}
