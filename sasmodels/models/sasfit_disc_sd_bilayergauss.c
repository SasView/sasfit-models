///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE);
double Fq( double q,  double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE);
double form_volume(  double T,  double SIGMA_T,  double D,  double SIGMA_D,
                     double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
                     double SIGMA_CORE,  double B_CORE);
double Iqxy( double qx, double qy, double T, double SIGMA_T, double D,
             double SIGMA_D, double DUMMY, double DUMMY, double SIGMA_OUT, double B_OUT,
             double SIGMA_CORE, double B_CORE);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE)
{
// insert your code here
    return 0.0;
}
double Fq( double q,  double T,  double SIGMA_T,  double D,  double SIGMA_D,
           double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
           double SIGMA_CORE,  double B_CORE)
{
// insert your code here
    return 0.0;
}
double form_volume(  double T,  double SIGMA_T,  double D,  double SIGMA_D,
                     double DUMMY,  double DUMMY,  double SIGMA_OUT,  double B_OUT,
                     double SIGMA_CORE,  double B_CORE)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double T, double SIGMA_T, double D,
             double SIGMA_D, double DUMMY, double DUMMY, double SIGMA_OUT, double B_OUT,
             double SIGMA_CORE, double B_CORE)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, T, SIGMA_T, D, SIGMA_D, DUMMY, DUMMY, SIGMA_OUT, B_OUT,
               SIGMA_CORE, B_CORE);
}
