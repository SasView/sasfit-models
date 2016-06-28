///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA);
double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA) double A,  double B,  double C,  double ETA,
                  double Q,  double ALPHA,  double BETA);
double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA) double A,  double B,  double C,  double ETA,
double Q,  double ALPHA,  double BETA) double A,  double B,  double C,
double ETA,  double Q,  double ALPHA,  double BETA);
double Iqxy( double qx, double qy, double A, double B, double C, double ETA,
             double Q, double ALPHA, double BETA);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
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
    return sasfit_integrate(0.0,M_PI/2.0,&Psi_P_kernel,param);
}
double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA)
{
    Q=q;
// insert your code here
    return sas_pow_2(ETA*sasfit_ff_parallelepiped_abc_v(q,param,1))
           *sasfit_integrate(0.0,M_PI/2.0,&Psi_kernel,param);
}
double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA) double A,  double B,  double C,  double ETA,
double Q,  double ALPHA,  double BETA)
{
// insert your code here
    return 0.0;
}
double Iq( double q, double A,  double B,  double C,  double ETA,  double Q,
           double ALPHA,  double BETA) double A,  double B,  double C,  double ETA,
double Q,  double ALPHA,  double BETA) double A,  double B,  double C,
double ETA,  double Q,  double ALPHA,  double BETA)
{
// insert your code here
    return A*B*C;
}
double Iqxy( double qx, double qy, double A, double B, double C, double ETA,
             double Q, double ALPHA, double BETA)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, B, C, ETA, Q, ALPHA, BETA);
}
