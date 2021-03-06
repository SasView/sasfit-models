r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by teubner_strey

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "teubner_strey"
title = " "
description = "F^2(Q,Rg,I0) = eta^2*8*pi/xi/(a^2-2bq^2+q^4)\nwith k=2pi/d, a=k^2+1/xi^2, b=k^2-1/xi^2"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "xi", 	"", 	10.0, 	[-inf, inf], 	"", 	"xi: correlation length"],
 [ "d", 	"", 	0.0, 	[-inf, inf], 	"", 	"d: characteristic domain size (the periodicity)"],
 [ "eta", 	"", 	0.0, 	[-inf, inf], 	"", 	"eta: mean average contrast"],
 [ "P0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_teubner_strey.c" ]

demo = dict(
	xi = 10.0,
	d = 0.0,
	eta = 0.0,
	P0 = 1.0)
