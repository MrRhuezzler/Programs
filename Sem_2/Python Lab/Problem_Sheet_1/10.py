# The US Census Bureau projects population based on the
# following assumptions:
# One birth every 7 seconds
# One death every 13 seconds
# One new immigrant every 45 seconds
# Write a program to display the population for each of the next five
# years. Assume the current population is 312032486 and one year has
# 365 days. Hint: in Python, you can use integer division operator //
# to perform division. The result is an integer.
# For example, 5 // 4 is 1 (not 1.25) and 10 // 4 is 2 (not 2.5).

currentPOP = 312032486
oneYrInSecs = 365 * 24 * 60 * 60
oneYrPOPAddition = ( oneYrInSecs // 7) - (oneYrInSecs // 13) + (oneYrInSecs // 45)

for i in range(5):
    currentPOP += oneYrPOPAddition
    print(f"{i + 1}th yr population : {currentPOP}")
