r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by gz_ggc

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "gz_ggc"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "RG", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "NU", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "DUMMY2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "I0", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c", "lib/sas_gamma.c",  "sasfit_gz_ggc.c" ]

demo = dict(
	RG = 10.0,
	NU = 0.0,
	DUMMY2 = 0.0,
	I0 = 1.0,
	P0 = 0.0)
