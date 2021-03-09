# Using a for loop, create the list below, which consists of ones separated by
# increasingly many zeroes. The last two ones in the list should be separated
# by ten zeroes.
# [1,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,....]

l = [1]
for i in range(11):
    l.extend(0 for _ in range(i))
    l.append(1)

for i in range(len(l)):
    if i % 20 == 0 and i != 0:
        print()
    
    print(l[i], end=", ")