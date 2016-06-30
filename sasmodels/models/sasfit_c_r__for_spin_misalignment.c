///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double K,  double HI,  double L_H,  double R,  double lR,
           double P0);
double Fq( double q,  double K,  double HI,  double L_H,  double R,  double lR,
           double P0);
double form_volume(  double K,  double HI,  double L_H,  double R,  double lR,
                     double P0);
double Iqxy( double qx, double qy, double K, double HI, double L_H, double R,
             double lR, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local K, HI, L_H, R, lR, P0eters/variables
double Cr_kernel(double q,  double K,  double HI,  double L_H,  double R,
                 double lR,  double P0)
{
    return K*sas_pow_4(R)/sas_pow_2(HI)*gsl_sf_bessel_j0(q*lR)*sas_pow_2(sph_j1(
                q*fabs(R)))/sas_pow_2(1.0+sas_pow_2(L_H*q));
}
double Iq( double q, double K,  double HI,  double L_H,  double R,  double lR,
           double P0)
{
    double lh,Cr, Cr0,C2RLr, C2RGr, C2REr, euler;
// insert your code here
    lR = r;
    lh = L_H;
    if (R==0) return 0;
//if (R>0) {
    euler = M_E;
    if (fabs(r)<=1e-5)
    {
//	   Cr = exp(-2/lh*R)*pow(R,-4)*(exp(2/lh
//*R)*(4*M_PI*pow(R,3)-9*lh*M_PI*pow(R,2)+15*pow(lh,3)*M_PI)-6*M_PI
//*pow(R,3)-21*lh*M_PI*pow(R,2)-30*pow(lh,2)*M_PI*R-15*pow(lh,3)*M_PI)/24.0;
        Cr = exp(-2*pow(lh,-1)*R)*pow(lh,-4)*pow(R,-4)*(exp(2*pow(lh,-1)*R)
                *(160*pow(lh,4)*M_PI*pow(R,3)+(lh*pow(r,4)*M_PI-
                                               20*pow(lh,3)*pow(r,2)*M_PI-360*pow(lh,5)*M_PI)*pow(R,2)+pow(lh,3)
                  *pow(r,4)*M_PI+60*pow(lh,5)*pow(r,2)*M_PI+600*pow(lh,7)*M_PI)+(-2
                          *pow(r,4)*M_PI-40*pow(lh,2)*pow(r,2)*M_PI-240*pow(lh,4)*M_PI)*pow(R,3)
                +(-3*lh*pow(r,4)*M_PI-100*pow(lh,3)*pow(r,2)*M_PI-840*pow(lh,5)
                  *M_PI)*pow(R,2)+(-2*pow(lh,2)*pow(r,4)*M_PI-120*pow(lh,4)*pow(r,2)
                                   *M_PI-1200*pow(lh,6)*M_PI)*R-pow(lh,3)*pow(r,4)*M_PI-60*pow(lh,5)
                *pow(r,2)*M_PI-600*pow(lh,7)*M_PI)/960.0;
    }
    else if (2*R > r)
    {
        Cr = exp(-2/lh*R-r/lh)*pow(r,-1)*pow(R,-4)
             *(exp(2/lh*R)*(16*exp(r/lh)*r*M_PI*
                            pow(R,3)+(exp(r/lh)*(-12*pow(r,2)*M_PI-48*pow(lh,2)
                                      *M_PI)+12*lh*r*M_PI+48*pow(lh,2)*M_PI)*pow(R,2)+exp(pow(lh,
                                              -1)*r)*(pow(r,4)*M_PI+24*pow(lh,2)*pow(r,2)*M_PI+72*pow(lh,4)*M_PI)
                            -12*pow(lh,3)*r*M_PI-72*pow(lh,4)*M_PI)+(12*lh*M_PI-12*exp(
                                        2/lh*r)*lh*M_PI)*pow(R,3)+(exp(2/lh*r)*(6
                                                *lh*r*M_PI-48*pow(lh,2)*M_PI)+6*lh*r*M_PI+48*pow(lh,2)*M_PI)*pow(
                   R,2)+(exp(2/lh*r)*(12*pow(lh,2)*r*M_PI-72*pow(lh,3)
                                      *M_PI)+12*pow(lh,2)*r*M_PI+72*pow(lh,3)*M_PI)*R+exp(2/lh*r)
               *(6*pow(lh,3)*r*M_PI-36*pow(lh,4)*M_PI)+6*pow(lh,3)*r*M_PI
               +36*pow(lh,4)*M_PI)/96.0;
    }
    else if (2*R < r)
    {
        Cr = -exp(-2/lh*R-r/lh)*pow(r,-1)*pow(R,
                                              -4)*(exp(4/lh*R)*(2*lh*M_PI*pow(R,3)+(-lh*r*M_PI-8*
                                                      pow(lh,2)*M_PI)*pow(R,2)+(2*pow(lh,2)*r*M_PI+12*pow(lh,3)*M_PI)*R
                                                      -pow(lh,3)*r*M_PI-6*pow(lh,4)*M_PI)-2*lh*M_PI*pow(R,3)+exp(
                                                              2/lh*R)*((-2*lh*r*M_PI-8*pow(lh,2)*M_PI)*pow(R,2)+2*pow(lh,
                                                                      3)*r*M_PI+12*pow(lh,4)*M_PI)+(-lh*r*M_PI-8*pow(lh,2)*M_PI)*pow(
                                                                              R,2)+(-2*pow(lh,2)*r*M_PI-12*pow(lh,3)*M_PI)*R-pow(lh,3)*r*M_PI-6
                                                      *pow(lh,4)*M_PI)/16.0;
    }
    else if (2*R == r)
    {
        Cr = exp(-2/lh*r)*pow(r,-5)*(exp(r/lh)
                                     *(lh*pow(r,3)*M_PI+4*pow(lh,2)*pow(r,2)*M_PI-4*pow(lh,3)*r*M_PI
                                       -24*pow(lh,4)*M_PI)+exp(2/lh*r)*(2*pow(lh,2)*pow(r,2)
                                               *M_PI-10*pow(lh,3)*r*M_PI+12*pow(lh,4)*M_PI)+lh*pow(r,3)*M_PI
                                     +6*pow(lh,2)*pow(r,2)*M_PI+14*pow(lh,3)*r*M_PI+12*pow(lh,4)*M_PI)
             /2.0;
    }
    else
    {
        Cr = 0;
    }
    return K*sas_pow_4(R)/sas_pow_2(HI)*Cr;
//} else {
//
//	return sasfit_integrate(0.0,GSL_POSINF,&Cr_kernel, K, HI, L_H, R, lR, P0);
//}
}
double Fq( double q,  double K,  double HI,  double L_H,  double R,  double lR,
           double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double K,  double HI,  double L_H,  double R,  double lR,
                     double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double K, double HI, double L_H, double R,
             double lR, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, K, HI, L_H, R, lR, P0);
}
