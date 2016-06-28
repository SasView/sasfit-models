///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP);
double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP) double A,  double DELTA_B,  double DELTA_C,  double T,
                  double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
                  double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
                  double ZB,  double TEMP);
double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP) double A,  double DELTA_B,  double DELTA_C,  double T,
double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
double ZB,  double TEMP) double A,  double DELTA_B,  double DELTA_C,  double T,
double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
double ZB,  double TEMP);
double Fq( double q,  double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP);
double form_volume(  double A,  double DELTA_B,  double DELTA_C,  double T,
                     double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
                     double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
                     double ZB,  double TEMP);
double Iqxy( double qx, double qy, double A, double DELTA_B, double DELTA_C,
             double T, double ETA_C, double ETA_SH_DRY, double ETA_SOL, double PHI,
             double V_POL_AP, double ALPHA, double Z_P, double EPSILON_R, double MB,
             double ZB, double TEMP);
/*
* src/plugins/triax_ellip_shell/sasfit_ff_triax_ellip_shell_sq_baba_ahmed_2.c
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
// define shortcuts for local parameters/variables
double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP)
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
double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP) double A,  double DELTA_B,  double DELTA_C,  double T,
double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
double ZB,  double TEMP)
{
    double res;
    res = sasfit_integrate(0.0, 1.0,
                           sasfit_ff_triax_ellip_shell_sq_baba_ahmed_2_core, param);
    return res;
}
double Iq( double q, double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP) double A,  double DELTA_B,  double DELTA_C,  double T,
double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
double ZB,  double TEMP) double A,  double DELTA_B,  double DELTA_C,  double T,
double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
double ZB,  double TEMP)
{
    double res, b, c, w, eta_sh, n;
    sasfit_param subParam;
    DELTA_B = fabs(DELTA_B);
    DELTA_C = fabs(DELTA_C);
    b = A + DELTA_B;
    c = b + DELTA_C;
    w = 1.0 - ((V_POL_AP * A * b * c)/((A+T)*(b+T)*(c+T) - A*b*c));
    eta_sh = (1.0-w)*ETA_SH_DRY + w*ETA_SOL;
    n = PHI/((1.0+V_POL_AP)*4./3.*M_PI*A*b*c);
    res = sasfit_integrate(0.0, 1.0,
                           sasfit_ff_triax_ellip_shell_sq_baba_ahmed_2_core_x, param);
    sasfit_init_param(&subParam);
    subParam.p[0] = ALPHA * pow(A*b*c, 1.0/3.0); // R_ref
    subParam.p[1] = ALPHA;
    subParam.p[2] = Z_P;
    subParam.p[3] = EPSILON_R;
    subParam.p[4] = MB;
    subParam.p[5] = ZB;
    subParam.p[6] = PHI * sas_pow_3(ALPHA); // vol frac
    subParam.p[7] = TEMP;
    return n*res*sasfit_sq_baba_ahmed_syl(q, &subParam);
}
double Fq( double q,  double A,  double DELTA_B,  double DELTA_C,  double T,
           double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
           double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
           double ZB,  double TEMP)
{
// insert your code here
    return 0.0;
}
double form_volume(  double A,  double DELTA_B,  double DELTA_C,  double T,
                     double ETA_C,  double ETA_SH_DRY,  double ETA_SOL,  double PHI,
                     double V_POL_AP,  double ALPHA,  double Z_P,  double EPSILON_R,  double MB,
                     double ZB,  double TEMP)
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
             double V_POL_AP, double ALPHA, double Z_P, double EPSILON_R, double MB,
             double ZB, double TEMP)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, DELTA_B, DELTA_C, T, ETA_C, ETA_SH_DRY, ETA_SOL, PHI, V_POL_AP,
               ALPHA, Z_P, EPSILON_R, MB, ZB, TEMP);
}
