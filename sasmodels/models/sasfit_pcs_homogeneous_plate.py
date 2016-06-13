r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_homogeneous_plate

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_homogeneous_plate"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "T", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_T", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY2", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_L", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_pcs_homogeneous_plate.c" ]

demo = dict(
	T = 10.0,
	SIGMA_T = 0.0,
	DUMMY1 = 0.0,
	DUMMY2 = 1.0,
	ETA_L = 0.0,
	ETA_SOL = 0.0,
	Q = 0.0)
