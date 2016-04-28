///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_PolydisperseStar.c
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
	double Rg,
	double f,
	double EMPTY,
	double I0)
{
double u2;//, Rg, f, I0;
if (q  == 0.0) return I0;
if (Rg == 0.0) return 0.0;
u2 = q*q*Rg*Rg;
return I0*(1.+u2/(3.*f))/pow(1.+u2*(1.+f)/(6.*f),2.);
}
double Iqxy( double qx, double qy,
	double Rg,
	double f,
	double EMPTY,
	double I0)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, Rg, f, EMPTY, I0);
}
