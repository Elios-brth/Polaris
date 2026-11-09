import numpy as np
import matplotlib.pyplot as plt
import math
import os

position_x, position_y = np.loadtxt('positions.txt', delimiter=',', unpack=True)

plt.figure()
plt.plot(position_x, position_y, '-')