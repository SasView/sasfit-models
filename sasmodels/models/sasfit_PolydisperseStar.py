r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by PolydisperseStar

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "PolydisperseStar"
title = " "
description = "F^2(Q,Rg,f,eta) = I0*(2/(f*v*v)*(-1+v+exp(-v)+(f-1)*pow(1-exp(-v),2)/2))\nwith u=Rg*Rg*Q*Q and v=u*f/(3*f-2)"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "Rg", 	"", 	10.0, 	[-inf, inf], 	"", 	"Rg: radius of gyratio"],
 [ "f", 	"", 	0.0, 	[-inf, inf], 	"", 	"f: number of branches"],
 [ "EMPTY", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "I0", 	"", 	1.0, 	[-inf, inf], 	"", 	"I0: forward scattering"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_PolydisperseStar.c" ]

demo = dict(
	Rg = 10.0,
	f = 0.0,
	EMPTY = 0.0,
	I0 = 1.0)
