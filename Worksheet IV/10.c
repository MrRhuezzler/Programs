// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int num, max = -32768, min = 32767, imin = 0, imax = 0, i=1;

    printf("Enter sample integers, negative integer when done: ");
    do{
        scanf("%d",&num);
        if(num > max){
            max = num;
            imax = i;
        }
        if((num > 0) && (num < min)){
            min = num;
            imin = i;
        }
        i += 1;

    }while(num >= 0);

    printf("\nThe smallest integer was %d and it is data item #%d",min, imin);
    printf("\nThe largest integer was %d and it is data item #%d",max, imax);
    return 0;
}