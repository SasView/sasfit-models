r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by DoubleShell_withSD

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "DoubleShell_withSD"
title = " "
description = "F^2(Q,R,s,...) analytical expression for spherical double shells\nwith a size distributio"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	"R: mean radius of core"],
 [ "s", 	"", 	0.0, 	[-inf, inf], 	"", 	"s: width of size distributio"],
 [ "c1", 	"", 	0.0, 	[-inf, inf], 	"", 	"eta_c: scattering length density of core"],
 [ "c2", 	"", 	1.0, 	[-inf, inf], 	"", 	"eta_1: scattering length density of first shell"],
 [ "c3", 	"", 	0.0, 	[-inf, inf], 	"", 	"eta_2: scattering length density of second shell"],
 [ "cm", 	"", 	0.0, 	[-inf, inf], 	"", 	"eta_m: scattering length density of matrix"],
 [ "d1", 	"", 	0.0, 	[-inf, inf], 	"", 	"d_1: thickness of first shell"],
 [ "d2", 	"", 	0.0, 	[-inf, inf], 	"", 	"d_2: thickness of second shell"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_DoubleShell_withSD.c" ]

demo = dict(
	R = 10.0,
	s = 0.0,
	c1 = 0.0,
	c2 = 1.0,
	c3 = 0.0,
	cm = 0.0,
	d1 = 0.0,
	d2 = 0.0)
