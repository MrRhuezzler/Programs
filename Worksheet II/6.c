// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int a,b,c;
    printf("Enter three numbers...\n");
    scanf("%d%d%d", &a, &b, &c);

    int *largest, *smallest;

    if(a >= b){
        if(a >= c){
            largest = &a;
            if(b >= c){
                smallest = &c;
            }else{
                smallest = &b;
            }
        }else{
            smallest = &b;
            largest = &c;
        }
    }else{
        if(b >= c){
            largest = &b;
            if(a >= c){
                smallest = &c;
            }else{
                smallest = &a;
            }
        }else{
            largest = &c;
            smallest = &a;
        }
    }

    printf("The largest number is %d, and it is %s\n", *largest, (*largest & 1) ? "odd" : "even");
    printf("The largest number is %d, and it is %s\n", *smallest, (*smallest & 1) ? "odd" : "even");

    return 0;
}