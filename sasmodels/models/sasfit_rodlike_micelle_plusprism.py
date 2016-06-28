r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by rodlike_micelle_plusprism

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "rodlike_micelle_plusprism"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "EPSILON", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "L", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PHI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PAR", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "HOW", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "THETA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/Si.c", "lib/polevl.c", "lib/sas_J1.c",  "sasfit_rodlike_micelle_plusprism.c" ]

demo = dict(
	R = 10.0,
	EPSILON = 0.0,
	L = 0.0,
	T = 1.0,
	ETA_CORE = 0.0,
	ETA_SH = 0.0,
	ETA_SOL = 0.0,
	PHI = 0.0,
	PAR = 0.0,
	HOW = 0.0,
	Q = 0.0,
	ALPHA = 0.0,
	THETA = 0.0)
