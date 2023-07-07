import numpy as np

a = np.array(
    [[-0.80,  0.51, -0.35,  0.00],
    [ 0.60,  0.82, -0.15,  0.00],
    [ 0.21, -0.32, -0.94,  0.00],
    [ 0.00,  0.00,  0.00,  1.00], ]
)
b = np.array(
    [[ 1.00,  0.00,  0.00, -3.25],
    [ 0.00,  1.00,  0.00,  3.50],
    [ 0.00,  0.00,  1.00,  27.7],
    [ 0.00,  0.00,  0.00,  1.00], ]
)

print(a)
print(b)
print(np.dot(a, b))
