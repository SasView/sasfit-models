///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double G, double B, double GS, double BS, double RG,
           double RSUB, double RS, double P, double PS);
double Fq( double q,  double G, double B, double GS, double BS, double RG,
           double RSUB, double RS, double P, double PS);
double form_volume(  double G, double B, double GS, double BS, double RG,
                     double RSUB, double RS, double P, double PS);
double Iqxy( double qx, double qy, double G, double B, double GS, double BS,
             double RG, double RSUB, double RS, double P, double PS);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double G, double B, double GS, double BS, double RG,
           double RSUB, double RS, double P, double PS)
{
// insert your code here
    double x, xs, xsub, k, ks, tmp, qsub;
    x 	= q*RG;
    xs 	= q*RS;
    k 	= 1;
    ks 	= 1.;
    xsub 	= q*RSUB;
    tmp  = sas_pow_3( sas_erf(x *k /sqrt(6.))) / q;
    qsub = sas_pow_3( sas_erf(xs*ks/sqrt(6.))) / q;
    return   G* exp(-x *x /3.0)   + B *exp(-xsub*xsub/3.)*pow(tmp,P) +
             GS*exp(-xs*xs/3.0) + BS*  pow(qsub,PS);
}
double Fq( double q,  double G, double B, double GS, double BS, double RG,
           double RSUB, double RS, double P, double PS)
{
// insert your code here
    return 0.0;
}
double form_volume(  double G, double B, double GS, double BS, double RG,
                     double RSUB, double RS, double P, double PS)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double G, double B, double GS, double BS,
             double RG, double RSUB, double RS, double P, double PS)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, G, B, GS, BS, RG, RSUB, RS, P, PS);
}
