// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int sum = 0;

    printf("n = ");
    for(int i = n; i ; i /= 10){
        printf("%d", i % 10);
        sum += i % 10;
    }
    printf("\n");

    if(sum % 9)
        printf("%d is not divisible by 9\n", n);
    else
        printf("%d is divisible by 9\n", n);


    return 0;
}