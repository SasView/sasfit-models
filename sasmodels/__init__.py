"""
sasmodels
=========

**sasmodels** is a package containing models for small angle neutron and xray
scattering.  Models supported are the one dimensional circular average and
two dimensional oriented patterns.  As well as the form factor calculations
for the individual shapes **sasmodels** also provides automatic shape
polydispersity, angular dispersion and resolution convolution.  SESANS
patterns can be computed for any model.

Models can be written in python or in C.  C models can run on the GPU if
OpenCL drivers are available.  See :mod:`generate` for details on
defining new models.
"""
__version__ = "0.9"

def data_files():
    """
    Return the data files to be installed with the package.

    The format is a list of (directory, [files...]) pairs which can be
    used directly in setup(...,data_files=...) for setup.py.
    """
    from os.path import join as joinpath
    from .generate import SIBLING_DIR, DATA_PATH
    data_files = {}
    def add_patterns(path, patterns):
        data_files[joinpath(SIBLING_DIR, *path)] \
            = [joinpath(DATA_PATH, *(path+[p])) for p in patterns]
    add_patterns([], ['*.c', '*.cl', 'convert.json'])
    add_patterns(['models'], ['*.c'])
    add_patterns(['models', 'lib'], ['*.c'])

    return data_files

