# Write a program to compute the salary of an employee. The user is
# prompted to enter the Basic Salary. Dearness Allowance (DA) is 120%
# of Basic and City Compensatory Allowance (CCA) is 20% of Basic.
# Total salary is Basic + DA + CCA.

salary = float(input("Enter the Salary : "))
da = salary * 1.2
cca = salary * 0.2
print(f"DA : {da}\nCCA : {cca}\nBasic : {salary + da + cca}")
