// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

long long fact(int n){

    long long f = 1;
    for(int i = 1; i <= n; i++){
        f *= i;
    }

    return f;
}

int main(){

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 0)
        printf("Negative number are not allowed\n");
    else
        printf("%d! is %ld\n", n, fact(n));

    return 0;
}