///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double N, double XMIN, double FD1, double X12, double FD2,
           double XMAX);
double Fq( double q,  double N, double XMIN, double FD1, double X12,
           double FD2, double XMAX);
double form_volume(  double N, double XMIN, double FD1, double X12, double FD2,
                     double XMAX);
double Iqxy( double qx, double qy, double N, double XMIN, double FD1,
             double X12, double FD2, double XMAX);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double N, double XMIN, double FD1, double X12, double FD2,
           double XMAX)
{
    double a1,a2;
    a1 = (FD2*N*pow(XMAX,FD2)*(pow(X12,FD1) - pow(XMIN,FD1)))
         /(   FD2*pow(X12,FD1)*pow(XMAX,FD2)
              - (FD1*pow(X12,FD2) + (FD2-FD1)*pow(XMAX,FD2))*pow(XMIN,FD1));
    a2 = (FD1*N*(pow(X12,FD2) - pow(XMAX,FD2))*pow(XMIN,FD1))
         /(  -FD2*pow(X12,FD1)*pow(XMAX,FD2)
             + (FD1*pow(X12,FD2) + (FD2-FD1)*pow(XMAX,FD2))*pow(XMIN,FD1));
// insert your code here
    return fractalFF_single(q,a1,FD1,XMIN,X12,param)
           + fractalFF_single(q,a2,FD2,X12 ,XMAX,param);
}
double Fq( double q,  double N, double XMIN, double FD1, double X12,
           double FD2, double XMAX)
{
// insert your code here
    return 0.0;
}
double form_volume(  double N, double XMIN, double FD1, double X12, double FD2,
                     double XMAX)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double N, double XMIN, double FD1,
             double X12, double FD2, double XMAX)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, N, XMIN, FD1, X12, FD2, XMAX);
}
