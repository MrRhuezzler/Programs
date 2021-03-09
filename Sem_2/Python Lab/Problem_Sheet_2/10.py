# Create a dictionary with roll number as the key and a set of 5 elective subjects as the
# value.

electives = dict()

while True:
    
    roll = input('Enter RollNo : ')
    electives[roll] = []

    print("Enter 5 Elective Subjects")
    for i in range(5):
        electives[roll].append(input(f"{i + 1}) "))

    choice = input('Do you want to continue (y / n) (y) : ')
    if choice == 'n':
        break

print(electives)