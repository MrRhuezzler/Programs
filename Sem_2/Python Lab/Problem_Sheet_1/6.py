# Write a program to convert a given temperature in Celsius to
# Fahrenheit and vice versa.

CtoF = lambda x: (x * (9 / 5)) + 32
FtoC = lambda x: (x - 32) * (5/9)

temperature = float(input("Enter the temperature to convert : "))
choice = input("To Fahrenheit(f) or Celsius(c) : ").lower()
print("Answer : ", CtoF(temperature) if choice == 'f' else FtoC(temperature))