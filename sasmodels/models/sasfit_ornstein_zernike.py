r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by ornstein_zernike

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "ornstein_zernike"
title = " "
description = "F^2(Q,Rg,I0) = I0/(1+Q^2*xi^2)"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "I0", 	"", 	10.0, 	[-inf, inf], 	"", 	"xi: correlation length"],
 [ "XI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_ornstein_zernike.c" ]

demo = dict(
	I0 = 10.0,
	XI = 0.0,
	P0 = 0.0)
