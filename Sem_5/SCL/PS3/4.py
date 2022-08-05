from math import e, sin, cos, tan, log

def bisection(F, a, b):
    if F(a)*F(b) > 0:
        return "No roots"

    for i in range(100000):
        x_n = (a+b)/2
        if F(x_n) == 0:
            return "The root is : {:.4f}".format(x_n)
        elif F(x_n)*F(a) < 0:
            b = x_n
        elif F(x_n)*F(b) < 0:
            a = x_n
    return "The root is : {:.4f}".format(x_n)

#1
def Q1(x): return 3*x + sin(x) - e**x
print("1 -> {}".format(bisection(Q1, 0.3, 0.4)))

#2
def Q2(x): return cos(x) - x*e**x
print("2 -> {}".format(bisection(Q2, 0.5, 0.6)))

#3
def Q3(x): return x**4 - x - 10
print("3 -> {}".format(bisection(Q3, 1, 2)))

#4
def Q4(x): return x - e**(-x)
print("4 -> {}".format(bisection(Q4, 0, 1)))

#5
def Q5(x): return e**(-x)*(x**2 + 5*x + 2) + 1
print("5 -> {}".format(bisection(Q5, -1, 0)))

#6
def Q6(x): return x - sin(x) - 0.5
print("6 -> {}".format(bisection(Q6, 1, 2)))

#7
def Q7(x): return e**(-x) - 3*log(x)
print("7 -> {}".format(bisection(Q7, 1.1, 1.2)))

#8
def Q8(x): return x*cos(x/(x-2))
print("8 -> {}".format(bisection(Q8, -1, 1)))

def Q9(x): return x*3 - (e**(-2*x)-1)      
print("9 -> {}".format(bisection(Q9, -0.1, 0.1)))

#10
def Q10(x): return tan(x) - x - 1
print("10 -> {}".format(bisection(Q10, 0, -3.14)))



