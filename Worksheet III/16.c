// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C

#include<stdio.h>

int main()
{
    int m,n;
    
    printf("Enter m: ");
    scanf("%d",&m);
    
    printf("Enter n: ");
    scanf("%d",&n);

    if(m>n)
    {
        int side1 = (m * m) - (n * n);
        int side2 = 2 * m * n;
        int hypotenuse = (m * m)+(n * n);
        printf("Side 1 = %d, Side 2 = %d, Hypotenuse = %d\n", side1, side2, hypotenuse);
    }
    else
        printf("Invalid Input(s).\n");

    return 0;
}
