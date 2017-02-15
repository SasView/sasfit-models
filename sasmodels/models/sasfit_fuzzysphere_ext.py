r"""
This file has been automatically gereated by sasfit_convert
The model calculates an empirical functional form for SAS data characterized
by fuzzysphere

Definition:
-----------

References:
-----------

"""
from numpy import inf

name = "fuzzysphere_ext"
title = " "
description = ""
category = " "
#pylint: disable=bad-whitespace, line-too-long
parameters = [
 [ "R", 	"", 	2.5, 	[-inf, inf], 	"volume", 	""],
 [ "SIGMA", 	"", 	0.8, 	[-inf, inf], 	"", 	""],
 [ "ETA_SPH", 	"", 	1.0, 	[-inf, inf], 	"", 	""],
 [ "ETA_SOL", 	"", 	0.0, 	[-inf, inf], 	"", 	""],
]
 #pylint: enable=bad-whitespace, line-too-long

opencl=False

source = [ "lib/sas_pow.c",  "sasfit_fuzzysphere_ext.c" ]

demo = dict(
	R = 2.5,
	SIGMA = 0.8,
	ETA_SPH = 1.0,
	ETA_SOL = 0.0)

tests = [

    [{'R': 2.5,
      'SIGMA': 0.8,
      'ETA_SPH':1.0,
      'ETA_SOL':0.0,
      'background':0.0},
    0.1, 64.223],
]