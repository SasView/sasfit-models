r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by radial_profile_of_expshell

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "radial_profile_of_expshell"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R_CORE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "DR", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SHELL", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "X_IN_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "X_OUT_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ALPHA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_radial_profile_of_expshell.c" ]

demo = dict(
	R_CORE = 10.0,
	DR = 0.0,
	ETA_CORE = 0.0,
	ETA_SHELL = 1.0,
	X_IN_SOL = 0.0,
	X_OUT_SOL = 0.0,
	ALPHA = 0.0,
	ETA_SOL = 0.0,
	P0 = 0.0)
