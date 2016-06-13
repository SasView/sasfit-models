r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by parallelepiped_ab

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "parallelepiped_ab"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "BETA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_parallelepiped_ab.c" ]

demo = dict(
	A = 10.0,
	B = 0.0,
	C = 0.0,
	ETA = 1.0,
	Q = 0.0,
	ALPHA = 0.0,
	BETA = 0.0)
