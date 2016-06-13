///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double prof(double x,double ir,double isigma) {
    double r,sigma;
    r = fabs(ir);
    sigma=fabs(isigma);
    if (fabs(x)<=(r-sigma)) {
        return 1;
    } else if ((r-sigma)<fabs(x) && fabs(x)<= r) {
        return (1-0.5*sas_pow_2(((fabs(x)-r)+sigma)/sigma));
    } else if (r<fabs(x) && fabs(x)<= (r+sigma)) {
        return (0.5*sas_pow_2(((r-fabs(x))+sigma)/sigma));
    } else {
        return 0;
    }
}
double Iq( double q, double W_CORE, double SIGMA_CORE, double W_SH,
           double SIGMA_SHIN, double D, double SIGMA_OUT, double ETA_CORE,
           double ETA_SHELL, double ETA_SOL)
{
// insert your code here
    return ETA_SOL
           +(ETA_SHELL-ETA_SOL) *prof(r,R_OUT,SIGMA_OUT)
           -(ETA_SHELL-ETA_SOL) *prof(r,R_SHIN,SIGMA_SHIN)
           +(ETA_CORE -ETA_SOL) *prof(r,R_CORE,SIGMA_CORE);
}
double Fq( double q,  double W_CORE, double SIGMA_CORE, double W_SH,
           double SIGMA_SHIN, double D, double SIGMA_OUT, double ETA_CORE,
           double ETA_SHELL, double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double form_volume(  double W_CORE, double SIGMA_CORE, double W_SH,
                     double SIGMA_SHIN, double D, double SIGMA_OUT, double ETA_CORE,
                     double ETA_SHELL, double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double W_CORE, double SIGMA_CORE,
             double W_SH, double SIGMA_SHIN, double D, double SIGMA_OUT, double ETA_CORE,
             double ETA_SHELL, double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, W_CORE, SIGMA_CORE, W_SH, SIGMA_SHIN, D, SIGMA_OUT, ETA_CORE,
               ETA_SHELL, ETA_SOL);
}
