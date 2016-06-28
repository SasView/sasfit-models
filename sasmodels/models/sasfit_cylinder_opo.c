///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double A,  double B,  double C);
double Fq( double q,  double A,  double B,  double C);
double form_volume(  double A,  double B,  double C);
double Iqxy( double qx, double qy, double A, double B, double C);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
opo_data opod;
double Iq( double q, double A,  double B,  double C)
{
    double psi;
// insert your code here
    opod.a = A;
    opod.b = B;
    opod.c = C;
    opod.Rotation.convention = yaw_pitch_roll;
    opo_setEulerAngles(&opod,ALPHA,BETA,GAMMA);
    opo_init(&opod);
    opod.Qmod = q;
    psi=sasfit_param_override_get_psi(PSI_DEG*M_PI/180.);
    opod.Q[0] = q*cos(psi);
    opod.Q[1] = q*sin(psi);
    opod.Q[2] = 0;
    opo_setQhat(&opod);
    return sas_pow_2((ETA_P-ETA_M) *opo_Fc(&opod));
}
double Fq( double q,  double A,  double B,  double C)
{
    double psi;
// insert your code here
    opod.a = A;
    opod.b = B;
    opod.c = C;
    opo_setConvention(&opod,yaw_pitch_roll);
//   opod.Rotation.convention =Z1_X2_Y3;
    opo_setEulerAngles(&opod,ALPHA,BETA,GAMMA);
    opo_init(&opod);
    opod.Qmod = q;
    psi=sasfit_param_override_get_psi(PSI_DEG*M_PI/180.);
    opod.Q[0] = q*cos(psi);
    opod.Q[1] = q*sin(psi);
    opod.Q[2] = 0;
    opo_setQhat(&opod);
    return (ETA_P-ETA_M) *opo_Fc(&opod);
}
double form_volume(  double A,  double B,  double C)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double A, double B, double C)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, B, C);
}
