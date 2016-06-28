///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R,  double SIGMA_R,  double DUMMY1,  double DUMMY2,
           double DUMMY3,  double DUMMY4,  double DUMMY5,  double ETA_CORE,  double DUMMY6,
           double ETA_SOL,  double Q);
double Fq( double q,  double R,  double SIGMA_R,  double DUMMY1,  double DUMMY2,
           double DUMMY3,  double DUMMY4,  double DUMMY5,  double ETA_CORE,  double DUMMY6,
           double ETA_SOL,  double Q);
double form_volume(  double R,  double SIGMA_R,  double DUMMY1,  double DUMMY2,
                     double DUMMY3,  double DUMMY4,  double DUMMY5,  double ETA_CORE,  double DUMMY6,
                     double ETA_SOL,  double Q);
double Iqxy( double qx, double qy, double R, double SIGMA_R, double DUMMY1,
             double DUMMY2, double DUMMY3, double DUMMY4, double DUMMY5, double ETA_CORE,
             double DUMMY6, double ETA_SOL, double Q);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double homo_cyl_Ampl_core(double x, sasfit_param *param)
{
    double A,u;
    u = Q*x;
    if (u==0)
    {
        A = M_PI*x*x*(ETA_CORE-ETA_SOL)*2;
    }
    else
    {
        A = M_PI*x*x*(ETA_CORE-ETA_SOL)*2*sas_J1(u)/u;
    }
    return A;
}
double homo_cyl_I_core(double x, sasfit_param *param)
{
    return sas_pow_2(homo_cyl_Ampl_core(x,param));
}
double Ampl_homoXS_core(double x, sasfit_param *param)
{
    double Pcs, u, LNdistr;
    sasfit_param subParam;
    Pcs = homo_cyl_Ampl_core(x,param);
    sasfit_init_param( &subParam );
    subParam.p[0] = 1.0;
    subParam.p[1] = SIGMA_R;
    subParam.p[2] = 1.0;
    subParam.p[3] = R;
    LNdistr = sasfit_sd_LogNorm(x, &subParam);
    return LNdistr*Pcs;
}
double I_homoXS_core(double x, sasfit_param *param)
{
    double Pcs, u, LNdistr;
    sasfit_param subParam;
    Pcs = homo_cyl_I_core(x,param);
    sasfit_init_param( &subParam );
    subParam.p[0] = 1.0;
    subParam.p[1] = SIGMA_R;
    subParam.p[2] = 1.0;
    subParam.p[3] = R;
    LNdistr = sasfit_sd_LogNorm(x, &subParam);
    return LNdistr*Pcs;
}
double Iq( double q, double R,  double SIGMA_R,  double DUMMY1,  double DUMMY2,
           double DUMMY3,  double DUMMY4,  double DUMMY5,  double ETA_CORE,  double DUMMY6,
           double ETA_SOL,  double Q)
{
    double Pcs, Rstart, Rend;
// insert your code here
    Q = q;
    if (SIGMA_R == 0.0)
    {
        Pcs=homo_cyl_I_core(R,param);
    }
    else
    {
        find_LogNorm_int_range(2,R,SIGMA_R,&Rstart,&Rend,param);
        Pcs 	= sasfit_integrate(Rstart, Rend, &I_homoXS_core, param);
    }
    return Pcs;
}
double Fq( double q,  double R,  double SIGMA_R,  double DUMMY1,  double DUMMY2,
           double DUMMY3,  double DUMMY4,  double DUMMY5,  double ETA_CORE,  double DUMMY6,
           double ETA_SOL,  double Q)
{
    double Pcs, Rstart, Rend;
// insert your code here
    Q = q;
    if (SIGMA_R == 0.0)
    {
        Pcs=homo_cyl_Ampl_core(R,param);
    }
    else
    {
        find_LogNorm_int_range(2,R,SIGMA_R,&Rstart,&Rend,param);
        Pcs 	= sasfit_integrate(Rstart, Rend, &Ampl_homoXS_core, param);
    }
    return Pcs;
}
double form_volume(  double R,  double SIGMA_R,  double DUMMY1,  double DUMMY2,
                     double DUMMY3,  double DUMMY4,  double DUMMY5,  double ETA_CORE,  double DUMMY6,
                     double ETA_SOL,  double Q)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double SIGMA_R, double DUMMY1,
             double DUMMY2, double DUMMY3, double DUMMY4, double DUMMY5, double ETA_CORE,
             double DUMMY6, double ETA_SOL, double Q)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, SIGMA_R, DUMMY1, DUMMY2, DUMMY3, DUMMY4, DUMMY5, ETA_CORE,
               DUMMY6, ETA_SOL, Q);
}
