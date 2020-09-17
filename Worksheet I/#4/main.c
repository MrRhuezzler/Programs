#include <stdio.h>

void main()
{

    int f;
    printf("Fahrenheit: ");
    scanf("%d", &f);
    printf("Celsius: %lf\n", (double)((5.0/9.0) * (f - 32)));

}