// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>

int main()
{   
    double PI = 0;
    int n;

    printf("PI Calculator\n");
    printf("Enter the precision...\n");
    scanf("%d", &n);

    for(int i = 0; i < n ;i++)
    {
        double k = (4.0 / (2 * i + 1));
        if(i & 1) k *= -1;
        PI += k;
        printf("%d:\t%lf\n", i + 1, PI);
    }

    return 0;
}
