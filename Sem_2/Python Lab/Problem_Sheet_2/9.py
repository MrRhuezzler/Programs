# In the game of Scrabble™, each letter has points associated with it. The total score
# of a word is the sum of the scores of its letters. More common letters are worth fewer
# points while less common letters are worth more points. The points associated with
# each letter are shown below:
# a. One point A, E, I, L, N, O, R, S, T and U
# b. Two points D and G
# c. Three points B, C, M and P
# d. Four points F, H, V, W and Y
# e. Five points K
# f. Eight points J and X
# g. Ten points Q and Z
# Create a dictionary with the alphabet as the key and the point as the value. Also
# try the other way, Point as the key and the alphabets as the value. Get an
# alphabet from the user and print the corresponding value and given a point value,
# print the alphabets having that point value.

scrabble = {'A': 1, 'B': 3, 'C': 3, 'E': 1, 'F': 4, 'H': 4, 'I': 1, 'J': 8, 'K': 5, 'L': 1, 'M': 4, 'O': 1, 'P': 3, 'Q': 10, 'R': 1, 'S': 1, 'T': 1, 'U': 1, 'V': 4, 'X': 8, 'Y': 4, 'Z': 10}

scrabblePoints = dict()

for k, v in scrabble.items():
    if v in scrabblePoints.keys():
        scrabblePoints[v].append(k)
    else:
        scrabblePoints[v] = [k]

given = input("Enter a scrabble letter or scrabble point : ").upper()

if given.isdigit():
    given = int(given)
    if given in list(scrabblePoints.keys()):
        print(scrabblePoints[given])
    else:
        print("Not a valid scrabble point")

else:
    if given in list(scrabble.keys()):
        print(scrabble[given])
    else:
        print("Not a valid scrabble letter")