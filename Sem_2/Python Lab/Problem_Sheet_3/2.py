# Ask the user to enter a list of strings. Create a new list that consists of those
# strings with their first characters removed.

userInput = input("Enter some words (seperated by spaces) : ").split(" ")
userInputFrstRemoved = [x[1:] for x in userInput]
print(userInputFrstRemoved)