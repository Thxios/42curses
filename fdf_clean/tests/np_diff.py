
import numpy as np


a = np.array([
    [1, 2, 0, 3],
    [-1, 0, 0, 0],
    [0, -3, 0, 0],
    [-1, 1, 0, 1],
])
b = np.array([
	[0, 3, -2, -1],
	[1, 2, 0, -3],
	[2, 1, -1, 0],
	[3, 0, 0, -1],
])

v = np.array([1, -4, 3, -1])

print(np.dot(a, b))
print(np.dot(a, v))
