///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_CORE,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
           double ETA_SOL,  double P0);
double Fq( double q,  double R_CORE,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
           double ETA_SOL,  double P0);
double form_volume(  double R_CORE,  double DR,  double ETA_CORE,
                     double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
                     double ETA_SOL,  double P0);
double Iqxy( double qx, double qy, double R_CORE, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ALPHA,
             double ETA_SOL, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R_CORE, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ALPHA, ETA_SOL, P0eters/variables
double expprof(double x,  double R_CORE,  double DR,  double ETA_CORE,
               double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
               double ETA_SOL,  double P0)
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
double Iq( double q, double R_CORE,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
           double ETA_SOL,  double P0)
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
        return expprof(x,R_CORE, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ALPHA,
                       ETA_SOL, P0);
    }
    else
    {
        return ETA_SOL;
    }
}
double Fq( double q,  double R_CORE,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
           double ETA_SOL,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R_CORE,  double DR,  double ETA_CORE,
                     double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ALPHA,
                     double ETA_SOL,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R_CORE, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ALPHA,
             double ETA_SOL, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ALPHA,
               ETA_SOL, P0);
}
