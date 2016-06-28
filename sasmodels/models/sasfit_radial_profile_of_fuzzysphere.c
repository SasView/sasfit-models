///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL);
double Fq( double q,  double R,  double SIGMA,  double ETA_SPH,
           double ETA_SOL);
double form_volume(  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL);
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL)
{
// insert your code here
    if (fabs(SIGMA)==0.0)
    {
        if (fabs(r) <= fabs(R) )
        {
            return ETA_SPH;
        }
        else
        {
            return ETA_SOL;
        }
    }
    else
    {
        if (r==0.0)
        {
            return (ETA_SPH-ETA_SOL)*
                   (sas_erf(R/(sqrt(2.0)*SIGMA))
                    -exp(-(sas_pow_2(R/SIGMA)/2.0)) * sqrt(2.0/M_PI)*R/SIGMA
                   ) + ETA_SOL;
        }
        else
        {
            return (ETA_SPH-ETA_SOL)*
                   ( ( exp(-0.5*sas_pow_2((fabs(r)+fabs(R))/fabs(SIGMA)))
                       -exp(-0.5*sas_pow_2((fabs(r)-fabs(R))/fabs(SIGMA)))
                     )*SIGMA/(sqrt(2.0*M_PI)*fabs(r))
                     +  0.5*sas_erf((fabs(r)+fabs(R))/(sqrt(2.0)*fabs(SIGMA)))
                     -  0.5*sas_erf((fabs(r)-fabs(R))/(sqrt(2.0)*fabs(SIGMA)))
                   )
                   + ETA_SOL;
        }
    }
}
double Fq( double q,  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, SIGMA, ETA_SPH, ETA_SOL);
}
