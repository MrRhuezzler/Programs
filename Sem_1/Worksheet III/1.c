// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 15-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int a, b, c, d, m, n, x1, x2, den;
    printf("Equations...\n");
    printf("a * X₁ + b * X₂ = m\n");
    printf("c * X₁ + d * X₂ = n\n");
    printf("Enter values...\na: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d",&b);
    printf("m: ");
    scanf("%d",&m);
    printf("c: ");
    scanf("%d",&c);
    printf("d: ");
    scanf("%d",&d);
    printf("n: ");
    scanf("%d",&n);

    x1 = m* d - b * n;
    x2 = n * a - m * c;
    den = a* d - c * b;
    if (den != 0)
    { 
        x1 /= den;
        x2 /= den;
        printf ("The values of x1 is %d and x2 is %d\n", x1, x2);
    }
    else
    {
      printf ("The following set of equations do not have a unique solution.\n");
    }

    return 0;
}
