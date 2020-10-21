// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main()
{
    int i, sum = 0;
    
    for(i = 2;i <= 30;i += 2)
    {
        sum += i;
    }

    printf("Sum of even integers from to 2 to 30 is %d\n",sum);
    
    return 0;
}
