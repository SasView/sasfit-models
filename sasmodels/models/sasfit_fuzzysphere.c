///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R, double SIGMA, double ETA_SPH, double ETA_SOL);
double Fq( double q,  double R, double SIGMA, double ETA_SPH, double ETA_SOL);
double Iq( double q, double R, double SIGMA, double ETA_SPH,
           double ETA_SOL) double R, double SIGMA, double ETA_SPH, double ETA_SOL);
double Iq( double q, double R, double SIGMA, double ETA_SPH,
       double ETA_SOL) double R, double SIGMA, double ETA_SPH,
double ETA_SOL) double R, double SIGMA, double ETA_SPH, double ETA_SOL);
double form_volume(  double R, double SIGMA, double ETA_SPH, double ETA_SOL);
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double R, double SIGMA, double ETA_SPH, double ETA_SOL)
{
// insert your code here
    Fq(q,R,SIGMA,ETA_SPH,ETA_SOL);
}
double Fq( double q,  double R, double SIGMA, double ETA_SPH, double ETA_SOL)
{
    double u,v;
    u = q*fabs(R);
    v=q*fabs(SIGMA);
// insert your code here
    if (u==0) {
        double Iq( double q, double R, double SIGMA, double ETA_SPH,
                   double ETA_SOL) double R, double SIGMA, double ETA_SPH, double ETA_SOL)
        * exp(-0.5*sas_pow_2(v))
        * (ETA_SPH-ETA_SOL);
    } else {
        double Iq( double q, double R, double SIGMA, double ETA_SPH,
                   double ETA_SOL) double R, double SIGMA, double ETA_SPH,
                          double ETA_SOL) double R, double SIGMA, double ETA_SPH, double ETA_SOL)
        * 3*(sin(u)-u*cos(u))/sas_pow_3(u)
        * exp(-0.5*sas_pow_2(v))
        * (ETA_SPH-ETA_SOL);
    }
}
double form_volume(  double R, double SIGMA, double ETA_SPH, double ETA_SOL)
{
// insert your code here
    return 4./3.*M_PI*sas_pow_3(R);
}
double Iqxy( double qx, double qy, double R, double SIGMA, double ETA_SPH,
             double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, SIGMA, ETA_SPH, ETA_SOL);
}
