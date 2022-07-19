import numpy as np

def GJREF(matrix):
    # Gauss Jordan Elimination -> RREF

    matrix = np.copy(matrix)
    j = 0
    for row, i in enumerate(matrix):

        if j >= len(matrix[row]):
            break

        # Make it 1
        divideBy = i[j]
        if divideBy != 0:
            matrix[row] = matrix[row] / divideBy

            # Make Others 0
            for _row, _i in enumerate(matrix):
                if _row != row:
                    matrix[_row] = matrix[_row] - _i[j] * matrix[row]

        j += 1
    print(matrix)

a = GJREF(np.array([[1,2,3],[0,0,1],[0,0,0],[0,0,0]]))
