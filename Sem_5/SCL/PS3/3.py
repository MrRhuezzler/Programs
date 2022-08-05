import sympy as sp
x = sp.symbols('x')


def newton_ralphson_method(F, x_n):
    f = sp.sympify(F())
    f_dash = sp.diff(f)
    f_ddash = sp.diff(f_dash)
    for i in range(100):
        h_n = -1*(f.subs(x, x_n)/f_dash.subs(x, x_n))
        x_n1 = x_n+h_n
        x_n = x_n1
        if (abs(f.subs(x, x_n)*f_ddash.subs(x, x_n)) > (abs(f_dash.subs(x, x_n)))**2):
            break
    return "The root is : {}".format(x_n1)

#a
def Qa(): return 'x**3 - 7*(x**2) + 8*x - 3'
print("a  => {}".format(newton_ralphson_method(Qa, 5.68)))

#b
def Qb(): return 'x*cos(x) - x**2'
print("b  => {}".format(newton_ralphson_method(Qb, -0.1)))

#c
def Qc(): return 'x**4 - 5*(x**3) + 9*x + 3'
print("c  => {}".format(newton_ralphson_method(Qc, -0.4)))

#d
def Qd(): return '2*(x**5) + 5'
print("d  => {}".format(newton_ralphson_method(Qd, -1.2)))

#e
def Qe(): return 'x**3 - x**2 - 15*x + 1'
print("e  => {}".format(newton_ralphson_method(Qe, -3.45)))

#f
def Qf(): return '2 - x**2 - sin(x)'
print("f  => {}".format(newton_ralphson_method(Qf, -1.78)))

#g
def Qg(): return 'cos(x) - 2*x'
print("g  => {}".format(newton_ralphson_method(Qg, 0.46)))

#h
def Qh(): return 'x - 2*sin(x)'
print("h  => {}".format(newton_ralphson_method(Qh, 0.01)))

#i
def Qi(): return '(7.3890)*x - x - 6'
print("i  => {}".format(newton_ralphson_method(Qi, 0.9)))

#j
def Qj(): return '5*x + ln(x) - 10000'
print("j  => {}".format(newton_ralphson_method(Qj, 0.01)))