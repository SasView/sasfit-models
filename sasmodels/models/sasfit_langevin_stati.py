r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by langevin_stati

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "langevin_stati"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "NU", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_langevin_stati.c" ]

demo = dict(
	NU = 10.0)
