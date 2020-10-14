// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>
#include <math.h>

int main(){
    
    float x;
    printf("Enter a decimal number...\n");
    scanf("%f", &x);
    int prec = 6;
    printf("Enter precision of the output...\n");
    scanf("%d", &prec);

    int decimal = (int) x;
    float fractional = x - (float)decimal;

    int dec_it = floor(log2(decimal) + 1);
    int decimal_equi[dec_it];

    for(int i = dec_it - 1; decimal != 0; i--){
        decimal_equi[i] = decimal % 2 ;
        decimal /= 2;
    }

    for(int i = 0; i < dec_it; i++){
        printf("%d", decimal_equi[i]);
    }
    printf(".");


    int frac_it = prec;
    int frac_equi[frac_it];

    for(int i = 0; i < frac_it; i++){
        float n = fractional * 2;
        int dec = (int)n;
        float frac = n - dec;
        frac_equi[i] = dec;
        fractional = frac;
    }

    for(int i = 0; i < frac_it; i++){
        printf("%d", frac_equi[i]);
    }

    printf("\n");

    return 0;
}