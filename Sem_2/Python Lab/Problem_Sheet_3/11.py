# Write a program that asks the user to enter a length in feet. The program
# should then give the user the option to convert from feet into inches, yards,
# miles, millimeters, centimeters, meters, or kilometers. Say if the user enters
# a 1, then the program converts to inches, if they enter a 2, then the program
# converts to yards, etc. While this can be done with if statements, it is much
# shorter with lists and it is also easier to add new conversions if you use lists.

conversions = [

    # Inches
    lambda x : x * 12,
    # Yards
    lambda x : x / 3,
    # Miles
    lambda x : x / 5280,
    # Millimeter
    lambda x : x * 305,
    # Centimeter
    lambda x : x * 30.48,
    # Meter
    lambda x : x / 3.281,
    # Kilometer
    lambda x : x / 3281

]

feet = float(input("Enter in feet : "))
print("1.inches\n2.yards\n3.miles\n4.millimeters\n5.centimeters\n6.meters\n7.kilometers")
to = int(input("Convert To : "))

while(to > len(conversions) or to <= 0):
    print("Enter a number between 1 and ", len(conversions))
    to = int(input("Convert To : "))

print("Converted : ", conversions[to - 1](feet))