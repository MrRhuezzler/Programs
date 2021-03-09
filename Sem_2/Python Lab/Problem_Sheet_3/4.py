# Write a program that takes any two lists L and M of the same size and adds
# their elements together to form a new list N whose elements are sums of the
# corresponding elements in L and M. For instance, if L=[3,1,4] and M=[1,5,9],
# then N should equal [4,6,13].

def add_lists(a, b):
    return [x + y for x,y in zip(a, b)]

L = list(map(int, input("Enter a list of numbers (sep by spaces) L : ").split()))
M = list(map(int, input("Enter a list of numbers (sep by spaces) M : ").split()))
print(add_lists(L, M))