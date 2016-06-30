///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double N,  double XMIN,  double FD1,  double X12,
           double FD2,  double X23,  double FD3,  double XMAX,  double P0);
double Fq( double q,  double N,  double XMIN,  double FD1,  double X12,
           double FD2,  double X23,  double FD3,  double XMAX,  double P0);
double form_volume(  double N,  double XMIN,  double FD1,  double X12,
                     double FD2,  double X23,  double FD3,  double XMAX,  double P0);
double Iqxy( double qx, double qy, double N, double XMIN, double FD1,
             double X12, double FD2, double X23, double FD3, double XMAX, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local N, XMIN, FD1, X12, FD2, X23, FD3, XMAX, P0eters/variables
double Iq( double q, double N,  double XMIN,  double FD1,  double X12,
           double FD2,  double X23,  double FD3,  double XMAX,  double P0)
{
    double a1,a2,a3;
// insert your code here
    a1 = (FD2*FD3*N*pow(X23,FD2)*pow(XMAX,FD3)*
          (pow(X12,FD1) - pow(XMIN,FD1)))/
         (FD2*FD3*pow(X12,FD1)*pow(X23,FD2)*pow(XMAX,FD3) -
          (FD1*FD2*pow(X12,FD2)*pow(X23,FD3) +
           (-(FD1*(FD2 - FD3)*pow(X12,FD2)) +
            (-FD1 + FD2)*FD3*pow(X23,FD2))*pow(XMAX,FD3))*
          pow(XMIN,FD1));
    a2 = (FD1*FD3*N*(pow(X12,FD2) - pow(X23,FD2))*
          pow(XMAX,FD3)*pow(XMIN,FD1))/
         (-(FD2*FD3*pow(X12,FD1)*pow(X23,FD2)*pow(XMAX,FD3)) +
          (FD1*FD2*pow(X12,FD2)*pow(X23,FD3) +
           (-(FD1*(FD2 - FD3)*pow(X12,FD2)) +
            (-FD1 + FD2)*FD3*pow(X23,FD2))*pow(XMAX,FD3))*
          pow(XMIN,FD1));
    a3 = (FD1*FD2*N*pow(X12,FD2)*
          (pow(X23,FD3) - pow(XMAX,FD3))*pow(XMIN,FD1))/
         (-(FD2*FD3*pow(X12,FD1)*pow(X23,FD2)*pow(XMAX,FD3)) +
          (FD1*FD2*pow(X12,FD2)*pow(X23,FD3) +
           (-(FD1*(FD2 - FD3)*pow(X12,FD2)) +
            (-FD1 + FD2)*FD3*pow(X23,FD2))*pow(XMAX,FD3))*
          pow(XMIN,FD1));
    return fractalFF_single(q,a1,FD1,XMIN,X12,N, XMIN, FD1, X12, FD2, X23, FD3,
                            XMAX, P0)
           + fractalFF_single(q,a2,FD2,X12 ,X23,N, XMIN, FD1, X12, FD2, X23, FD3, XMAX, P0)
           + fractalFF_single(q,a3,FD3,X23,XMAX,N, XMIN, FD1, X12, FD2, X23, FD3, XMAX,
                              P0);
}
double Fq( double q,  double N,  double XMIN,  double FD1,  double X12,
           double FD2,  double X23,  double FD3,  double XMAX,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double N,  double XMIN,  double FD1,  double X12,
                     double FD2,  double X23,  double FD3,  double XMAX,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double N, double XMIN, double FD1,
             double X12, double FD2, double X23, double FD3, double XMAX, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, N, XMIN, FD1, X12, FD2, X23, FD3, XMAX, P0);
}
