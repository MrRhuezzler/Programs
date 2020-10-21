// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int main(){

    float principalAmount, interestRate, i, payment;
    float payInt, payPri;
    int monthlyPayments;

    printf("Enter the amount to be borrowed:");
    scanf("%f", &principalAmount);
    
    printf("Enter the Annual Interest rate:");
    scanf("%f", &interestRate);
    
    printf("Enter the number of monthly payments:");
    scanf("%d", &monthlyPayments);
    
    i = interestRate / ( 100 * 12.0 );//monthly interest rate  
    
    payment = (i*principalAmount)/(1-pow(1+i,-monthlyPayments));//calculating monthly payment
    
    printf("\nPrincipal:%.2f\n",principalAmount);
    printf("Annual Interest:%.2f\n",interestRate);
    printf("Term: %d\n",monthlyPayments);
    printf("Monthly Payment:%.2f\n\n",payment);
    printf("Payment\tInterest\tPrincipal\tBalance\n");
    
    for(int k=1;k<=monthlyPayments;k++){

        payInt = i*principalAmount;
        payPri = payment - payInt;
        principalAmount = principalAmount - payPri;
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", k, payInt, payPri, principalAmount);

    }
    
    printf("Final Payment:%.2f", payInt+payPri);
}   