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
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "IMAX", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "QMAX", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "GAMMA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_spinodal.c" ]

demo = dict(
	IMAX = 10.0,
	QMAX = 0.0,
	GAMMA = 0.0)
