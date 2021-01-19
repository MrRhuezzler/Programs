#include <stdio.h>

int main(){

    int temp,min=10000,max=-10000;

    for(int i=1; i<=24; i++){
        printf("\nEnter temperature at hour %d", i);
        scanf("%d", &temp);
        if(max < temp){
            max = temp;
        }
        if(min > temp){
            min = temp;
        }
    }

    printf("\n\nMaximum temperature: %d", max);
    printf("\nMinimum temperature: %d", min);

    return 0;
}