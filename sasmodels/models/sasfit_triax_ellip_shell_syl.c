///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double P0);
double Fq( double q,  double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double P0);
double form_volume(  double A,  double DELTA_B,  double DELTA_C,  double T,
                     double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
                     double V_POL_AP,  double P0);
double Iqxy( double qx, double qy, double A, double DELTA_B, double DELTA_C,
             double T, double ETA_C, double ETA_SH_DRY, double ETA_SOL, double PHI,
             double V_POL_AP, double P0);
/*
* src/plugins/triax_ellip_shell/sasfit_ff_triax_ellip_shell_syl.c
*
* Copyright (c) 2008-2009, Paul Scherrer Institute (PSI)
*
* This file is part of SASfit.
*
* SASfit is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* SASfit is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with SASfit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
* Author(s) of this file:
*   Joachim Kohlbrecher (joachim.kohlbrecher@psi.ch)
*   Ingo Bressler (ingo@cs.tu-berlin.de)
*/
// define shortcuts for local A, DELTA_B, DELTA_C, T, ETA_C, ETA_SH_DRY, ETA_SOL, PHI, V_POL_AP, P0eters/variables
double sasfit_ff_triax_ellip_shell_syl_core(double y,  double A,
        double DELTA_B,  double DELTA_C,  double T,  double ETA_C,  double ETA_SH_DRY,
        double ETA_SOL,  double PHI,  double V_POL_AP,  double P0)
{
    double q, p, x, b, c, u_c, u_sh, eta_sh, f_c, f_sh;
    if (fabs(A*b*c) + fabs(T) == 0.0) return 0.0;
    u_c = q*sqrt(( pow(A*cos(x*M_PI/2.),2.) + pow(b*sin(x*M_PI/2.),
                   2.) )*(1.-y*y) + pow(c*y,2.));
    u_sh = q*sqrt(( pow((A+T)*cos(x*M_PI/2.),2.) + pow((b+T)*sin(x*M_PI/2.),
                    2.) ) * (1.-y*y) + pow((c+T)*y,2.));
    f_c  = 4./3.*M_PI*A*b*c*(ETA_C-eta_sh);
    if (u_c != 0.0)
    {
        f_c  = f_c * 3*(sin(u_c) -u_c *cos(u_c) )/pow(u_c ,3);
    }
    f_sh  = 4./3.*M_PI*(A+T)*(b+T)*(c+T)*(eta_sh-ETA_SOL);
    if (u_sh != 0.0)
    {
        f_sh  = f_sh * 3*(sin(u_sh)-u_sh*cos(u_sh))/pow(u_sh,3);
    }
    return pow(f_sh+f_c, p);
}
double sasfit_ff_triax_ellip_shell_syl_core_x(double x,  double A,
        double DELTA_B,  double DELTA_C,  double T,  double ETA_C,  double ETA_SH_DRY,
        double ETA_SOL,  double PHI,  double V_POL_AP,  double P0)
{
    double res;
    res = sasfit_integrate(0.0, 1.0, sasfit_ff_triax_ellip_shell_syl_core, A,
                           DELTA_B, DELTA_C, T, ETA_C, ETA_SH_DRY, ETA_SOL, PHI, V_POL_AP, P0);
    return res;
}
double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double P0)
{
    double res, b, c, w, eta_sh, n;
    b = A + DELTA_B;
    c = b + DELTA_C;
    w = 1.0 - ((V_POL_AP * A * b * c)/((A+T)*(b+T)*(c+T) - A*b*c));
    eta_sh = (1.0-w)*ETA_SH_DRY + w*ETA_SOL;
    n = PHI/((1.0+V_POL_AP)*4./3.*M_PI*A*b*c);
    res = sasfit_integrate(0.0, 1.0, sasfit_ff_triax_ellip_shell_syl_core_x, A,
                           DELTA_B, DELTA_C, T, ETA_C, ETA_SH_DRY, ETA_SOL, PHI, V_POL_AP, P0);
    return n*res;
}
double Fq( double q,  double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double P0)
{
// insert your code here
    return 0.0;
}
double form_volume(  double A,  double DELTA_B,  double DELTA_C,  double T,
                     double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
                     double V_POL_AP,  double P0)
{
    double b, c;
    b = A + DELTA_B;
    c = b + DELTA_C;
    switch ( dist )
    {
    case 0:
        q = (q + T) * (b + T) * (c + T);
        break;
    case 1:
        q = (A + T) * (q + T) * (c + T);
        break;
    case 2:
        q = (A + T) * (b + T) * (q + T);
        break;
    case 3:
        q = (A + q) * (b + q) * (c + q);
        break;
    default:
        q = (A + T) * (b + T) * (c + T);
        break;
    }
    return 4.0/3.0 * M_PI * q;
}
double Iqxy( double qx, double qy, double A, double DELTA_B, double DELTA_C,
             double T, double ETA_C, double ETA_SH_DRY, double ETA_SOL, double PHI,
             double V_POL_AP, double P0)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, DELTA_B, DELTA_C, T, ETA_C, ETA_SH_DRY, ETA_SOL, PHI, V_POL_AP,
               P0);
}
