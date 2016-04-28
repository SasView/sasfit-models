///////////////////////////////////////////////////
//    This is automatically genearted file       //
//    by sasfit_convert.py                       //
//    Some editting might be required            //
///////////////////////////////////////////////////

/*
* src/sasfit_ff/sasfit_ff_DAB.c
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
/*
float DAB(Tcl_Interp *interp,
float Q,
float xi,
float I0,
bool  *error)
*/
double Iq( double q,
	double xi,
	double I0)
{
return I0/pow(q*q * xi*xi+1.0,2.0);
}
double Iqxy( double qx, double qy,
	double xi,
	double I0)
{
	double q = sqrt(qx*qx + qy*qy);
	return Iq( q, xi, I0);
}
