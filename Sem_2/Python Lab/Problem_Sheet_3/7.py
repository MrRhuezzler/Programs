# Write a program that rotates the elements of a list so that the element at the
# first index moves to the second index, the element in the second index
# moves to the third index, etc., and the element in the last index moves to the
# first index.

l = list(map(int, input("Enter numbers seperated by spaces : ").split()))
for i in range(len(l)):
    l.insert(0, l.pop())
    print(l)