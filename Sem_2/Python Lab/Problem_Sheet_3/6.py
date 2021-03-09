# When playing games where you have to roll two dice, it is nice to know the
# odds of each roll. For instance, the odds of rolling a 12 are about 3%, and the
# odds of rolling a 7 are about 17%. You can compute these mathematically,
# but if you don’t know the math, you can write a program to do it. To do this,
# your program should simulate rolling two dice about 10,000 times and
# compute and print out the percentage of rolls that come out to be 2, 3, 4, . .
# . , 12.

from random import randint

times = {x : 0 for x in range(2, 13)}

for _ in range(10000):
    times[randint(1, 6) + randint(1, 6)] += 1

for i in range(2, 13):
    print(f"{i:2} occured for {times[i] : 5} : {times[i] / 100 : 6} %")