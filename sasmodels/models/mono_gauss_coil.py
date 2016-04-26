#mono_gauss_coil model
#conversion of DebyeModel.py
#converted by Steve King, Mar 2016



r"""
This Debye Gaussian coil model strictly describes the scattering from *monodisperse* polymer chains in theta solvents or polymer melts, conditions under which the distances between segments follow a Gaussian distribution. Provided the number of segments is large (ie, high molecular weight polymers) the single-chain form factor P(Q) is that described by Debye (1947).

To describe the scattering from *polydisperse* polymer chains see the :ref:`poly_gauss_coil <poly-gauss-coil>` model.

Definition
----------

     *I(q)* = *scale* |cdot| *I* \ :sub:`0` |cdot| *P(q)* + *background*

where

     *I*\ :sub:`0` = |phi|\ :sub:`poly` |cdot| *V* |cdot| (|rho|\ :sub:`poly` - |rho|\ :sub:`solv`)\  :sup:`2`

     *P(q)* = 2 [exp(-Z) + Z - 1] / Z \ :sup:`2`

     *Z* = (*q R* \ :sub:`g`)\ :sup:`2`

and

     *V* = *M* / (*N*\ :sub:`A` |delta|)

Here, |phi|\ :sub:`poly` is the volume fraction of polymer, *V* is the volume of a polymer coil, *M* is the molecular weight of the polymer, *N*\ :sub:`A` is Avogadro's Number, |delta| is the bulk density of the polymer, |rho|\ :sub:`poly` is the sld of the polymer, |rho|\ :sub:`solv` is the sld of the solvent, and *R*\ :sub:`g` is the radius of gyration of the polymer coil.

The 2D scattering intensity is calculated in the same way as the 1D, but where the *q* vector is redefined as

.. math::

    q = \sqrt{q_x^2 + q_y^2}

References
----------

P Debye, *J. Phys. Colloid. Chem.*, 51 (1947) 18.

R J Roe, *Methods of X-Ray and Neutron Scattering in Polymer Science*, Oxford University Press, New York (2000).

http://www.ncnr.nist.gov/staff/hammouda/distance_learning/chapter_28.pdf
"""

from numpy import inf, sqrt, exp

name =  "mono_gauss_coil"
title =  "Scattering from monodisperse polymer coils"

description =  """
    Evaluates the scattering from 
    monodisperse polymer chains.
    """
category =  "shape-independent"

#             ["name", "units", default, [lower, upper], "type", "description"],
parameters =  [["i_zero", "1/cm", 70.0, [0.0, inf], "", "Intensity at q=0"],
               ["radius_gyration", "Ang", 75.0, [0.0, inf], "", "Radius of gyration"]]

# NB: Scale and Background are implicit parameters on every model
def Iq(q, i_zero, radius_gyration):
    # pylint: disable = missing-docstring
    z = (q * radius_gyration) * (q * radius_gyration)
    if (q == 0).any():
       inten = i_zero
    else:
       inten = i_zero * 2.0 * (exp(-z) + z - 1.0 ) / (z * z)
    return inten
#Iq.vectorized = True # Iq accepts an array of q values

def Iqxy(qx, qy, *args):
    # pylint: disable = missing-docstring
    return Iq(sqrt(qx ** 2 + qy ** 2), *args)
#Iqxy.vectorized = True # Iqxy accepts an array of qx, qy values

demo =  dict(scale = 1.0,
            i_zero = 70.0,
            radius_gyration = 75.0,
            background = 0.0)

# these unit test values taken from SasView 3.1.2
tests =  [
    [{'scale': 1.0, 'i_zero': 70.0, 'radius_gyration': 75.0, 'background': 0.0},
     [0.0106939, 0.469418], [57.1241, 0.112859]],
    ]
