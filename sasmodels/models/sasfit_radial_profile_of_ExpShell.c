///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iqxy( double qx, double qy, double R_CORE, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ALPHA,
             double ETA_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double expprof(double x, sasfit_param * param)
{
    double eta_sh_in, eta_sh_out;
    eta_sh_in	= X_IN_SOL	*ETA_SOL + (1-X_IN_SOL)*ETA_SHELL;
    eta_sh_out	= X_OUT_SOL	*ETA_SOL + (1-X_OUT_SOL)*ETA_SHELL;
    if (ALPHA<0)
    {
        return eta_sh_in+(eta_sh_out-eta_sh_in)*x*exp((1-x)*ALPHA);
    }
    else
    {
        return eta_sh_out+(eta_sh_in-eta_sh_out)*(1-x)*exp(-x*ALPHA);
    }
}
double sasfit_ff_radial_profile_of_expshell(double r, sasfit_param * param)
{
    double x;
// insert your code here
    x = (fabs(r)-R_CORE)/DR;
    if (fabs(r)<R_CORE)
    {
        return ETA_CORE;
    }
    else if ((fabs(r)<(R_CORE+DR)) && fabs(r)>=R_CORE)
    {
        return expprof(x,param);
    }
    else
    {
        return ETA_SOL;
    }
}
double sasfit_ff_radial_profile_of_expshell_f(double q, sasfit_param * param)
{
// insert your code here
    return 0.0;
}
double sasfit_ff_radial_profile_of_expshell_v(double q, sasfit_param * param,
        int dist)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R_CORE, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ALPHA,
             double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ALPHA,
               ETA_SOL);
}
