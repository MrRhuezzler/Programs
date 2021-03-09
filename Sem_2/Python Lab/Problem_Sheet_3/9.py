# Write a program that generates 100 random integers that are either 0 or 1.
# Then find the longest run of zeros, the largest number of zeros in a row. For
# instance, the longest run of zeros in [1,0,1,1,0,0,0,0,1,0,0] is 4.

from random import random as rand

li = [0 if rand() > .5 else 1 for _ in range(100)]
longestZeros = 0
currentZeros = 0
for i in range(len(li)):
    if li[i] == 1:
        if(longestZeros < currentZeros):
            longestZeros = currentZeros

        currentZeros = 0
    else:
        currentZeros += 1

if(longestZeros < currentZeros):
    longestZeros = currentZeros

for i in range(len(li)):
    if i % 20 == 0 and i != 0:
        print()
    
    print(li[i], end=", ")

print()
print("Longest Zero Line : ", longestZeros)