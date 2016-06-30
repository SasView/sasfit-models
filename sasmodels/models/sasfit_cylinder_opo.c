///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double A,  double B,  double C,  double P0,  double A,
           double EA_X,  double EA_Y,  double EA_Z,  double B,  double EB_X,  double EB_Y,
           double EB_Z,  double C,  double EC_X,  double EC_Y,  double EC_Z,  double ETA_P,
           double ETA_M,  double ALPHA,  double BETA,  double GAMMA,  double PSI_DEG);
double Fq( double q,  double A,  double B,  double C,  double P0,  double A,
           double EA_X,  double EA_Y,  double EA_Z,  double B,  double EB_X,  double EB_Y,
           double EB_Z,  double C,  double EC_X,  double EC_Y,  double EC_Z,  double ETA_P,
           double ETA_M,  double ALPHA,  double BETA,  double GAMMA,  double PSI_DEG);
double form_volume(  double A,  double B,  double C,  double P0,  double A,
                     double EA_X,  double EA_Y,  double EA_Z,  double B,  double EB_X,  double EB_Y,
                     double EB_Z,  double C,  double EC_X,  double EC_Y,  double EC_Z,  double ETA_P,
                     double ETA_M,  double ALPHA,  double BETA,  double GAMMA,  double PSI_DEG);
double Iqxy( double qx, double qy, double A, double B, double C, double P0,
             double A, double EA_X, double EA_Y, double EA_Z, double B, double EB_X,
             double EB_Y, double EB_Z, double C, double EC_X, double EC_Y, double EC_Z,
             double ETA_P, double ETA_M, double ALPHA, double BETA, double GAMMA,
             double PSI_DEG);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local A, B, C, P0, A, EA_X, EA_Y, EA_Z, B, EB_X, EB_Y, EB_Z, C, EC_X, EC_Y, EC_Z, ETA_P, ETA_M, ALPHA, BETA, GAMMA, PSI_DEGeters/variables
opo_data opod;
double Iq( double q, double A,  double B,  double C,  double P0,  double A,
           double EA_X,  double EA_Y,  double EA_Z,  double B,  double EB_X,  double EB_Y,
           double EB_Z,  double C,  double EC_X,  double EC_Y,  double EC_Z,  double ETA_P,
           double ETA_M,  double ALPHA,  double BETA,  double GAMMA,  double PSI_DEG)
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
double Fq( double q,  double A,  double B,  double C,  double P0,  double A,
           double EA_X,  double EA_Y,  double EA_Z,  double B,  double EB_X,  double EB_Y,
           double EB_Z,  double C,  double EC_X,  double EC_Y,  double EC_Z,  double ETA_P,
           double ETA_M,  double ALPHA,  double BETA,  double GAMMA,  double PSI_DEG)
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
double form_volume(  double A,  double B,  double C,  double P0,  double A,
                     double EA_X,  double EA_Y,  double EA_Z,  double B,  double EB_X,  double EB_Y,
                     double EB_Z,  double C,  double EC_X,  double EC_Y,  double EC_Z,  double ETA_P,
                     double ETA_M,  double ALPHA,  double BETA,  double GAMMA,  double PSI_DEG)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double A, double B, double C, double P0,
             double A, double EA_X, double EA_Y, double EA_Z, double B, double EB_X,
             double EB_Y, double EB_Z, double C, double EC_X, double EC_Y, double EC_Z,
             double ETA_P, double ETA_M, double ALPHA, double BETA, double GAMMA,
             double PSI_DEG)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, B, C, P0, A, EA_X, EA_Y, EA_Z, B, EB_X, EB_Y, EB_Z, C, EC_X,
               EC_Y, EC_Z, ETA_P, ETA_M, ALPHA, BETA, GAMMA, PSI_DEG);
}
