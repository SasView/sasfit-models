///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local parameters/variables
double Iq( double q, double XMIN, double XMAX, double Y1, double Y2, double Y3,
           double Y4, double Y5, double Y6, double Y7, double Y8)
{
    double tmp, xcs[10], ycs[10];
    int i;
    if (x < XMIN) return 0;
    if (x > XMAX) return 0;
    if (XMIN > XMAX) {
        tmp = XMAX;
        XMAX = XMIN;
        XMIN = tmp;
    }
    xcs[0]=XMIN;
    ycs[0]=0;
    xcs[9]=XMAX;
    ycs[9]=0;
    for (i=1; i<=8; i++) {
        xcs[i] = XMIN+i*(XMAX-XMIN)/(8.0+1.0);
        ycs[i] = param->p[1+i];
    }
    gsl_spline_init(ffcspline8_T, xcs, ycs, 10);
    return gsl_spline_eval (ffcspline8_T, x, acc_cspline);
}
double Fq( double q,  double XMIN, double XMAX, double Y1, double Y2,
           double Y3, double Y4, double Y5, double Y6, double Y7, double Y8)
{
// insert your code here
    return 0.0;
}
double form_volume(  double XMIN, double XMAX, double Y1, double Y2, double Y3,
                     double Y4, double Y5, double Y6, double Y7, double Y8)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double XMIN, double XMAX, double Y1,
             double Y2, double Y3, double Y4, double Y5, double Y6, double Y7, double Y8)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, XMIN, XMAX, Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8);
}
