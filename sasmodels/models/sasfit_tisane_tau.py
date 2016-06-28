r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by tisane_tau

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "tisane_tau"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "NU", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [ "lib/sas_pow.c",  "sasfit_tisane_tau.c" ]

demo = dict(
	NU = 10.0)
