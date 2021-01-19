// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    const int sentinal = -999;

    int n = 0;
    int value, sum = 0;

    while (1)
    {
        scanf("%d", &value);

        if(value == sentinal)
            break;

        n++;
        sum += value;
    }

    printf("The average of the given values is %.2f\n", (sum / (float)n));

    return 0;
}