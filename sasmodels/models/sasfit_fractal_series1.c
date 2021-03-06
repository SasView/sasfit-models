///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double N,  double XMIN,  double FD1,  double XMAX,
           double P0);
double Fq( double q,  double N,  double XMIN,  double FD1,  double XMAX,
           double P0);
double form_volume(  double N,  double XMIN,  double FD1,  double XMAX,
                     double P0);
double Iqxy( double qx, double qy, double N, double XMIN, double FD1,
             double XMAX, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local N, XMIN, FD1, XMAX, P0eters/variables
double Iq( double q, double N,  double XMIN,  double FD1,  double XMAX,
           double P0)
{
// insert your code here
//	sasfit_out("q:%lg, q*xmin:%lg, q*xmax:%lg",q,q*XMIN,q*XMAX);
    return fractalFF_single(q,N,FD1,XMIN,XMAX,N, XMIN, FD1, XMAX, P0);
}
double Fq( double q,  double N,  double XMIN,  double FD1,  double XMAX,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double N,  double XMIN,  double FD1,  double XMAX,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double N, double XMIN, double FD1,
             double XMAX, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, N, XMIN, FD1, XMAX, P0);
}
