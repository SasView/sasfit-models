///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iqxy( double qx, double qy, double R_TOT, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ETA_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
#define R_CORE		((R_TOT-DR>=0) ? R_TOT-DR : 0)
double sasfit_ff_radial_profile_of_linshell2(double r, sasfit_param * param)
{
    double m,b,eta_sh_in, eta_sh_out;
// insert your code here
    eta_sh_in = (1- X_IN_SOL)*ETA_SHELL+ X_IN_SOL*ETA_SOL;
    eta_sh_out= (1-X_OUT_SOL)*ETA_SHELL+X_OUT_SOL*ETA_SOL;
    m=1e100;
    if (DR !=0)
    {
        m=(eta_sh_out-eta_sh_in)/DR;
    }
    b=-m*R_CORE+eta_sh_in;
    if (fabs(r)<=R_CORE)
    {
        return ETA_CORE;
    }
    else if ((fabs(r)>R_CORE) && (fabs(r)<R_CORE+DR))
    {
        return m*fabs(r)+b;
    }
    else
    {
        return ETA_SOL;
    }
}
double sasfit_ff_radial_profile_of_linshell2_f(double q, sasfit_param * param)
{
// insert your code here
    return 0.0;
}
double sasfit_ff_radial_profile_of_linshell2_v(double q, sasfit_param * param,
        int dist)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R_TOT, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_TOT, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ETA_SOL);
}
