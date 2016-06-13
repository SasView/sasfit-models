r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by broad_peak

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "broad_peak"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "I0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "XI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "M", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "P", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_broad_peak.c" ]

demo = dict(
	I0 = 10.0,
	XI = 0.0,
	Q0 = 0.0,
	M = 1.0,
	P = 0.0)
