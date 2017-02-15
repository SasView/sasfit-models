///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL,
           double P0);
double Fq( double q,  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL,
           double P0);
double form_volume(  double R );
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R, SIGMA, ETA_SPH, ETA_SOL, P0eters/variables
double Iq( double q, double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL,
           double P0)
{
    // insert your code here
    return sas_pow_2(Fq(q,R, SIGMA, ETA_SPH, ETA_SOL, P0));
}
double Fq( double q,  double R,  double SIGMA,  double ETA_SPH,  double ETA_SOL,
           double P0)
{
    double u,v;
    u = q*fabs(R);
    v = q*fabs(SIGMA);
    // insert your code here
    if (u == 0.0)
    {
        return 4./3.*M_PI*sas_pow_3(R)
               * exp(-0.5*sas_pow_2(v))
               * (ETA_SPH-ETA_SOL);
    }
    else
    {
        return 4./3.*M_PI*sas_pow_3(R)
               * 3*(sin(u)-u*cos(u))/sas_pow_3(u)
               * exp(-0.5*sas_pow_2(v))
               * (ETA_SPH-ETA_SOL);
    }
}
double form_volume(  double R )
{
    // insert your code here
    return 4./3.*M_PI*sas_pow_3(R);
}
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, SIGMA, ETA_SPH, ETA_SOL, P0);
}
