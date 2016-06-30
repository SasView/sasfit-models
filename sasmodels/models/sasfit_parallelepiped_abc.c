///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA,  double P0);
double Fq( double q,  double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA,  double P0);
double form_volume(  double A,  double B,  double C,  double ETA,  double Q,
                     double ALPHA,  double BETA,  double P0);
double Iqxy( double qx, double qy, double A, double B, double C, double ETA,
             double Q, double ALPHA, double BETA, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local A, B, C, ETA, Q, ALPHA, BETA, P0eters/variables
double sinc(double x)
{
    if (fabs(x) <= 1e-4)
    {
        return 1.0-sas_pow_2(x)/6.0
               +sas_pow_4(x)/120.0
               -sas_pow_6(x)/5040.0
               +sas_pow_8(x)/362880;
    }
    else
    {
        return sin(x)/x;
    }
}
double Psi_P_kernel(double y, sasfit_param * param)
{
}
double Psi_kernel(double x, sasfit_param * param)
{
    return sasfit_integrate(0.0,M_PI/2.0,&Psi_P_kernel,A, B, C, ETA, Q, ALPHA, BETA,
                            P0);
}
double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA,  double P0)
{
    Q=q;
// insert your code here
    return sas_pow_2(ETA*form_volume(q,A, B, C, ETA, Q, ALPHA, BETA, P0,1))
           *sasfit_integrate(0.0,M_PI/2.0,&Psi_kernel,A, B, C, ETA, Q, ALPHA, BETA, P0);
}
double Fq( double q,  double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double A,  double B,  double C,  double ETA,  double Q,
                     double ALPHA,  double BETA,  double P0)
{
// insert your code here
    return A*B*C;
}
double Iqxy( double qx, double qy, double A, double B, double C, double ETA,
             double Q, double ALPHA, double BETA, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, B, C, ETA, Q, ALPHA, BETA, P0);
}
