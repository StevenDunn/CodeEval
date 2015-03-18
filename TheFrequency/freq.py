# the frequency soln in py for code eval by steven a dunn

import sys
from numpy.fft import fft
import matplotlib.pyplot as plt

f = open(sys.argv[1], 'r')

for line in f:
    samples = line.strip().split()
    samples = [int(x) for x in samples]

    # get the Fast Fourier Transform
    sampleMean = sum(samples)/len(samples)
    detrendSamples = [entry - sampleMean for entry in samples]
    transformedSignal = abs(fft(detrendSamples))

    # get the frequency
    maxVal = max(transformedSignal)
    maxIdx = [i for i, j in enumerate(transformedSignal) if j == maxVal]
    print maxIdx

    samplingFrequency = 20000
    frequency = int(maxIdx[0]) * samplingFrequency / len(transformedSignal)
    print frequency
f.close()