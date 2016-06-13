r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by ornstein_zernike

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "ornstein_zernike"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "I0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "XI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_ornstein_zernike.c" ]

demo = dict(
	I0 = 10.0,
	XI = 0.0)
