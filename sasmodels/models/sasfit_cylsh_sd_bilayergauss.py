r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by cylsh_sd_bilayergauss

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "cylsh_sd_bilayergauss"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "T", 	"", 	10.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

source = [  "sasfit_cylsh_sd_bilayergauss.c" ]

demo = dict(
	T = 10.0)
