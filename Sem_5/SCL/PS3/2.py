from math import isclose
import sympy as sp
x = sp.symbols('x')

# Equation: x = func(x)
def fixed_point_method(F, a, b):
    f = sp.sympify(F())
    f_dash = sp.diff(f, x)
    if max(f_dash.subs(x, a), f_dash.subs(x, b)) > 1:
        print('It doesn\'t converge')
        return None

    x_n = a
    for _ in range(10):
        x_n_1 = f.evalf(subs={x : x_n})
        if isclose(x_n, x_n_1, rel_tol=1e-3):
            return x_n_1
        x_n = x_n_1
    return x_n


def Qa(): return '(cos(x) + 1) / 3'
print("a  => {}".format(fixed_point_method(Qa, 0, 1)))
