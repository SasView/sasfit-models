r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by extended_guinier_law

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "extended_guinier_law"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "I0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "A", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_extended_guinier_law.c" ]

demo = dict(
	I0 = 10.0,
	A = 0.0,
	RA = 0.0,
	P0 = 1.0)
