r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by gz_generalized_dab

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "gz_generalized_dab"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "H", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/sas_gamma.c",  "sasfit_gz_generalized_dab.c" ]

demo = dict(
	A = 10.0,
	H = 0.0,
	DUMMY = 0.0,
	ETA = 1.0,
	P0 = 0.0)
