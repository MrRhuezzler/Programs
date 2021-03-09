# Write a program that removes any repeated items from a list so that each
# item appears at most once. For instance, the list [1,1,2,3,4,3,0,0] would
# become [1,2,3,4,0].


def removeDups(l):
    temp = []
    for i in l:
        if i not in temp:
            temp.append(i)
    return temp

li = list(map(int, input("Enter a list of number (sep by spaces) : ").split(" ")))
print("Without Duplicates : ", removeDups(li))


