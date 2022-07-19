import numpy as np

def checkREF(matrix, with_pivots=False):
    pivots = []
    currentOne = 0
    for row, i in enumerate(matrix):
        oneFound = False
        for col, j in enumerate(i):

            if j == 0:
                continue

            if not oneFound and j != 1:
                return False, pivots if with_pivots else False
            
            if currentOne <= col:
                pivots.append((row, col))
                currentOne = col
                oneFound = True
                break
            else:
                return False, pivots if with_pivots else False

        else:
            if not oneFound:
                currentOne = j

    return True, pivots if with_pivots else True

def checkRREF(matrix):
    ok, pivots = checkREF(matrix, True)
    if ok:
        for row, col in pivots:
            if sum(matrix[:, col]) != 1:
                return False
        return True
    return False

