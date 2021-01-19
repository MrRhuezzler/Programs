#include <stdio.h>

int main(){

    int num, fact=1;

    do{
        printf("\n\nEnter a number:");
        scanf("%d", &num);
        if(num < 0){
            printf("\nThe given number is negative. Enter an non negative number");
        }
    }while(num < 0);

    if(num == 0){
        printf("\nThe factorial of %d is 1.", num);
    }else{
        for(int i=1; i<=num; i++){
            fact *= i;
        }
        printf("\nThe factorial of %d is %d", num, fact);
    }

    return 0;
}