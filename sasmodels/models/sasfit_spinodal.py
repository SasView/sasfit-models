r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by spinodal

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "spinodal"
title = " "
description = "F^2(Q,gamma,Qmax,I0) = I0 (1+gamma/2)(Q/Qmax)^2/(gamma/2+(Q/Qmax)^(2+gamma))"
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "IMAX", 	"", 	1.0, 	[-inf, inf], 	"", 	"Qmax:"],
 [ "QMAX", 	"", 	0.04, 	[-inf, inf], 	"", 	"gamma: the exponent gamma is equal to d+1 for off-critical concentration mixtures\nand 2d for critical concentration mixtures (d:dimension)"],
 [ "GAMMA", 	"", 	2.0, 	[-inf, inf], 	"", 	"Imax: scattering intensity at peak position I(Q=Qmax)"],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_spinodal.c" ]

demo = dict(
	IMAX = 1.0,
	QMAX = 0.04,
	GAMMA = 2.0)
