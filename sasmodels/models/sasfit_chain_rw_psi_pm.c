///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL);
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL);
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double POL);
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double POL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL)
{
// insert your code here
    RW_SAW = 1.0;
    RADAVG = 0.0;
    PEP    = 0.0;
    R_CORE = 0.0;
    if ((R_TOT-T_SHELL) > 0)
    {
        R_CORE=R_TOT-T_SHELL;
        T_SH = T_SHELL;
    }
    else
    {
        R_CORE = 0.0;
        T_SH = R_TOT;
    }
    PSI = sasfit_param_override_get_psi(PSIDEG*M_PI/180.);
    return	FFmicelle_pm(q,param);
}
double Fq( double q,  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
           double POL)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R_CORE,  double SNAGG,  double VBRUSH,  double RG,
                     double POL)
{
// insert your code here
    return V(R_CORE+T_SH+2.*sqrt(5./3.)*RG,param);
}
double Iqxy( double qx, double qy, double R_CORE, double SNAGG, double VBRUSH,
             double RG, double POL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, SNAGG, VBRUSH, RG, POL);
}
