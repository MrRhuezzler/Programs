// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 12-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int isPrime(int x){
    if(x == 2 || x == 3){
        return 1;
    }else if(x % 2 == 0 || x % 3 == 0){
        return 0;
    }else{
        for(int i = 5; i < sqrt(x); i += 6){
            if(x % i == 0) return 0;
        }
        return 1;
    }
}

int main(){

    int x;
    printf("Enter a number...\n");
    scanf("%d", &x);

    printf("%d, is %s a prime number.\n", x, (isPrime(x)) ? "\b" : "not");

    return 0;
}