"""
Sasview model constructor.

Given a module defining an OpenCL kernel such as sasmodels.models.cylinder,
create a sasview model class to run that kernel as follows::

    from sasmodels.sasview_model import load_custom_model
    CylinderModel = load_custom_model('sasmodels/models/cylinder.py')
"""
from __future__ import print_function

import math
from copy import deepcopy
import collections
import traceback
import logging

import numpy as np

from . import core
from . import custom
from . import generate

try:
    from typing import Dict, Mapping, Any, Sequence, Tuple, NamedTuple, List, Optional
    from .kernel import KernelModel
    MultiplicityInfoType = NamedTuple(
        'MuliplicityInfo',
        [("number", int), ("control", str), ("choices", List[str]),
         ("x_axis_label", str)])
except ImportError:
    pass

# TODO: separate x_axis_label from multiplicity info
# The x-axis label belongs with the profile generating function
MultiplicityInfo = collections.namedtuple(
    'MultiplicityInfo',
    ["number", "control", "choices", "x_axis_label"],
)

MODELS = {}
def find_model(modelname):
    # TODO: used by sum/product model to load an existing model
    # TODO: doesn't handle custom models properly
    if modelname.endswith('.py'):
        return load_custom_model(modelname)
    elif modelname in MODELS:
        return MODELS[modelname]
    else:
        raise ValueError("unknown model %r"%modelname)

def load_standard_models():
    """
    Load and return the list of predefined models.

    If there is an error loading a model, then a traceback is logged and the
    model is not returned.
    """
    models = []
    for name in core.list_models():
        try:
            MODELS[name] = _make_standard_model(name)
            models.append(MODELS[name])
        except Exception:
            logging.error(traceback.format_exc())
    return models


def load_custom_model(path):
    """
    Load a custom model given the model path.
    """
    #print("load custom model", path)
    kernel_module = custom.load_custom_kernel_module(path)
    try:
        model = kernel_module.Model
    except AttributeError:
        model_info = generate.make_model_info(kernel_module)
        model = _make_model_from_info(model_info)
    MODELS[model.name] = model
    return model


def _make_standard_model(name):
    """
    Load the sasview model defined by *name*.

    *name* can be a standard model name or a path to a custom model.

    Returns a class that can be used directly as a sasview model.
    """
    kernel_module = generate.load_kernel_module(name)
    model_info = generate.make_model_info(kernel_module)
    return _make_model_from_info(model_info)


def _make_model_from_info(model_info):
    """
    Convert *model_info* into a SasView model wrapper.
    """
    model_info['variant_info'] = None  # temporary hack for older sasview
    def __init__(self, multiplicity=1):
        SasviewModel.__init__(self, multiplicity=multiplicity)
    attrs = _generate_model_attributes(model_info)
    attrs['__init__'] = __init__
    ConstructedModel = type(model_info['id'], (SasviewModel,), attrs)
    return ConstructedModel

def _generate_model_attributes(model_info):
    # type: (ModelInfo) -> Dict[str, Any]
    """
    Generate the class attributes for the model.

    This should include all the information necessary to query the model
    details so that you do not need to instantiate a model to query it.

    All the attributes should be immutable to avoid accidents.
    """
    attrs = {}  # type: Dict[str, Any]
    attrs['_model_info'] = model_info
    attrs['name'] = model_info['name']
    attrs['id'] = model_info['id']
    attrs['description'] = model_info['description']
    attrs['category'] = model_info['category']

    # TODO: allow model to override axis labels input/output name/unit

    #self.is_multifunc = False
    non_fittable = []  # type: List[str]
    variants = MultiplicityInfo(0, "", [], "")
    attrs['is_structure_factor'] = model_info['structure_factor']
    attrs['is_form_factor'] = model_info['ER'] is not None
    attrs['is_multiplicity_model'] = variants[0] > 1
    attrs['multiplicity_info'] = variants

    partype = model_info['partype']
    orientation_params = (
            partype['orientation']
            + [n + '.width' for n in partype['orientation']]
            + partype['magnetic'])
    magnetic_params = partype['magnetic']
    fixed = [n + '.width' for n in partype['pd-2d']]

    attrs['orientation_params'] = tuple(orientation_params)
    attrs['magnetic_params'] = tuple(magnetic_params)
    attrs['fixed'] = tuple(fixed)

    attrs['non_fittable'] = tuple(non_fittable)

    return attrs

class SasviewModel(object):
    """
    Sasview wrapper for opencl/ctypes model.
    """
    # Model parameters for the specific model are set in the class constructor
    # via the _generate_model_attributes function, which subclasses
    # SasviewModel.  They are included here for typing and documentation
    # purposes.
    _model = None       # type: KernelModel
    _model_info = None  # type: ModelInfo
    #: load/save name for the model
    id = None           # type: str
    #: display name for the model
    name = None         # type: str
    #: short model description
    description = None  # type: str
    #: default model category
    category = None     # type: str

    #: names of the orientation parameters in the order they appear
    orientation_params = None # type: Sequence[str]
    #: names of the magnetic parameters in the order they appear
    magnetic_params = None    # type: Sequence[str]
    #: names of the fittable parameters
    fixed = None              # type: Sequence[str]
    # TODO: the attribute fixed is ill-named

    # Axis labels
    input_name = "Q"
    input_unit = "A^{-1}"
    output_name = "Intensity"
    output_unit = "cm^{-1}"

    #: default cutoff for polydispersity
    cutoff = 1e-5

    # Note: Use non-mutable values for class attributes to avoid errors
    #: parameters that are not fitted
    non_fittable = ()        # type: Sequence[str]

    #: True if model should appear as a structure factor
    is_structure_factor = False
    #: True if model should appear as a form factor
    is_form_factor = False
    #: True if model has multiplicity
    is_multiplicity_model = False
    #: Mulitplicity information
    multiplicity_info = None # type: MultiplicityInfoType

    # Per-instance variables
    #: parameter {name: value} mapping
    params = None      # type: Dict[str, float]
    #: values for dispersion width, npts, nsigmas and type
    dispersion = None  # type: Dict[str, Any]
    #: units and limits for each parameter
    details = None     # type: Mapping[str, Tuple(str, float, float)]
    #: multiplicity used, or None if no multiplicity controls
    multiplicity = None     # type: Optional[int]

    def __init__(self, multiplicity):
        # type: () -> None
        #print("initializing", self.name)
        #raise Exception("first initialization")
        self._model = None

        ## _persistency_dict is used by sas.perspectives.fitting.basepage
        ## to store dispersity reference.
        self._persistency_dict = {}

        self.multiplicity = multiplicity

        self.params = collections.OrderedDict()
        self.dispersion = collections.OrderedDict()
        self.details = {}

        for p in self._model_info['parameters']:
            self.params[p.name] = p.default
            self.details[p.name] = [p.units] + p.limits

        for name in self._model_info['partype']['pd-2d']:
            self.dispersion[name] = {
                'width': 0,
                'npts': 35,
                'nsigmas': 3,
                'type': 'gaussian',
            }

    def __get_state__(self):
        state = self.__dict__.copy()
        state.pop('_model')
        # May need to reload model info on set state since it has pointers
        # to python implementations of Iq, etc.
        #state.pop('_model_info')
        return state

    def __set_state__(self, state):
        self.__dict__ = state
        self._model = None

    def __str__(self):
        """
        :return: string representation
        """
        return self.name

    def is_fittable(self, par_name):
        """
        Check if a given parameter is fittable or not

        :param par_name: the parameter name to check
        """
        return par_name in self.fixed
        #For the future
        #return self.params[str(par_name)].is_fittable()


    # pylint: disable=no-self-use
    def getProfile(self):
        """
        Get SLD profile

        : return: (z, beta) where z is a list of depth of the transition points
                beta is a list of the corresponding SLD values
        """
        return None, None

    def setParam(self, name, value):
        """
        Set the value of a model parameter

        :param name: name of the parameter
        :param value: value of the parameter

        """
        # Look for dispersion parameters
        toks = name.split('.')
        if len(toks) == 2:
            for item in self.dispersion.keys():
                if item == toks[0]:
                    for par in self.dispersion[item]:
                        if par == toks[1]:
                            self.dispersion[item][par] = value
                            return
        else:
            # Look for standard parameter
            for item in self.params.keys():
                if item == name:
                    self.params[item] = value
                    return

        raise ValueError("Model does not contain parameter %s" % name)

    def getParam(self, name):
        """
        Set the value of a model parameter

        :param name: name of the parameter

        """
        # Look for dispersion parameters
        toks = name.split('.')
        if len(toks) == 2:
            for item in self.dispersion.keys():
                if item == toks[0]:
                    for par in self.dispersion[item]:
                        if par == toks[1]:
                            return self.dispersion[item][par]
        else:
            # Look for standard parameter
            for item in self.params.keys():
                if item == name:
                    return self.params[item]

        raise ValueError("Model does not contain parameter %s" % name)

    def getParamList(self):
        """
        Return a list of all available parameters for the model
        """
        param_list = self.params.keys()
        # WARNING: Extending the list with the dispersion parameters
        param_list.extend(self.getDispParamList())
        return param_list

    def getDispParamList(self):
        """
        Return a list of polydispersity parameters for the model
        """
        # TODO: fix test so that parameter order doesn't matter
        ret = ['%s.%s' % (d, p)
               for d in self._model_info['partype']['pd-2d']
               for p in ('npts', 'nsigmas', 'width')]
        #print(ret)
        return ret

    def clone(self):
        """ Return a identical copy of self """
        return deepcopy(self)

    def run(self, x=0.0):
        """
        Evaluate the model

        :param x: input q, or [q,phi]

        :return: scattering function P(q)

        **DEPRECATED**: use calculate_Iq instead
        """
        if isinstance(x, (list, tuple)):
            # pylint: disable=unpacking-non-sequence
            q, phi = x
            return self.calculate_Iq([q * math.cos(phi)],
                                     [q * math.sin(phi)])[0]
        else:
            return self.calculate_Iq([float(x)])[0]


    def runXY(self, x=0.0):
        """
        Evaluate the model in cartesian coordinates

        :param x: input q, or [qx, qy]

        :return: scattering function P(q)

        **DEPRECATED**: use calculate_Iq instead
        """
        if isinstance(x, (list, tuple)):
            return self.calculate_Iq([float(x[0])], [float(x[1])])[0]
        else:
            return self.calculate_Iq([float(x)])[0]

    def evalDistribution(self, qdist):
        r"""
        Evaluate a distribution of q-values.

        :param qdist: array of q or a list of arrays [qx,qy]

        * For 1D, a numpy array is expected as input

        ::

            evalDistribution(q)

          where *q* is a numpy array.

        * For 2D, a list of *[qx,qy]* is expected with 1D arrays as input

        ::

              qx = [ qx[0], qx[1], qx[2], ....]
              qy = [ qy[0], qy[1], qy[2], ....]

        If the model is 1D only, then

        .. math::

            q = \sqrt{q_x^2+q_y^2}

        """
        if isinstance(qdist, (list, tuple)):
            # Check whether we have a list of ndarrays [qx,qy]
            qx, qy = qdist
            partype = self._model_info['partype']
            if not partype['orientation'] and not partype['magnetic']:
                return self.calculate_Iq(np.sqrt(qx ** 2 + qy ** 2))
            else:
                return self.calculate_Iq(qx, qy)

        elif isinstance(qdist, np.ndarray):
            # We have a simple 1D distribution of q-values
            return self.calculate_Iq(qdist)

        else:
            raise TypeError("evalDistribution expects q or [qx, qy], not %r"
                            % type(qdist))

    def calculate_Iq(self, *args):
        """
        Calculate Iq for one set of q with the current parameters.

        If the model is 1D, use *q*.  If 2D, use *qx*, *qy*.

        This should NOT be used for fitting since it copies the *q* vectors
        to the card for each evaluation.
        """
        if self._model is None:
            self._model = core.build_model(self._model_info)
        q_vectors = [np.asarray(q) for q in args]
        fn = self._model.make_kernel(q_vectors)
        pars = [self.params[v] for v in fn.fixed_pars]
        pd_pars = [self._get_weights(p) for p in fn.pd_pars]
        result = fn(pars, pd_pars, self.cutoff)
        fn.q_input.release()
        fn.release()
        return result

    def calculate_ER(self):
        """
        Calculate the effective radius for P(q)*S(q)

        :return: the value of the effective radius
        """
        ER = self._model_info.get('ER', None)
        if ER is None:
            return 1.0
        else:
            values, weights = self._dispersion_mesh()
            fv = ER(*values)
            #print(values[0].shape, weights.shape, fv.shape)
            return np.sum(weights * fv) / np.sum(weights)

    def calculate_VR(self):
        """
        Calculate the volf ratio for P(q)*S(q)

        :return: the value of the volf ratio
        """
        VR = self._model_info.get('VR', None)
        if VR is None:
            return 1.0
        else:
            values, weights = self._dispersion_mesh()
            whole, part = VR(*values)
            return np.sum(weights * part) / np.sum(weights * whole)

    def set_dispersion(self, parameter, dispersion):
        """
        Set the dispersion object for a model parameter

        :param parameter: name of the parameter [string]
        :param dispersion: dispersion object of type Dispersion
        """
        if parameter in self.params:
            # TODO: Store the disperser object directly in the model.
            # The current method of relying on the sasview gui to
            # remember them is kind of funky.
            self.dispersion[parameter] = dispersion.get_pars()
        else:
            raise ValueError("%r is not a dispersity or orientation parameter")

    def _dispersion_mesh(self):
        """
        Create a mesh grid of dispersion parameters and weights.

        Returns [p1,p2,...],w where pj is a vector of values for parameter j
        and w is a vector containing the products for weights for each
        parameter set in the vector.
        """
        pars = self._model_info['partype']['volume']
        return core.dispersion_mesh([self._get_weights(p) for p in pars])

    def _get_weights(self, par):
        """
        Return dispersion weights for parameter
        """
        from . import weights
        relative = self._model_info['partype']['pd-rel']
        limits = self._model_info['limits']
        dis = self.dispersion[par]
        value, weight = weights.get_weights(
            dis['type'], dis['npts'], dis['width'], dis['nsigmas'],
            self.params[par], limits[par], par in relative)
        return value, weight / np.sum(weight)


def test_model():
    """
    Test that a sasview model (cylinder) can be run.
    """
    Cylinder = _make_standard_model('cylinder')
    cylinder = Cylinder()
    return cylinder.evalDistribution([0.1,0.1])


def test_model_list():
    """
    Make sure that all models build as sasview models.
    """
    from .exception import annotate_exception
    for name in core.list_models():
        try:
            _make_standard_model(name)
        except:
            annotate_exception("when loading "+name)
            raise

if __name__ == "__main__":
    print("cylinder(0.1,0.1)=%g"%test_model())
