// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    float balance = 0;
    float amnt;
    char trans, d = 'd', w = 'w';

    printf("\n\tXYZ Bank of India");
    printf("\n\t*** **** ** *****");
    printf("\n\nAmount\tTransaction Type(d/w)");
    
    while(balance >= 0){
        printf("\n\nEnter Amount: ");
        scanf("%f", &amnt);

        printf("\nEnter transaction: ");
        scanf("%c", &trans);

        if(trans == d){
            balance += amnt;
        }else if(trans == w){
            balance -= amnt;
        }else{
            printf("\nTransaction type unavailable.");
        }
    }

    printf("\n\nSorry your account is in lesser the minimum balance.\nYour Current balance amount is Rs. %.2f .", balance);

    return 0;
}