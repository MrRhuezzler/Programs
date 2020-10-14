// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int x;
    printf("Enter a number...\n");
    scanf("%d", &x);

    int bin[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 15; x != 0; i--){
        bin[i] = x % 2;
        x /=2;
    }

    printf("Binary Equivalent: ");

    for(int i = 0; i < 16; i++){
        if(i != 0 && i % 4 == 0) printf(" ");
        printf("%d", bin[i]);
    }
    printf("\n");
    return 0;
}