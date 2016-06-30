r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by fractal_series2

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "fractal_series2"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "N", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "XMIN", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "FD1", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "X12", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "FD2", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "XMAX", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
 [ "P0", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_fractal_series2.c" ]

demo = dict(
	N = 10.0,
	XMIN = 0.0,
	FD1 = 0.0,
	X12 = 1.0,
	FD2 = 0.0,
	XMAX = 0.0,
	P0 = 0.0)
