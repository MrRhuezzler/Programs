// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int main(){

    float principalAmt, intRate, i, payment;
    float payInt, payPri;
    int monthlyPayments;

    printf("Enter the amount to be borrowed:");
    scanf("%f", &principalAmt);
    
    printf("Enter the Annual Interest rate:");
    scanf("%f", &intRate);
    
    printf("Enter the number of monthly payments:");
    scanf("%d", &monthlyPayments);
    
    i = intRate / ( 100 * 12.0 );
    
    payment = (i * principalAmt) / (1 - pow(1 + i, -monthlyPayments));
    
    printf("\nPrincipal : %.2f\n" , principalAmt);
    printf("Annual Interest : %.2f\n" , intRate);
    printf("Term : %d\n" , monthlyPayments);
    printf("Monthly Payment : %.2f\n\n" , payment);
    printf("Payment\tInterest\tPrincipal\tBalance\n");
    
    for(int k = 1;k <= monthlyPayments;k++){

        payInt = i * principalAmt;
        payPri = payment - payInt;
        principalAmt = principalAmt - payPri;
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", k, payInt, payPri, principalAmt);

    }
    
    printf("Final Payment:%.2f", payInt + payPri);
}   