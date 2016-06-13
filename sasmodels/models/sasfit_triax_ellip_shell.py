r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by triax_ellip_shell

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "triax_ellip_shell"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "A", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "B", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "T", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_C", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SH", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_triax_ellip_shell.c" ]

demo = dict(
	A = 10.0,
	B = 0.0,
	C = 0.0,
	T = 1.0,
	ETA_C = 0.0,
	ETA_SH = 0.0,
	ETA_SOL = 0.0)
