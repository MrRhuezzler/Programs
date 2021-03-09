# Write a program to find the sum of the first n natural numbers (created using range)
# where the value of n is provided by the user.

n = int(input("Enter n : "))
print(f"Sum of {n} natural numbers : ", sum(range(1, n + 1)))