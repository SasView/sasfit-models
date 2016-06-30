r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by ellipsoid_opo

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "ellipsoid_opo"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "A", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EA_X", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EA_Y", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EA_Z", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EB_X", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "EB_Y", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EB_Z", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EC_X", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EC_Y", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EC_Z", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_P", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ETA_M", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "BETA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "GAMMA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PSI_DEG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_ellipsoid_opo.c" ]

demo = dict(
	A = 10.0,
	B = 0.0,
	C = 0.0,
	P0 = 1.0,
	A = 0.0,
	EA_X = 0.0,
	EA_Y = 0.0,
	EA_Z = 0.0,
	B = 0.0,
	EB_X = 0.0,
	EB_Y = 0.0,
	EB_Z = 0.0,
	C = 0.0,
	EC_X = 0.0,
	EC_Y = 0.0,
	EC_Z = 0.0,
	ETA_P = 0.0,
	ETA_M = 0.0,
	ALPHA = 0.0,
	BETA = 0.0,
	GAMMA = 0.0,
	PSI_DEG = 0.0)
