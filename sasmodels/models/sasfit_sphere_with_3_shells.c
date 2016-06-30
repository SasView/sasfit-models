///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R_CORE,  double T_SH1,  double T_SH2,  double T_SH3,
           double ETA_CORE,  double ETA_SH1,  double ETA_SH2,  double ETA_SH3,
           double ETA_SOL,  double P0);
double Fq( double q,  double R_CORE,  double T_SH1,  double T_SH2,
           double T_SH3,  double ETA_CORE,  double ETA_SH1,  double ETA_SH2,
           double ETA_SH3,  double ETA_SOL,  double P0);
double form_volume(  double R_CORE,  double T_SH1,  double T_SH2,  double T_SH3,
                     double ETA_CORE,  double ETA_SH1,  double ETA_SH2,  double ETA_SH3,
                     double ETA_SOL,  double P0);
double Iqxy( double qx, double qy, double R_CORE, double T_SH1, double T_SH2,
             double T_SH3, double ETA_CORE, double ETA_SH1, double ETA_SH2, double ETA_SH3,
             double ETA_SOL, double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local R_CORE, T_SH1, T_SH2, T_SH3, ETA_CORE, ETA_SH1, ETA_SH2, ETA_SH3, ETA_SOL, P0eters/variables
double Iq( double q, double R_CORE,  double T_SH1,  double T_SH2,  double T_SH3,
           double ETA_CORE,  double ETA_SH1,  double ETA_SH2,  double ETA_SH3,
           double ETA_SOL,  double P0)
{
    double F;
// insert your code here
    F=Fq(q,R_CORE, T_SH1, T_SH2, T_SH3, ETA_CORE, ETA_SH1, ETA_SH2, ETA_SH3,
         ETA_SOL, P0);
    return sas_pow_2(F);
}
double SF(double q,double r)
{
    double qr;
    qr=q*r;
    if (qr == 0.0)
    {
        return 4./3. * M_PI * sas_pow_3(r);
    }
    else
    {
        return 4./3. * M_PI * sas_pow_3(r) * 3.0*(sin(q*r)-qr*cos(q*r))/sas_pow_3(q*r);
    }
}
double Fq( double q,  double R_CORE,  double T_SH1,  double T_SH2,
           double T_SH3,  double ETA_CORE,  double ETA_SH1,  double ETA_SH2,
           double ETA_SH3,  double ETA_SOL,  double P0)
{
    return   (ETA_CORE-ETA_SOL)* SF(q,R_CORE)
             + (ETA_SH1-ETA_SOL) *(SF(q,R_CORE+T_SH1)            -SF(q,R_CORE))
             + (ETA_SH2-ETA_SOL) *(SF(q,R_CORE+T_SH1+T_SH2)      -SF(q,R_CORE+T_SH1))
             + (ETA_SH3-ETA_SOL) *(SF(q,R_CORE+T_SH1+T_SH2+T_SH3)-SF(q,R_CORE+T_SH1+T_SH2));
}
double form_volume(  double R_CORE,  double T_SH1,  double T_SH2,  double T_SH3,
                     double ETA_CORE,  double ETA_SH1,  double ETA_SH2,  double ETA_SH3,
                     double ETA_SOL,  double P0)
{
// insert your code here
    return 4./3. * M_PI * sas_pow_3(R_CORE+T_SH1+T_SH2+T_SH3);
}
double Iqxy( double qx, double qy, double R_CORE, double T_SH1, double T_SH2,
             double T_SH3, double ETA_CORE, double ETA_SH1, double ETA_SH2, double ETA_SH3,
             double ETA_SOL, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R_CORE, T_SH1, T_SH2, T_SH3, ETA_CORE, ETA_SH1, ETA_SH2, ETA_SH3,
               ETA_SOL, P0);
}
