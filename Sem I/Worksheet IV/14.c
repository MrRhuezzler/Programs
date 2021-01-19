// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int num, temp, ans = 0;
    printf("Enter an  integer: ");
    scanf("%d", &num);

    while(num){
        temp = num % 10;
        ans = ans*10 + temp;
        num = num/10;
    }

    printf("\nThe inverse inv of the integer is %d.", ans);
    printf("\nDouble of inv is %d.", ans*2);

    return 0;
}
