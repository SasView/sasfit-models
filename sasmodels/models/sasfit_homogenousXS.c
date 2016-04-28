///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_homogenousXS.c
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
double Iq( double q,
	double L,
	double D,
	double eta)
{
double u, Pprime, R;
u = q*L*0.5;
R = 0.5*D;
if (q == 0.0)
{
Pprime = pow(M_PI*R*R,2);
}
else if (D == 0.0)
{
Pprime = 0.0;
} else {
Pprime = pow(M_PI*R*R,2)*2.0/pow(q*R,2)*(1.0-sas_J1(D*q)/(q*R));
}
if (u  == 0.0) return 0;
return pow(L*eta*sin(u)/u, 2)*Pprime;
}
double Iqxy( double qx, double qy,
	double L,
	double D,
	double eta)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, L, D, eta);
}
