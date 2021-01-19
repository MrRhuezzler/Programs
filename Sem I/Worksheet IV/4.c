// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    int cont = 0;

    do
    {
        char item[50];
        float price;
        int opn;
        printf("Enter an item: ");
        scanf("%s", &item);
        printf("\nEnter price: ");
        scanf("%f", &price);

        do{
            printf("\nOvernight delivery (0 = no, 1 = yes): ");
            scanf("%d", &opn);
            if((opn != 1) && (opn !=0)){
                printf("\nInvalid option\n");
            }
        } while (opn!=0 && opn!=1);

        printf("\n\nInvoice:");
        printf("\n%s\t\t%.2f",item,price);

        float ship = 2 + opn*5;

        if(price > 10){
            ship+=1;
        }

        printf("\nShipping\t%.2f",ship);
        printf("\nTotal\t\t%.2f",ship + price);
        printf("\nMore item? -1 to stop, other to continue: ");
        scanf("%d", &cont);
    } while(cont != -1);
    

    return 0;
}