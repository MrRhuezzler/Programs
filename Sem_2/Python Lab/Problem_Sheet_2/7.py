# Create a list of names of the students in the class. Create another list to store their
# corresponding ages. Print the minimum age and maximum age of the students along
# with their names.

studName = []
studAge = []

while True:
    name = input('Enter Name : ')
    studName.append(name)

    age = int(input('Enter Age : '))
    studAge.append(age)

    choice = input('Do you want to continue (y / n) (y) : ')
    if choice == 'n':
        break

minAge = float('inf')
minAgeName = None
for name, age in zip(studName, studAge):
    if age < minAge:
        minAge = age
        minAgeName = name

print(f"\nMinimum Age\nName : {minAgeName}\nAge : {minAge}")