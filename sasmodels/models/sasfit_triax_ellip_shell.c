///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/plugins/triax_ellip_shell/sasfit_ff_triax_ellip_shell.c
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
double Iq( double q, double A, double B, double C, double T, double ETA_C,
           double ETA_SH, double ETA_SOL)
{
    double q, p, x, u_c, u_sh;
    double f_c, f_sh;
    q		= param->p[MAXPAR-1];
    p		= param->p[MAXPAR-2]; // pow
    x		= param->p[MAXPAR-3]; // param from outer integration
    if (fabs(A*B*C) + fabs(T) == 0.0) return 0.0;
    u_c = q*sqrt(( pow(A*cos(x*M_PI/2.),2.) + pow(B*sin(x*M_PI/2.),
                   2.) )*(1.-y*y) + pow(C*y,2.));
    u_sh = q*sqrt(( pow((A+T)*cos(x*M_PI/2.),2.) + pow((B+T)*sin(x*M_PI/2.),
                    2.) ) * (1.-y*y) + pow((C+T)*y,2.));
    f_c  = 4./3.*M_PI*A*B*C*(ETA_C-ETA_SH);
    if (u_c != 0.0)
    {
        f_c  = f_c * 3*(sin(u_c) -u_c *cos(u_c) )/pow(u_c ,3);
    }
    f_sh  = 4./3.*M_PI*(A+T)*(B+T)*(C+T)*(ETA_SH-ETA_SOL);
    if (u_sh != 0.0)
    {
        f_sh  = f_sh * 3*(sin(u_sh)-u_sh*cos(u_sh))/pow(u_sh,3);
    }
    return pow(f_sh+f_c, p);
}
double Iq( double q, double A, double B, double C, double T, double ETA_C,
           double ETA_SH, double ETA_SOL)
double A, double B, double C, double T, double ETA_C, double ETA_SH,
       double ETA_SOL)
{
    double res;
    param->p[MAXPAR-3] = x;
    double Iq( double q, double A, double B, double C, double T, double ETA_C,
               double ETA_SH, double ETA_SOL)
    double A, double B, double C, double T, double ETA_C, double ETA_SH,
           double ETA_SOL)
    double A, double B, double C, double T, double ETA_C, double ETA_SH,
    double ETA_SOL)
    return res;
}
double Iq( double q, double A, double B, double C, double T, double ETA_C,
           double ETA_SH, double ETA_SOL)
double A, double B, double C, double T, double ETA_C, double ETA_SH,
double ETA_SOL)
double A, double B, double C, double T, double ETA_C, double ETA_SH,
double ETA_SOL)
double A, double B, double C, double T, double ETA_C, double ETA_SH,
double ETA_SOL)
{
    double res;
    param->p[MAXPAR-1] = q;		// Q
    param->p[MAXPAR-2] = 2.0;	// pow
    double Iq( double q, double A, double B, double C, double T, double ETA_C,
               double ETA_SH, double ETA_SOL)
    double A, double B, double C, double T, double ETA_C, double ETA_SH,
           double ETA_SOL)
    double A, double B, double C, double T, double ETA_C, double ETA_SH,
    double ETA_SOL)
    double A, double B, double C, double T, double ETA_C, double ETA_SH,
    double ETA_SOL)
    double A, double B, double C, double T, double ETA_C, double ETA_SH,
    double ETA_SOL)
    return res;
}
double Fq( double q,  double A, double B, double C, double T, double ETA_C,
           double ETA_SH, double ETA_SOL)
{
// insert your code here
    return 0.0;
}
double form_volume(  double A, double B, double C, double T, double ETA_C,
                     double ETA_SH, double ETA_SOL)
{
    double V;
    switch ( dist )
    {
    case 0:
        V = (x + T) * (B + T) * (C + T);
        break;
    case 1:
        V = (A + T) * (x + T) * (C + T);
        break;
    case 2:
        V = (A + T) * (B + T) * (x + T);
        break;
    case 3:
        V = (A + x) * (B + x) * (C + x);
        break;
    default:
        V = (A + T) * (B + T) * (C + T);
        break;
    }
    return 4.0/3.0 * M_PI * x;
}
double Iqxy( double qx, double qy, double A, double B, double C, double T,
             double ETA_C, double ETA_SH, double ETA_SOL)
{
    double q = sqrt(qx*qx + qy*qy);
    return Iq( q, A, B, C, T, ETA_C, ETA_SH, ETA_SOL);
}
