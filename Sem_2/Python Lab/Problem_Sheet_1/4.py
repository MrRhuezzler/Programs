# Write a program to accept the name of an employee, age and salary.
# Name should be a string; age should be an integer and salary a float
# value.
# a. Display them in a single line.
# b. Display them in a single line without space (+)
# Check the output and do proper modifications

employees = []
n = int(input("Enter the number of entries : "))

for i in range(n):
    employee = {}
    print(f"{i + 1})")
    employee['name'] = input('Enter the name of the employee : ')
    employee['age'] = int(input('Enter the age of the employee : '))
    employee['salary'] = float(input('Enter the salary of the employee : '))
    employees.append(employee)

print("--- Employee Details ---")
for index, employee in enumerate(employees):
    print(f"{index + 1})")
    print(f"Name   : {employee['name']}")
    print(f"Age    : {employee['age']}")
    print(f"Salary : {employee['salary']}")