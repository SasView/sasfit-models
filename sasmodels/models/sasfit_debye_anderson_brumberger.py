r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by debye_anderson_brumberger

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "debye_anderson_brumberger"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "I0", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
 [ "XI", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_debye_anderson_brumberger.c" ]

demo = dict(
	I0 = 10.0,
	XI = 0.0)
