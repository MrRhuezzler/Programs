import numpy as np

def getInput():
    noOfUnknowns = int(input("No. of Unknowns: "))
    noOfEqns = int(input("No. of Equations: "))
    
    equations = []
    
    print("----")
    for i in range(noOfEqns):
        print(f"Inputing Equation {i + 1}")
        coeffs = []
        for j in range(noOfUnknowns):
            coeffs.append(float(input(f"Co-eff of X{j + 1} : ")))
        coeffs.append(float(input(f"Constant : ")))
        equations.append(coeffs)
        print("----")

    return np.array(equations)

def checkREF(matrix):
    currentOne = 0
    for i in matrix:
        oneFound = False
        for index, j in enumerate(i):

            if j == 0:
                continue

            if not oneFound and j != 1:
                return False

            if currentOne <= index:
                currentOne = index
                oneFound = True
                continue
            else:
                return False

        else:
            if not oneFound:
                currentOne = j

    return True
