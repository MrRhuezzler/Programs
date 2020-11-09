// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int test,i=0,a,b,c;
    printf("Enter no. of testcases:");
    scanf("%d", &test);

    for(i = 0; i< test; i++){
        printf("\n\nInput %d:\n\tEnter sides of a triangle: ", i+1);
        scanf("%d%d%d", &a, &b, &c);

        if(a == b && b == c){
            printf("\n\tGiven triangle is an equilateral");
        }else if(a==b || b==c || a==c){
            printf("\n\tGiven triangle is an isoceles");
        }else{
            printf("\n\tGiven triangle is not an isoceles or an equilateral");
        }
    }

    return 0;
}
