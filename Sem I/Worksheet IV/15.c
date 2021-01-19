// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    int num,sum,mid;

    printf("\nEnter a 3-digit integer: ");
    scanf("%d", &num);

    printf("\n(To check whether the middle digit numerically equals to sum of other two)");
    printf("\n\nResult:");

    sum = num/100 + num%10;
    mid = (num/10)%10;

    if(sum == mid){
        printf("\tTrue");
    }else{
        printf("\tFalse");
    }

    return 0;
}
