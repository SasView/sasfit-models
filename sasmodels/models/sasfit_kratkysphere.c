///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double R, double DELTA_Q_PERP, double ETA, double R0,
           double XI, double D, double SCALE param->p[6]
           , double Q);
double Fq( double q,  double R, double DELTA_Q_PERP, double ETA, double R0,
           double XI, double D, double SCALE param->p[6]
           , double Q);
double form_volume(  double R, double DELTA_Q_PERP, double ETA, double R0,
                     double XI, double D, double SCALE param->p[6]
                     , double Q);
double Iqxy( double qx, double qy, double R, double DELTA_Q_PERP, double ETA,
             double R0, double XI, double D, double SCALE param->p[6]
             , double Q);
/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double FFPhiKratky(double qperp, sasfit_param * param) {
    double P,P16, q;
    q = sqrt(qperp*qperp+Q*Q);
    if (q*R == 0) {
        P = sas_pow_2(ETA*4.*M_PI/3.*sas_pow_3(R));
    } else {
        P= sas_pow_2(ETA*4.*M_PI/3.*sas_pow_3(R)* 3.*(sin(q*R)-q*R*cos(q*R))/sas_pow_3(
                         q*R));
    }
    if ((XI == 0) || (R0 == 0)) {
        P16=1.0;
    } else {
        P16 = 1.0/pow(q*R0,D);
        P16 = P16*D*sas_gamma(D-1.0)/pow(1.0+1.0/(q*q*XI*XI),(D-1.0)/2.0);
        P16 = P16*sin((D-1.0)*atan(q*XI));
        P16 = P16*SCALE;
        P16 = (1.0+P16);
    }
    return P*P16;
}
double Iq( double q, double R, double DELTA_Q_PERP, double ETA, double R0,
           double XI, double D, double SCALE param->p[6]
           , double Q)
{
// insert your code here
    Q=q;
    return sasfit_integrate(0,DELTA_Q_PERP,FFPhiKratky,param)/DELTA_Q_PERP;
}
double Fq( double q,  double R, double DELTA_Q_PERP, double ETA, double R0,
           double XI, double D, double SCALE param->p[6]
           , double Q)
{
// insert your code here
    return 0.0;
}
double form_volume(  double R, double DELTA_Q_PERP, double ETA, double R0,
                     double XI, double D, double SCALE param->p[6]
                     , double Q)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double R, double DELTA_Q_PERP, double ETA,
             double R0, double XI, double D, double SCALE param->p[6]
             , double Q)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, R, DELTA_Q_PERP, ETA, R0, XI, D, SCALE param->p[6]
               , Q);
}
