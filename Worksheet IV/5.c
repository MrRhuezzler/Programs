// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    int choice = 0;
    int num,rem, sum = 0;
    do {
        printf("\n\nEnter an integer: ");
        scanf("%d", &num);

        printf("\nAfter Operation:\nremainder\tnum");
        printf("\n_________\t___\n");


        while(num > 0){
            rem = num%10;
            num /= 10;
            sum += rem;
            printf("\n%d\t\t%d",rem,num);
        }
        printf("\nSum of digits is %d", sum);
        printf("\n\nMore? -1 to stop, other to continue:");
        scanf("%d", &choice);
    } while(choice != -1);
    return 0;
}