# Write a program to swap two variables without using a third
# variable.

a = int(input("Enter A : "))
b = int(input("Enter B : "))

print("Before")
print(f"The value of A : {a}\nThe Value of B : {b}")

b, a = a, b

print("After")
print(f"The value of A : {a}\nThe Value of B : {b}")