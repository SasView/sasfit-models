r"""
This model provides the form factor, $P(q)$, for a core shell ellipsoid (below)
where the form factor is normalized by the volume of the outer [CHECK].

.. math::

    P(q) = scale * \left<f^2\right>/V + background

where the volume $V = (4/3)\pi(R_{major\_outer}R_{minor\_outer}^2)$ and the averaging $< >$ is
applied over all orientations for 1D.

.. figure:: img/core_shell_ellipsoid_geometry.png

    The returned value is in units of $cm^{-1}$, on absolute scale.

Definition
----------

The form factor calculated is

.. math::

    P(q) = \frac{scale}{V}\int_0^1
        \left|F(q,r_{minor\_core},r_{major\_core},\alpha) + F(q,r_{major\_outer},r_{major\_outer},\alpha)\right|^2d\alpha + background

    \left|F(q,r_{minor},r_{major},\alpha)\right|=(4\pi/3)r_{major}r_{minor}^2 \Delta \rho \cdot (3j_1(u)/u)

    u = q\left[ r_{major}^2\alpha ^2 + r_{minor}^2(1-\alpha ^2)\right]^{1/2}

where

.. math::

    j_1(u)=(\sin x - x \cos x)/x^2

To provide easy access to the orientation of the core-shell ellipsoid,
we define the axis of the solid ellipsoid using two angles $\theta$ and $\phi$.
These angles are defined as for
:ref:`cylinder orientation <cylinder-angle-definition>`.
The contrast is defined as SLD(core) - SLD(shell) and SLD(shell) - SLD(solvent).

In the parameters, *equat_core* = equatorial core radius, *polar_core* =
polar core radius, *equat_shell* = $r_{min}$ (or equatorial outer radius),
and *polar_shell* = $r_{maj}$ (or polar outer radius).

Note:It is the users' responsibility to ensure that shell radii are larger than 
the core radii, especially if both are polydisperse, in which case the
core_shell_ellipsoid_xt model may be much better.


.. note::
    The 2nd virial coefficient of the solid ellipsoid is calculated based on
    the *radius_a* (= *polar_shell)* and *radius_b (= equat_shell)* values,
    and used as the effective radius for *S(Q)* when $P(Q) * S(Q)$ is applied.

.. figure:: img/core_shell_ellipsoid_angle_projection.jpg

    The angles for oriented core_shell_ellipsoid.

Our model uses the form factor calculations implemented in a c-library provided
by the NIST Center for Neutron Research (Kline, 2006).

References
----------

M Kotlarchyk, S H Chen, *J. Chem. Phys.*, 79 (1983) 2461

S J Berr, *Phys. Chem.*, 91 (1987) 4760

"""

from numpy import inf, sin, cos, pi

name = "core_shell_ellipsoid"
title = "Form factor for an spheroid ellipsoid particle with a core shell structure."
description = """
    [SpheroidCoreShellModel] Calculates the form factor for an spheroid
    ellipsoid particle with a core_shell structure.
    The form factor is averaged over all possible
    orientations of the ellipsoid such that P(q)
    = scale*<f^2>/Vol + bkg, where f is the
    single particle scattering amplitude.
    [Parameters]:
    equat_core = equatorial radius of core, Rminor_core,
    polar_core = polar radius of core, Rmajor_core,
    equat_shell = equatorial radius of shell, Rminor_outer,
    polar_shell = polar radius of shell, Rmajor_outer,
    sld_core = scattering length density of core,
    sld_shell = scattering length density of shell,
    sld_solvent = scattering length density of solvent,
    background = Incoherent bkg
    scale =scale
    Note:It is the users' responsibility to ensure
    that shell radii are larger than core radii,
    especially if both are polydisperse.
    oblate: polar radius < equatorial radius
    prolate :  polar radius > equatorial radius
    """
category = "shape:ellipsoid"

single = False  # TODO: maybe using sph_j1c inside gfn would help?
# pylint: disable=bad-whitespace, line-too-long
#             ["name", "units", default, [lower, upper], "type", "description"],
parameters = [
    ["equat_core",  "Ang",      200,   [0, inf],    "volume",      "Equatorial radius of core, Rminor_core "],
    ["polar_core",  "Ang",       10,   [0, inf],    "volume",      "Polar radius of core, Rmajor_core"],
    ["equat_shell", "Ang",      250,   [0, inf],    "volume",      "Equatorial radius of shell, Rminor_outer "],
    ["polar_shell", "Ang",       30,   [0, inf],    "volume",      "Polar radius of shell, Rmajor_outer"],
    ["sld_core",    "1e-6/Ang^2", 2,   [-inf, inf], "sld",            "Core scattering length density"],
    ["sld_shell",   "1e-6/Ang^2", 1,   [-inf, inf], "sld",            "Shell scattering length density"],
    ["sld_solvent", "1e-6/Ang^2", 6.3, [-inf, inf], "sld",            "Solvent scattering length density"],
    ["theta",       "degrees",    0,   [-inf, inf], "orientation", "Oblate orientation wrt incoming beam"],
    ["phi",         "degrees",    0,   [-inf, inf], "orientation", "Oblate orientation in the plane of the detector"],
    ]
# pylint: enable=bad-whitespace, line-too-long

source = ["lib/sph_j1c.c", "lib/gfn.c", "lib/gauss76.c", "core_shell_ellipsoid.c"]

def ER(equat_core, polar_core, equat_shell, polar_shell):
    """
        Returns the effective radius used in the S*P calculation
    """
    import numpy as np
    from .ellipsoid import ER as ellipsoid_ER
    return ellipsoid_ER(polar_shell, equat_shell)


demo = dict(scale=1, background=0.001,
            equat_core=200.0,
            polar_core=10.0,
            equat_shell=250.0,
            polar_shell=30.0,
            sld_core=2.0,
            sld_shell=1.0,
            sld_solvent=6.3,
            theta=0,
            phi=0)

q = 0.1
phi = pi/6
qx = q*cos(phi)
qy = q*sin(phi)

tests = [
    # Accuracy tests based on content in test/utest_other_models.py
    [{'equat_core': 200.0,
      'polar_core': 20.0,
      'equat_shell': 250.0,
      'polar_shell': 30.0,
      'sld_core': 2.0,
      'sld_shell': 1.0,
      'sld_solvent': 6.3,
      'background': 0.001,
      'scale': 1.0,
     }, 1.0, 0.00189402],

    # Additional tests with larger range of parameters
    [{'background': 0.01}, 0.1, 8.86741],

    [{'equat_core': 20.0,
      'polar_core': 200.0,
      'equat_shell': 54.0,
      'polar_shell': 3.0,
      'sld_core': 20.0,
      'sld_shell': 10.0,
      'sld_solvent': 6.0,
      'background': 0.0,
      'scale': 1.0,
     }, 0.01, 26150.4],

    [{'background': 0.001}, (0.4, 0.5), 0.00170471],

    [{'equat_core': 20.0,
      'polar_core': 200.0,
      'equat_shell': 54.0,
      'polar_shell': 3.0,
      'sld_core': 20.0,
      'sld_shell': 10.0,
      'sld_solvent': 6.0,
      'background': 0.01,
      'scale': 0.01,
     }, (qx, qy), 0.105764],
    ]
