#!/usr/bin/env python3

"""
Generate coverage reports for the testModels and testSBML scripts
exported format is cobertura xml
"""

import coverage
import unittest
import os
import sys
import amici

import testModels
import testSBML

# only consider amici module and ignore the swig generated amici.py
cov = coverage.Coverage(source=['amici'],omit=['*/amici.py','*/amici_without_hdf5.py'])

# ignore code blocks containing import statements
cov.exclude('import')
cov.start()

# build the testSuite from testModels and testSBML
suite = unittest.TestSuite()
suite.addTest(testModels.TestAmiciPregeneratedModel())
suite.addTest(testSBML.TestAmiciSBMLModel())
testRunner = unittest.TextTestRunner(verbosity=0)
result = testRunner.run(suite)

cov.stop()
cov.xml_report(outfile='coverage_py_tmp.xml')
libdir = os.path.dirname(os.path.dirname(amici.__file__))

with open("coverage_py_tmp.xml", "rt") as fin:
    with open("coverage_py.xml", "wt") as fout:
        for line in fin:
            fout.write(line.replace(libdir, 'python'))
os.remove("coverage_py_tmp.xml")

# propagate failure
sys.exit(not result.wasSuccessful())