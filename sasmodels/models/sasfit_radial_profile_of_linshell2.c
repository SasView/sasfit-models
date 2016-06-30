///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_TOT,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ETA_SOL,
           double P0);
double Fq( double q,  double R_TOT,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ETA_SOL,
           double P0);
double form_volume(  double R_TOT,  double DR,  double ETA_CORE,
                     double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ETA_SOL,
                     double P0);
double Iqxy( double qx, double qy, double R_TOT, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ETA_SOL, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R_TOT, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ETA_SOL, P0eters/variables
#define R_CORE		((R_TOT-DR>=0) ? R_TOT-DR : 0)
double Iq( double q, double R_TOT,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ETA_SOL,
           double P0)
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
double Fq( double q,  double R_TOT,  double DR,  double ETA_CORE,
           double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ETA_SOL,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R_TOT,  double DR,  double ETA_CORE,
                     double ETA_SHELL,  double X_IN_SOL,  double X_OUT_SOL,  double ETA_SOL,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R_TOT, double DR, double ETA_CORE,
             double ETA_SHELL, double X_IN_SOL, double X_OUT_SOL, double ETA_SOL, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_TOT, DR, ETA_CORE, ETA_SHELL, X_IN_SOL, X_OUT_SOL, ETA_SOL, P0);
}
