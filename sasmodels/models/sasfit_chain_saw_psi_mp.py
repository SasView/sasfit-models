r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by chain_saw_psi_mp

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "chain_saw_psi_mp"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R_CORE", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SNAGG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "VBRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RG", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "T_BRUSH_CONST", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA_BRUSH_GAUSSIAN", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "POL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "L_B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_chain_saw_psi_mp.c" ]

demo = dict(
	R_CORE = 10.0,
	SNAGG = 0.0,
	VBRUSH = 0.0,
	RG = 1.0,
	T_BRUSH_CONST = 0.0,
	SIGMA_BRUSH_GAUSSIAN = 0.0,
	POL = 0.0,
	L_B = 0.0)
