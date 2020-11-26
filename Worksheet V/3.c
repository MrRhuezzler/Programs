#include <stdio.h>

int main() {
     
    int num,sum=0;
    printf("\nEnter a number:");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        printf("\n%d I love C Programming!!", i);
        sum += i;
    }
    printf("\nPrinted this message %d times", num);
    printf("\nThe sum of the numbers from 1 to %d is %d", num, sum);

    return 0;
}