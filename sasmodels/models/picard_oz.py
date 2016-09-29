# -*- coding: utf-8 -*-
# *-----------------------------------------------------------------------*
# |                                                                       |
# | Copyright (c) 2016 by Paul Scherrer Institute (http://www.psi.ch)     |
# |                                                                       |
# | Author: A. Studer, Scientific Computing, PSI                          |
# | Contributor: J. Kohlbrecher, Neutron Laboratory, PSI                  |
# *-----------------------------------------------------------------------*
'''
Authors: A. Studer, J. Kohlbrecher, PSI
Adapted by Wojciech Potrzebowski, ESS to work with SasView
'''

category = "structure-factor"
structure_factor = True
single = False  # double precision only!

#  dp[0] = 2.0*radius_effective();
#  dp[1] = fabs(charge());
#  dp[2] = volfraction();
#  dp[3] = temperature();
#  dp[4] = salt_concentration();
#  dp[5] = dielectconst();




name = "picard_oz"
title = "Picard Ornstein-Zernike solver"
description = """\
    This code aims at solving the Ornstein Zernike equation.
    It is a python implementation of the algorithm described in
    J. Kohlbrecher's SASfit documentation. (Chapter 5.2)
    The documentation can be downloaded here:
    http://sourceforge.net/p/sasfit/sasfit/ci/tip/tree/doc/manual/sasfit.pdf
    The python code is intended primarily as
    the non-algorithmic part of the documentation of
    the Anderson Algorithm for OZ, so
    it does not focus on the iterative solver
    but on the Fixpoint operator, which is delicate
    due to being highly non-linear.
    Nevertheless the code is reasonable
    fast to carry out further experiments.
    (Only few options are implemented)
    If you are interested in the
    Anderson Acceleration Algorithm alone, see
    https://gitorious.psi.ch/scicomp/aa4oz/blobs/master/src/AA.c
    If you are interested to see the
    Anderson Acceleration Algorithm
    (and many more iterative Algorithms)
    solving the OZ equations, see
"""

POTENTIALS = [["Lenard-Jones", "HardSphere"]]

CLOSURES = [["Chain", "PercusYevick"]]

# pylint: disable=bad-whitespace, line-too-long
#             [ "name", "units", default, [lower, upper], "type", "description" ],
parameters = [
    ["potential", "", 0,   POTENTIALS,    "", "Use Lennard-Jones potential or hard spheres"],
    ["closure",   "",  0, CLOSURES,   "", "Use Hypernetted Chain Closure or Percus Yevick"],
    ["denisty",  "",   0.4,    [0, 0.74],    "", "define the Volume density of the liquid"],
    ["energy",   "epsilon/kT",  0.6,   [0, inf],    "", "define the binding energy of the Lennard Jones potential in kT units"],
    ]

#calculations
import numpy as np
from scipy.fftpack import dst, idst


#global constants
#*******************************************************************************
numberOfRadialSamplingPoints = 2**10   #In SASfit gridsize n=8 (2^7*2^3 = 2^10)
hardSphereRadiusInPoints = numberOfRadialSamplingPoints/2**3
#Length units is such that the 'box' has length 1
rLength = 1.0
#Calculate spacing in this length units
Delta_r = rLength/(numberOfRadialSamplingPoints - 1.0)
#Sphere radius (also for LJ)
hardSphereRadius = hardSphereRadiusInPoints*Delta_r




#Hankel transform
#*********************************************************************************
#See https://en.wikipedia.org/wiki/Hankel_transform#Relation_to_the_Fourier_transform_.28radially_symmetric_case_in_n-dimensions.29
#and http://mathworld.wolfram.com/SphericalBesselFunctionoftheFirstKind.html
#for connection between Fourier/Hankel transform and the spherical Bessel function (Set n=3 in the former)
#See http://docs.scipy.org/doc/scipy/reference/tutorial/fftpack.html#discrete-sine-transforms
#for the definition of dst and idst (discrete sine transform and its inverse) 
def hankelTransform(f, delta_r):
  numberOfSamplingPoints = f.shape[0]
  lr = np.arange(numberOfSamplingPoints).astype('float')
  lr += 1.0
  f_hat = dst(f*lr, type=1)
  f_hat /= lr
  delta_q = np.pi/((numberOfSamplingPoints + 1.0)*delta_r)
  f_hat *= 2*np.pi*delta_r**2/delta_q
  return f_hat
  
def inverseHankelTransform(f, delta_r):
  numberOfSamplingPoints = f.shape[0]
  delta_q = np.pi/((numberOfSamplingPoints + 1.0)*delta_r)
  return delta_q**3*hankelTransform(f, delta_r)/( (2*np.pi)**3*delta_r**3 )

#FixPoint Operator (In 'Gamma' space)
#*******************************************************************************************************
def fixPointOperatorForGamma(G):
    if not isHNC:
        c_new = boltzmannOfP2Ppotential*(1.0 + G) - G - 1.0
    else:
        c_new = boltzmannOfP2Ppotential*np.exp(G) - G - 1.0
    c_hat = hankelTransform(c_new, Delta_r)
    #G_new = inverseHankelTransform( (rho*c_hat**2)/(1.0 - rho*c_hat) )
    G_hat = c_hat/(1.0 - rho*c_hat) - c_hat
    #G_hat[np.isinf(G_hat)] = 0.0; G_hat[np.isneginf(G_hat)] = 0.0; G_hat[np.isnan(G_hat)] = 0.0
    G_new = inverseHankelTransform(G_hat, Delta_r)
    #G_new[np.isinf(G_new)] = 0.0; G_new[np.isneginf(G_new)] = 0.0; G_new[np.isnan(G_new)] = 0.0
    return (G_new, c_new)
    

#We know a analytical OZ solution for hard sphere particles and Percus Yevick closure 
#********************************************************************************************************
def analyticalRDFsolutionForHS():
    sigma = hardSphereRadius
    r = Delta_r*np.arange(numberOfRadialSamplingPoints).astype('float')
    c = np.zeros(numberOfRadialSamplingPoints).astype('float')
    c[hardSphereRadiusInPoints:] = 0.0 #Not needed (c = np.zeros), just to emphasize definition of c (c = 0 for r > sigma)
    r_HSR = r[:hardSphereRadiusInPoints]
    c[:hardSphereRadiusInPoints] = ( 6.0*rho_V*(1.0 + 0.5*rho_V)**2*(r_HSR/sigma) - (1.0 + 2.0*rho_V)**2*(1 + 0.5*rho_V*(r_HSR/sigma)**3) ) / (1.0 - rho_V)**4
    c_hat = hankelTransform(c, Delta_r)
    G_hat = c_hat/(1.0 - rho*c_hat) - c_hat
    G = inverseHankelTransform(G_hat, Delta_r)
    g = G + c + 1.0
    g[:hardSphereRadiusInPoints] = 0.0
    return g
    

    
#Start here
#*******************************************************************************************************************************************************************
def Iq(q, intercept, slope):
    #Working Examples:
    #*****************************************************
    #python PicardOZ.py
    #python PicardOZ.py -l
    #python PicardOZ.py -l -n
    #python PicardOZ.py -l -e 0.2
    #python PicardOZ.py -l -d 0.3 -e 0.6
    #Mimicking ideal gas:
    #python PicardOZ.py -l -e 0
    #For rho -> 0, the pair correlation equals e^{-beta U}
    #python PicardOZ.py -d 0    #Boltzmann of HS
    #python PicardOZ.py -l -d 0 #Boltzmann of LJ
    #Failing example:
    #python PicardOZ.py -l -d 0.3 -e 1.0
    #python PicardOZ.py -l -d 0.7 -e 0.2
    #Do a unit Test:
    #python PicardOZ.py -u  -d 0.3
    #*******************************************************
    
    #LJ or hard sphere potential?
    if parameters["potential"] == 0:
        isLennardJonesPotential = "True"
    #Which closure relation was chosen? (Default PY)
    if parameters["closure"] == 0:
        isHNC = "True"
    #Should we compare with analytical solution? The unit test to work is a strong indication
    #that the numerical result is true. The only flaw of the comparison is that the same operators are used
    #as for the fixpoint problem (Hankel transform and its inverse). Hence this part is not independent of
    #what we want to check against.

    #We read the potential depth (also for HS)
    epsilonInkTUnits = parameters["energy"] #epsilon/kT = epsilon*beta
    rho_V = parameters["density"]

    #We transform the volume density into the mandatory particle
    #number density. The term 'hardSphereRadius' is not fully consistent,
    #since the 'hardSphereRadius' as in the code is actually the
    #'hardSphereDiameter', since 2 particles must be separated at least by 
    #2*r_hs. This is why the factor 0.5 is introduced bellow in V_atom.
    rho = rho_V/( (4*np.pi/3.0)*(0.5*hardSphereRadius)**3 ) #rho_V = rho*V_atom 
    numberOfIterations = 10000; #Same upper bound as in SASfit (Ten thousand)

    #Set up Potential according parsed data
    #****************************************************************

    #ideal Gas
    #**********
    boltzmannOfP2Ppotential = np.ones(numberOfRadialSamplingPoints)

    #Hard Sphere
    #***********
    #beta = 1.0 #not needed for hard spheres
    boltzmannOfP2Ppotential[:hardSphereRadiusInPoints] = 0.0

    #Lennard Jones
    #*************
    sigma = hardSphereRadius
    r = Delta_r*(np.arange(numberOfRadialSamplingPoints).astype('float') + 1.0)
    potential_LJ = (sigma/r)**12 - (sigma/r)**6
    #Since Potential so far is unitless, we also want this for the energy
    #hence we express epsilon (energy scale of potential) in kT unit
    #binding energy. For e.g. liquid Argon: e/k ~ 120 K, e/(kT) ~ 1.2
    #(http://www.sklogwiki.org/SklogWiki/index.php/Argon)
    potential_LJ *= 4.0*epsilonInkTUnits
    #pl.plot(potential_LJ[hardSphereRadius -2:]); pl.show()
    if isLennardJonesPotential:
        boltzmannOfP2Ppotential = np.exp(-potential_LJ)
    #boltzmannOfP2Ppotential[0] = 0.0 #exp(-inf), we start at Delta_r
    
    #Plot exp(-beta*U)
    #pl.plot(boltzmannOfP2Ppotential, label = 'exp(-beta u)'); pl.legend(); pl.show()

    #Potential defined, start Picard iteration. 
    #*************************************************************************
    t_start = time.time()
    
    G_0 = np.zeros(numberOfRadialSamplingPoints)
    #Start with Gamma = 0
    G_fp = G_0
    #Simple Picard iteration, if algorithm did not converge
    #after 10000 steps, it is unlikely to converge at all. Since the
    #application of the fix point operator is so cheap, we don't
    #bother about a stoping criterion.
    for i in range(numberOfIterations):
      (G_fp, c_fp) = fixPointOperatorForGamma(G_fp)
      

    t_stop = time.time()
    print "time used for", numberOfIterations, "iterations:", t_stop - t_start, " sec" 
    print "time used for one OZ step:", 1000.0*(t_stop - t_start)/float(numberOfIterations), "milliseconds" 
    
    #Calculate S(q) as well (outside the Picard loop, from a math point of view
    #this can be done since the operator C2S transforming c to Sq is continuous, 
    #(Hankel transform is continuous and 1.0/(1.0-rho*c_hat) is continuous, but mind the pole. Hence
    #lim C2S(c_n) -> C2S(c) = Sq for c_n -> c, such that bellow should be valid
    c_hat_fp = hankelTransform(c_fp, Delta_r)
    Sq = 1.0/(1.0-rho*c_hat_fp)
    return Sq

