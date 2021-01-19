// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include<stdio.h>

int main(){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if ((num%5 == 0) && (num%6 == 0)){
        printf("\nIs %d divisible by 5 and 6? True.",num);
    }else{
        printf("\nIs %d divisible by 5 and 6? False.",num);
    }

    if ((num%5 == 0) || (num%6 == 0)){
        printf("\nIs %d divisible by 5 or 6? True.",num);
    }else{
        printf("\nIs %d divisible by 5 or 6? False.",num);
    }

    if ((num%5 == 0) != (num%6 == 0)){
        printf("\nIs %d divisible by 5 and 6,but not both? True.",num);
    }else{
        printf("\nIs %d divisible by 5 and 6,but not both? False.",num);
    }
    
    return 0;
}