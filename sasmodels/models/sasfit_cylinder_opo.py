r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by cylinder_opo

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "cylinder_opo"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_cylinder_opo.c" ]

demo = dict(
	A = 10.0,
	B = 0.0,
	C = 0.0)
