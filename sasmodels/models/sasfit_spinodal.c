///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* Author(s) of this file:
*   <your name> (<email address>)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double IMAX, double QMAX, double GAMMA)
{
    double tmp,c;
// insert your code here
    tmp = q/QMAX;
    c = GAMMA/2.+pow(tmp,2.+GAMMA);
    return IMAX*tmp*tmp*(1.+GAMMA/2.)/c;
}
double Fq( double q,  double IMAX, double QMAX, double GAMMA)
{
// insert your code here
    return 0.0;
}
double form_volume(  double IMAX, double QMAX, double GAMMA)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double IMAX, double QMAX, double GAMMA)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, IMAX, QMAX, GAMMA);
}
