# Write a program that asks the user to enter an angle between -180 and 180. Using
# an expression with the modulo operator, convert the angle to its equivalent between
# 0 and 360.

angle = int(input("Enter Angle : "))
MOD = 360
print("Angle btw 0 and 360 : ", (angle % MOD + MOD) % MOD)