# Create the following lists using a for loop.
# (a) A list consisting of the integers 0 through 49
# (b) A list containing the squares of the integers 1 through 50.
# (c) The list ['a' ,'bb','ccc','ddddd', . . . ] that ends with 26 copies of the letter z.
from string import ascii_lowercase

import pprint

pprint.pprint(f"(a) {[x for x in range(0, 50)]}")
pprint.pprint(f"(b) {[x ** 2 for x in range(1, 51)]}")
pprint.pprint(f"(c) {[x * (i + 1) for i,x in enumerate(ascii_lowercase)]}")



