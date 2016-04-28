r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by TwoInfinitelyThinPlates

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "TwoInfinitelyThinPlates"
title = " "
description = "P(Q,L,I0) ="
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "L", 	"", 	10.0, 	[-inf, inf], 	"", 	"L: layer distance"],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	"D: diameter of planar object"],
 [ "I0", 	"", 	0.0, 	[-inf, inf], 	"", 	"I0: forward scattering"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["lib/polevl.c","lib/sas_J1.c","sasfit_TwoInfinitelyThinPlates.c" ]

demo = dict(
	L = 10.0,
	D = 0.0,
	I0 = 0.0)
