// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Sep-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

void main()
{

    int f;
    printf("Fahrenheit: ");
    scanf("%d", &f);
    printf("Celsius: %lf\n", (double)((5.0/9.0) * (f - 32)));

}