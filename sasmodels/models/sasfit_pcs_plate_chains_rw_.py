r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by pcs_plate_chains_rw_

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "pcs_plate_chains_rw_"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "LC", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "N_AGG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "V_BRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_CORE", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_BRUSH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOLV", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "XSOLV_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "RG", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "D", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "PCHAIN", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "NAGG", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
 [ "V_CORE", 	"", 	0.0, 	[-inf, inf], 	"", 	" "],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_pcs_plate_chains_rw_.c" ]

demo = dict(
	LC = 10.0,
	N_AGG = 0.0,
	V_BRUSH = 0.0,
	ETA_CORE = 1.0,
	ETA_BRUSH = 0.0,
	ETA_SOLV = 0.0,
	XSOLV_CORE = 0.0,
	RG = 0.0,
	D = 0.0,
	PCHAIN = 0.0,
	NAGG = 0.0,
	V_CORE = 0.0)
