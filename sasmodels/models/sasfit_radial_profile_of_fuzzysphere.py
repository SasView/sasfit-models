r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by radial_profile_of_fuzzysphere

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "radial_profile_of_fuzzysphere"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "SIGMA", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SPH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/polevl.c", "lib/sas_erf.c", "lib/sas_pow.c",  "sasfit_radial_profile_of_fuzzysphere.c" ]

demo = dict(
	R = 10.0,
	SIGMA = 0.0,
	ETA_SPH = 0.0,
	ETA_SOL = 1.0)
