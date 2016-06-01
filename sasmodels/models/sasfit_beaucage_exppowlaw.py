r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by beaucage_exppowlaw

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "beaucage_exppowlaw"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "G", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "GS", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "BS", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "RG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RSUB", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RS", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PS", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = ["sasfit_beaucage_exppowlaw.c" ]

demo = dict(
	G = 10.0,
	B = 0.0,
	GS = 0.0,
	BS = 1.0,
	RG = 0.0,
	RSUB = 0.0,
	RS = 0.0,
	P = 0.0,
	PS = 0.0)
