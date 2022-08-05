from math import cos, e, sin, tan

def false_position(f,x0,x1,e= 0.0001):
    step = 1
    condition = True
    while condition:
        x2 = x0 - (x1-x0) * f(x0)/( f(x1) - f(x0) )
        
        if f(x0) * f(x2) < 0:
            x1 = x2
        else:
            x0 = x2

        step = step + 1
        condition = abs(f(x2)) > e

    return "The root is : {:.3f}".format(x2)

#a
def a(x): return 3*x - cos(x) - 1
print("a  => {}".format(false_position(a, 0, 1)))

#b
def b(x): return cos(x) - x*e**x
print("b  => {}".format(false_position(b, 0, 0.6)))

#c
def c(x): return x**3 + 2*x**2 + 10*x - 20
print("c  => {}".format(false_position(c, 1, 2)))

#d
def d(x): return x - cos(x)
print("d  => {}".format(false_position(d, 0, 1)))

#e
def Qe(x): return e**(-x)*(x**2 + 5*x+2) + 1
print("e  => {}".format(false_position(Qe, -1, 0)))

#f
def f(x): return x - sin(x) - 0.5
print("f  => {}".format(false_position(f, 1, 2)))

#g
def g(x): return x*e**x - 3
print("g  => {}".format(false_position(g, 1, 2)))

#h
def h(x): return x*cos(x/(x-2))
print("h  => {}".format(false_position(h, -1, 1,0.01)))

#i
def i(x): return x**3 - (e**(-2*x) - 1)
print("i  => {}".format(false_position(i, -0.1, 0.0001)))

#j
def j(x): return tan(x) - x - 1
print("j  => {}".format(false_position(j, 1, 1.2)))

#k
def k(x): return 3*x + sin(x) - e**x
print("k  => {}".format(false_position(k, 0, 1)))

#l
def l(x): return e**(-x) - sin(x)
print("l  => {}".format(false_position(l, 3, 4)))