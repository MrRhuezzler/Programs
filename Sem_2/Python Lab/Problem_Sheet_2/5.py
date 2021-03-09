# Write a program to determine the length of a ladder required to reach a given height
# when leaned against a house. The height and angle of the ladder are given as inputs.
# To compute length use

# Note: The angle must be in radians. If received in radians also, it should be
# converted to degrees. use import math and use math.sin() function.

import math

heightToBeReached = float(input('Height to be reached : '))
angle = float(input("Angle of the ladder : "))
mode = int(input('Radians(0) or Degree(1) : '))

if mode:
    angle = angle * (math.pi / 180)

print("Length of the ladder : ", heightToBeReached / (math.sin(angle)))