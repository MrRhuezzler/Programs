// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int x;
    printf("Enter a number...\n");
    scanf("%d", &x);

    int n = x;
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }

    printf("The \"sum of digits\" of the number %d is %d\n", n, sum);

    return 0;
}