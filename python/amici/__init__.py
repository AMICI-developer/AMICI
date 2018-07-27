""" @package amici 
The AMICI Python module (in doxygen this will also contain documentation about the C++ library)

The AMICI Python module provides functionality for importing SBML models and turning them into C++ Python extensions.

Getting started:
```
# creating a extension module for an SBML model:
import amici
amiSbml = amici.SbmlImporter('mymodel.sbml')
amiSbml.sbml2amici('modelName', 'outputDirectory')

# using the created module (set python path)
import modelName
help(modelName)
```

Attributes:
    dirname: absolute path to parent directory of this file
    amici_path: absolute root path of the amici repository
    amiciSwigPath: absolute path of the amici swig directory
    amiciSrcPath: absolute path of the amici source directory
    amiciModulePath: absolute root path of the amici module
    hdf5_enabled: boolean indicating if amici was compiled with hdf5 support
"""

import os
import numpy as np

# If this file is inside the amici package, import swig interface,
# otherwise we are inside the git repository, then don't
dirname = os.path.dirname(__file__)
hdf5_enabled = False
if os.path.isfile(os.path.join(dirname, 'amici.py')):
    try:
        from . import amici
        from .amici import *
        hdf5_enabled = True
    except AttributeError:
        from . import amici_without_hdf5 as amici
        from .amici_without_hdf5 import *

# determine package installation path, or, if used directly from git
# repository, get repository root
if os.path.exists(os.path.join(os.path.dirname(__file__), '..', '..', '.git')):
    amici_path = os.path.abspath(os.path.join(
        os.path.dirname(__file__), '..', '..'))
else:
    amici_path = os.path.dirname(__file__)

amiciSwigPath = os.path.join(amici_path, 'swig')
amiciSrcPath = os.path.join(amici_path, 'src')
amiciModulePath = os.path.dirname(__file__)

from .sbml_import import *


def runAmiciSimulation(model, solver, edata=None):
    """ Convenience wrapper around amici.runAmiciSimulation (generated by swig) 

    Arguments:
        model: Model instance
        solver: Solver instance, must be generated from Model.getSolver()
        edata: ExpData instance (optional)

    Returns:
        ReturnData object with simulation results

    Raises:
        
    """
    if edata and edata.__class__.__name__ == 'ExpDataPtr':
        edata = edata.get()

    rdata = amici.runAmiciSimulation(solver.get(), edata, model.get())
    return rdataToNumPyArrays(rdata)


def rdataToNumPyArrays(rdata):
    """ Convenience wrapper ReturnData class (generated by swig) 

    Arguments:
        rdata: ReturnData instance with simulation results

    Returns:
        ReturnData object with numpy array fields

    Raises:
        
    """
    npReturnData = {}
    fieldNames = ['t', 'x', 'x0', 'sx', 'sx0', 'y', 'sigmay', 'sy', 'ssigmay', 
                  'z', 'rz', 'sigmaz', 'sz', 'srz', 'ssigmaz', 'sllh', 's2llh', 
                  'J', 'xdot', 'status', 'llh', 'chi2', 'res', 'sres', 'FIM',
                  'newton_numlinsteps', 'newton_numsteps', 
                  'numsteps', 'numrhsevals', 'numerrtestfails', 'numnonlinsolvconvfails', 
                  'order', 'numstepsB', 'numrhsevalsB', 'numerrtestfailsB', 'numnonlinsolvconvfailsB']

    for field in fieldNames:
        npReturnData[field] = getFieldAsNumPyArray(rdata, field)

    return npReturnData


def getFieldAsNumPyArray(rdata, field):
    """ Convert ReturnData field to numpy array with dimensions according to model dimensions in rdata

    Arguments:
        rdata: ReturnData instance with simulation results
        field: Name of field

    Returns:
        Field Data as numpy array with dimensions according to model dimensions in rdata

    Raises:
        
    """

    fieldDimensions = {'ts':  [rdata.nt],
                       'x':   [rdata.nt, rdata.nx],
                       'x0':  [rdata.nx],
                       'sx':  [rdata.nt, rdata.nplist, rdata.nx],
                       'sx0': [rdata.nplist, rdata.nx],
                       
                       # observables
                       'y':       [rdata.nt, rdata.ny],
                       'sigmay':  [rdata.nt, rdata.ny],
                       'sy':      [rdata.nt, rdata.nplist, rdata.ny],
                       'ssigmay': [rdata.nt, rdata.nplist, rdata.ny],
                       
                       # event observables
                       'z':       [rdata.nmaxevent, rdata.nz],
                       'rz':      [rdata.nmaxevent, rdata.nz],
                       'sigmaz':  [rdata.nmaxevent, rdata.nz],
                       'sz':      [rdata.nmaxevent, rdata.nplist, rdata.nz],
                       'srz':     [rdata.nmaxevent, rdata.nplist, rdata.nz],
                       'ssigmaz': [rdata.nmaxevent, rdata.nplist, rdata.nz],

                       # objective function
                       'sllh':  [rdata.nplist],
                       's2llh': [rdata.np, rdata.nplist],

                       'res':   [rdata.nt * rdata.nytrue],
                       'sres':  [rdata.nt * rdata.nytrue, rdata.nplist],
                       'FIM':   [rdata.nplist, rdata.nplist],
                       
                       # diagnosis
                       'J':                       [rdata.nx, rdata.nx],
                       'xdot':                    [rdata.nx],
                       'newton_numlinsteps':      [rdata.newton_maxsteps, 2],
                       'newton_numsteps':         [1, 2],
                       'numsteps':                [rdata.nt],
                       'numrhsevals':             [rdata.nt],
                       'numerrtestfails':         [rdata.nt],
                       'numnonlinsolvconvfails':  [rdata.nt],
                       'order':                   [rdata.nt],
                       'numstepsB':               [rdata.nt],
                       'numrhsevalsB':            [rdata.nt],
                       'numerrtestfailsB':        [rdata.nt],
                       'numnonlinsolvconvfailsB': [rdata.nt],
                       }
    if field == 't':
        field = 'ts'

    attr = getattr(rdata, field)
    if field in fieldDimensions.keys():
        if len(attr) == 0:
            return None
        else:
            return stdVec2ndarray(attr, *fieldDimensions[field]).copy()
    else:
        return float(attr)
