///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double EMPTY,  double DR,  double eta_core,
           double eta_shell,  double x_in_solvent,  double x_out_solvent,
           double eta_solvent,  double P0);
double Fq( double q,  double EMPTY,  double DR,  double eta_core,
           double eta_shell,  double x_in_solvent,  double x_out_solvent,
           double eta_solvent,  double P0);
double form_volume(  double EMPTY,  double DR,  double eta_core,
                     double eta_shell,  double x_in_solvent,  double x_out_solvent,
                     double eta_solvent,  double P0);
double Iqxy( double qx, double qy, double EMPTY, double DR, double eta_core,
             double eta_shell, double x_in_solvent, double x_out_solvent, double eta_solvent,
             double P0);
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*/
// define shortcuts for local EMPTY, DR, eta_core, eta_shell, x_in_solvent, x_out_solvent, eta_solvent, P0eters/variables
#define R1		RTOT-DR
double Iq( double q, double EMPTY,  double DR,  double eta_core,
           double eta_shell,  double x_in_solvent,  double x_out_solvent,
           double eta_solvent,  double P0)
{
    return sas_pow_2(Fq(q,EMPTY, DR, eta_core, eta_shell, x_in_solvent,
                        x_out_solvent, eta_solvent, P0));
}
double Fq( double q,  double EMPTY,  double DR,  double eta_core,
           double eta_shell,  double x_in_solvent,  double x_out_solvent,
           double eta_solvent,  double P0)
{
    double A, t1, t2, shlin, m, b, eta_sh_in, eta_sh_out;
    double DR, eta_core, eta_shell, x_in_solvent, x_out_solvent, eta_solvent;
    eta_sh_in  = (1.0- x_in_solvent)*eta_shell +  x_in_solvent*eta_solvent
                 -eta_solvent;
    eta_sh_out = (1.0-x_out_solvent)*eta_shell + x_out_solvent*eta_solvent
                 -eta_solvent;
    A = q*R1;
    shlin = 4.0*M_PI*(eta_core-eta_solvent)*(sin(A)-A*cos(A))/pow(q,3.0);
    if (DR > 0)
    {
        m = (eta_sh_out-eta_sh_in)/DR;
        b = -m*R1+eta_sh_in;
        t1 = 4.0*M_PI*m*(2.0*cos(A)+2.0*A*sin(A)-A*A*cos(A))/pow(q,4);
        t2 = 4.0*M_PI*b*(sin(A)-A*cos(A))/pow(q,3.0);
        shlin = shlin-t1-t2;
        A = q*(R1+DR);
        t1 = 4.0*M_PI*m*(2.0*cos(A)+2.0*A*sin(A)-A*A*cos(A))/pow(q,4);
        t2 = 4.0*M_PI*b*(sin(A)-A*cos(A))/pow(q,3.0);
        shlin = shlin+t1+t2;
    }
    return shlin;
}
double form_volume(  double EMPTY,  double DR,  double eta_core,
                     double eta_shell,  double x_in_solvent,  double x_out_solvent,
                     double eta_solvent,  double P0)
{
// insert your code here
    return 0.0;
}
double Iqxy( double qx, double qy, double EMPTY, double DR, double eta_core,
             double eta_shell, double x_in_solvent, double x_out_solvent, double eta_solvent,
             double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, EMPTY, DR, eta_core, eta_shell, x_in_solvent, x_out_solvent,
               eta_solvent, P0);
}
