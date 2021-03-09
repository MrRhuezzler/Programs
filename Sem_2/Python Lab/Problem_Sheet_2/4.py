# Write a program that asks the user for number of seconds and print how many
# minutes and seconds that is. (use operators appropriately)

gsecs = int(input("Secs : "))
print(f"{gsecs // 60} Minutes, {gsecs % 60} Seconds")