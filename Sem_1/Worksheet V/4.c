#include <stdio.h>

int main(){

    int num,prod=1;
    printf("\nEnter a number :");
    scanf("%d",&num);
    
    printf("\nHere are the first %d powers of 2", num);
    for(int i=0; i<num; i++){
        printf("\n\t2^%d = %d",i,prod);
        prod *= 2;
    }

    return 0;
}