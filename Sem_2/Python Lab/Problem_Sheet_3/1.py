# Ask the user to enter a list containing numbers between 1 and 12. Then
# replace all of the entries in the list that are greater than 10 with 10.

userInput = input("Enter a list of numbers (separated by spaces): ").split(" ")
userInputList = list(map(int, userInput))
userInputList = [x if x < 10 else 10 for x in userInputList]
print(userInputList)
