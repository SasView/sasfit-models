r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pearl_necklace

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pearl_necklace"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "l", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "NU", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "NP", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/Si.c",  "sasfit_pearl_necklace.c" ]

demo = dict(
	R = 10.0,
	l = 0.0,
	NU = 0.0,
	B = 1.0,
	NP = 0.0,
	P0 = 0.0)
