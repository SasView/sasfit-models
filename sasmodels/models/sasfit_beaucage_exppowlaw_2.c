///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double G, double B, double R_I, double R_Ip1, double K,
           double P);
double Fq( double q,  double G, double B, double R_I, double R_Ip1, double K,
           double P);
double form_volume(  double G, double B, double R_I, double R_Ip1, double K,
                     double P);
double Iqxy( double qx, double qy, double G, double B, double R_I,
             double R_Ip1, double K, double P);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double G, double B, double R_I, double R_Ip1, double K,
           double P)
{
// insert your code here
    double x, xs, tmp;
    x = q*R_I;
    xs = q*R_Ip1;
    tmp = sas_pow_3( sas_erf(x *K /sqrt(6.)) ) / q;
    return G*exp(-x*x/3.0) + B*exp(-xs*xs/3.)*pow(tmp,P);
}
double Fq( double q,  double G, double B, double R_I, double R_Ip1, double K,
           double P)
{
// insert your code here
    return 0.0;
}
double form_volume(  double G, double B, double R_I, double R_Ip1, double K,
                     double P)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double G, double B, double R_I,
             double R_Ip1, double K, double P)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, G, B, R_I, R_Ip1, K, P);
}
