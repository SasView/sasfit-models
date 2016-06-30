r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by disc_sd_homoxs

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "disc_sd_homoxs"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "T", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_T", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_D", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_L", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "LB", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "L", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "EXVOL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "CLB", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_disc_sd_homoxs.c" ]

demo = dict(
	T = 10.0,
	SIGMA_T = 0.0,
	D = 0.0,
	SIGMA_D = 1.0,
	DUMMY1 = 0.0,
	DUMMY2 = 0.0,
	ETA_L = 0.0,
	ETA_SOL = 0.0,
	P0 = 0.0,
	LB = 0.0,
	B = 0.0,
	L = 0.0,
	EXVOL = 0.0,
	CLB = 0.0)
