r"""
This model calculates the scattering from a gel structure,
but typically a physical rather than chemical network.
It is modeled as a sum of a low-q exponential decay (which happens to
give a functional form similar to Guinier scattering, so interpret with 
care) plus a Lorentzian at higher-q values. See also the gel_fit model.

Definition
----------

The scattering intensity I(q) is calculated as (Eqn. 5 from the reference)

.. math::

    I(q) = I_G(0)exp(-q^2\Xi ^2/2) + I_L(0)/(1+q^2\xi^2)

$\Xi$ is the length scale of the static correlations in the gel,
which can be attributed to the "frozen-in" crosslinks.
\ |xi|\  is the dynamic correlation length, which can be attributed to the
fluctuating polymer chains between crosslinks.
$I_G(0)$ and $I_L(0)$ are the scaling factors for each of these structures.
Think carefully about how these map to your particular system!

.. note::
    The peaked structure at higher $q$ values (Figure 2 from the reference)
    is not reproduced by the model. Peaks can be introduced into the model
    by summing this model with the PeakGaussModel function.

For 2D data the scattering intensity is calculated in the same way as 1D,
where the $q$ vector is defined as

.. math::

    q = \sqrt{q_x^2 + q_y^2}


References
----------

G Evmenenko, E Theunissen, K Mortensen, H Reynaers, *Polymer*,
42 (2001) 2907-2913

"""

from numpy import inf, sqrt, exp

name = "gauss_lorentz_gel"
title = "Gauss Lorentz Gel model of scattering from a gel structure"
description = """
            Class that evaluates a GaussLorentzGel model.

            I(q) = scale_g*exp(- q^2*Z^2 / 2)+scale_l/(1+q^2*z^2)
                    + background
            List of default parameters:
                scale_g = Gauss scale factor
                Z = Static correlation length
                scale_l = Lorentzian scale factor
                z = Dynamic correlation length
                background = Incoherent background
            """
category = "shape-independent"
# pylint: disable=bad-whitespace, line-too-long
#            ["name", "units", default, [lower, upper], "type", "description"],
parameters = [["gauss_scale_factor",   "",    100.0,  [-inf, inf], "", "Gauss scale factor"],
              ["static_cor_length",    "Ang", 100.0,  [0, inf],    "", "Static correlation length"],
              ["lorentz_scale_factor", "",     50.0,  [-inf, inf], "", "Lorentzian scale factor"],
              ["dynamic_cor_length",   "Ang",  20.0,  [0, inf],    "", "Dynamic correlation length"],
             ]
# pylint: enable=bad-whitespace, line-too-long

def Iq(q,
       gauss_scale_factor=100.0,
       static_cor_length=100.0,
       lorentz_scale_factor=50.0,
       dynamic_cor_length=20.0):
    """

    :param q:                    Input q-value
    :param gauss_scale_factor:   Gauss scale factor
    :param static_cor_length:    Static correlation length
    :param lorentz_scale_factor: Lorentzian scale factor
    :param dynamic_cor_length:   Dynamic correlation length
    :return:                     1-D intensity
    """

    term1 = gauss_scale_factor *\
            exp(-1.0*q*q*static_cor_length*static_cor_length/2.0)
    term2 = lorentz_scale_factor /\
            (1.0+(q*dynamic_cor_length)*(q*dynamic_cor_length))

    return term1 + term2

Iq.vectorized = True  # Iq accepts an array of q values


def Iqxy(qx, qy, *args):
    """
    :param qx:   Input q_x-value
    :param qy:   Input q_y-value
    :param args: Remaining aruments
    :return:     2-D intensity
    """

    return Iq(sqrt(qx**2 + qy**2), *args)

Iqxy.vectorized = True  # Iqxy accepts an array of qx, qy values


demo = dict(scale=1, background=0.1,
            gauss_scale_factor=100.0,
            static_cor_length=100.0,
            lorentz_scale_factor=50.0,
            dynamic_cor_length=20.0)

oldname = "GaussLorentzGelModel"

oldpars = dict(background='background',
               gauss_scale_factor='scale_g',
               static_cor_length='stat_colength',
               lorentz_scale_factor='scale_l',
               dynamic_cor_length='dyn_colength')

tests = [

    # Accuracy tests based on content in test/utest_extra_models.py
    [{'gauss_scale_factor':  100.0,
      'static_cor_length':   100.0,
      'lorentz_scale_factor': 50.0,
      'dynamic_cor_length':   20.0,
     }, 0.001, 149.482],

    [{'gauss_scale_factor':  100.0,
      'static_cor_length':   100.0,
      'lorentz_scale_factor': 50.0,
      'dynamic_cor_length':   20.0,
     }, 0.105363, 9.1913],

    [{'gauss_scale_factor':  100.0,
      'static_cor_length':   100.0,
      'lorentz_scale_factor': 50.0,
      'dynamic_cor_length':   20.0,
     }, 0.441623, 0.633811],

    # Additional tests with larger range of parameters
    [{'gauss_scale_factor':  10.0,
      'static_cor_length':  100.0,
      'lorentz_scale_factor': 3.0,
      'dynamic_cor_length':   1.0,
     }, 0.1, 2.9712970297],

    [{'gauss_scale_factor':  10.0,
      'static_cor_length':  100.0,
      'lorentz_scale_factor': 3.0,
      'dynamic_cor_length':   1.0,
      'background':         100.0
     }, 5.0, 100.116384615],

    [{'gauss_scale_factor':  10.0,
      'static_cor_length':  100.0,
      'lorentz_scale_factor': 3.0,
      'dynamic_cor_length':   1.0,
      'background':           0.0,
     }, 200., 7.49981250469e-05],
    ]
