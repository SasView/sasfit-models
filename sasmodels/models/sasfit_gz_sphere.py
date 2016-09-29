r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by gz_sphere

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "gz_sphere"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_gz_sphere.c" ]

demo = dict(
	R = 10.0,
	DUMMY1 = 0.0,
	DUMMY2 = 0.0,
	ETA = 1.0,
	P0 = 0.0)
