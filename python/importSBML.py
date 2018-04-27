#!/usr/bin/env python3

from model import Model
import os
import sys
import importlib
import numpy as np
sys.path.insert(0, "../build/swig/python/")
import amici

dirname = os.path.split(os.path.abspath(__file__))[0]
amici_path = os.path.split(dirname)[0]
test_path = os.path.join(amici_path,'tests','sbml-semantic-test-cases','cases','semantic')

def runTest(testId):
    try:
        current_test_path = os.path.join(test_path, testId)
        sbmlFile = os.path.join(current_test_path, testId + '-sbml-l3v2.xml')
        settingsFile = os.path.join(current_test_path, testId + '-settings.txt')
        resultsFile = os.path.join(current_test_path, testId + '-settings.txt')
        wrapper = Model(sbmlFile,'SBMLTest' + testId)
        wrapper.wrapModel()
        sys.path.insert(0,os.path.join(wrapper.model_path,'build','swig'))

        settings = {}
        with open(settingsFile) as f:
            for line in f:
                if not line == '\n':
                    (key, val) = line.split(':')
                    settings[key] = val
        ts = np.linspace(float(settings['start']),float(settings['start'])+float(settings['duration']),int(settings['steps']))
        atol = float(settings['absolute'])
        rtol = float(settings['relative'])

        mod = importlib.import_module(wrapper.modelname)
        model = mod.getModel()
        model.setTimepoints(mod.amici.DoubleVector(ts))
        solver = model.getSolver()
        solver.setRelativeTolerance(rtol)
        solver.setAbsoluteTolerance(atol)
        rdata = amici.runAmiciSimulation(solver.get(),None,model.get())
        print(rdata)




    except AssertionError:
        None

def getTestStr(testId):
    testStr = str(testId)
    testStr = '0'*(5-len(testStr)) + testStr
    return testStr


for testId in range(1,1781):
    runTest(getTestStr(testId))

#model = Model('/Users/F.Froehlich/Downloads/Speedy_v3_r403445_v1.sbml','speedy')
#model.wrapModel()