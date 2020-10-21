// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>


int main(){

    int n;

    printf("Enter a number: ");
    scanf("%d",&n);
    
    int sum = 0;

    for(int i = n; i; i /= 10){
        sum += i % 10;
    }
    
    printf("Sum of Digits of %d is %d\n",n,sum);
    
    return 0;
}
