// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int a, b, c, d, m, n, x1, x2, den;
    scanf("Enter values:\n\ta: %d\n\tb: %d\n\tm: %d\n\tc: %d\n\td: %d\n\tn: %d",&a, &b, &m, &c, &d, &n);
    x1 = m* d - b * n;
    x2 = n * a - m * c;
    den = a* d - c * b;
    if (den != 0)
    { 
        x1 /= den;
        x2 /= den;
        printf ("The values of x1 is %d and x2 is %d", x1, x2);
    }
    else
    {
      printf ("The following set of equations do not have a unique solution.");
    }

    return 0;
}
