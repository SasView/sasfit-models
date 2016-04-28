r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by DAB

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "DAB"
title = " "
description = "F^2(Q,Rg,I0) = I0/(1+Q^2*xi^2)^2"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "xi", 	"", 	10.0, 	[-inf, inf], 	"", 	"xi: correlation length"],
 [ "I0", 	"", 	0.0, 	[-inf, inf], 	"", 	"I0: forward scattering I(Q=0)"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_DAB.c" ]

demo = dict(
	xi = 10.0,
	I0 = 0.0)
