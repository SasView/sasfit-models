r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by magneticfieldalignedvesicleP2Psi

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "magneticfieldalignedvesicleP2Psi"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "RSH0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "THETA1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "THETA2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T_SH", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "T_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DETA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DETA_CE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PSI_DEG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "KAPPA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "Q", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "RKERNEL", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "GAMA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "_THETA", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PHI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "PSI", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "RSH", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/polevl.c", "lib/sas_erf.c", "lib/sas_pow.c",  "sasfit_magneticfieldalignedvesicleP2Psi.c" ]

demo = dict(
	RSH0 = 10.0,
	THETA1 = 0.0,
	THETA2 = 0.0,
	T_SH = 1.0,
	T_C = 0.0,
	DETA_SH = 0.0,
	DETA_CE = 0.0,
	SIGMA = 0.0,
	PSI_DEG = 0.0,
	KAPPA = 0.0,
	Q = 0.0,
	RKERNEL = 0.0,
	GAMA = 0.0,
	_THETA = 0.0,
	PHI = 0.0,
	PSI = 0.0,
	RSH = 0.0)
