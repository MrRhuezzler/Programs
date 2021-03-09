# Write a program to calculate the cost per square inch of a circular pizza, given its
# diameter and price.

PI = 3.14159
diameter = float(input("Enter the diameter (in) : "))
price = float(input("Enter the price : "))

radius = diameter / 2
print("Cost per sq inch of pizza : ", price / (radius * radius * PI))