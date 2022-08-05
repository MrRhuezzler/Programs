import numpy as np

# Matrix, Number of Iterations
def inversePowerIteration(_, __):
    ___ = np.linalg.inv(_)
    ____ = np.random.rand(_.shape[1])
    for _____ in range(__):
        ____ = np.dot(___, ____)
        ______ = np.linalg.norm(____)
        ____ = ____ / ______

    return ____

# Matrix, Number of Iterations
def powerIteration(_, __):
    # Initial Approximation
    ___ = np.random.rand(_.shape[1])
    
    # Update
    for ____ in range(__):
        ___ = np.dot(_, ___)
        _____ = np.linalg.norm(___)
        ___ = ___ / _____
    
    return ___


# Matrix, Eigen Vector
def rayleighQuotient(_, __):
    ___ = np.dot(np.dot(_, __), __)
    ____ = np.dot(__, __)
    return ___ / ____


def isDiagonalizable(A):
    a, P = np.linalg.eig(A)
    D = np.zeros(A.shape)
    for i in range(a.shape[0]):
        D[i][i] = a[i]
    AA = np.matmul(np.matmul(P, D), np.linalg.inv(P))
    return np.isclose(A, AA).all()

A = np.array([[2, -12], [1, -5]])

ieig = inversePowerIteration(A, 100)
eig = powerIteration(A, 100)

print(isDiagonalizable(A))


"""
print("Power Method")
print("Eigen Value:", rayleighQuotient(A, eig), "Eigen Vector:", eig)
print()
print("Inverse Power Method")
print("Eigen Value:", rayleighQuotient(A, ieig), "Eigen Vector:", ieig)
"""