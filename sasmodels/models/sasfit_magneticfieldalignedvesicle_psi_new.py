r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by magneticfieldalignedvesicle_psi_new

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "magneticfieldalignedvesicle_psi_new"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "RSHMODE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "THETA_1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "R1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "THETA_2", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "R2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "_PSI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "SIGMA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "KAPPA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "BIG_THETA_1", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "BIG_THETA_2", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DELTA_1", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DELTA_2", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "D_1", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "D_2", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DIF_ETA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "DIF_ETA_C", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "GAMMA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "_THETA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "_PHI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PSI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R_1", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "R_2", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/polevl.c", "lib/sas_J1.c", "lib/sas_erf.c",  "sasfit_magneticfieldalignedvesicle_psi_new.c" ]

demo = dict(
	RSHMODE = 10.0,
	THETA_1 = 0.0,
	R1 = 0.0,
	THETA_2 = 1.0,
	R2 = 0.0,
	T_SH = 0.0,
	T_C = 0.0,
	ETA_SH = 0.0,
	ETA_C = 0.0,
	ETA_SOL = 0.0,
	_PSI = 0.0,
	SIGMA = 0.0,
	KAPPA = 0.0,
	Q = 0.0,
	BIG_THETA_1 = 0.0,
	BIG_THETA_2 = 0.0,
	DELTA_1 = 0.0,
	DELTA_2 = 0.0,
	D_1 = 0.0,
	D_2 = 0.0,
	DIF_ETA_SH = 0.0,
	DIF_ETA_C = 0.0,
	GAMMA = 0.0,
	_THETA = 0.0,
	_PHI = 0.0,
	PSI = 0.0,
	R_SH = 0.0,
	R_1 = 0.0,
	R_2 = 0.0)
