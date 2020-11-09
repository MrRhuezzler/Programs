// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    float max = -32768, min = 32767;
    int i=0;
    float num;
    printf("Enter scores:\n ");
    do{
        scanf("%f\n",&num);
        if(num!=0){
            if(i%2==0){
                if(num < min){
                    min = num;
                }
            }else{
                if(num > max){
                    max = num;
                }
            }
        }
        i += 1;

    }while((i%2==0)||(num != 0));

    printf("\nLowest men's score: %.3f",min);
    printf("\nHighest women's score: %.3f",max);
    return 0;
}