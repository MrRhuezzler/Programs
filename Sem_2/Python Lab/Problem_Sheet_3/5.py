# Write a program that asks the user for an integer and creates a list that
# consists of the factors of that integer.

num = int(input("Enter a number : "))
print(list(filter(lambda x : num % x == 0, [x for x in range(1, num + 1)])))