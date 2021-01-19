// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    int choice = 0;
    int num, div;
    do {
        printf("\n\nEnter an integer: ");
        scanf("%d", &num);
        printf("\nThe individual numbers are: ");

        while(num>0){
            div = 1;
            while(div <= num){
                div *= 10;
            }
            div /=10;
            printf("\t%d",num / div);
            num %= div;
        }

        printf("\n\nMore? -1 to stop, other to continue:");
        scanf("%d", &choice);
    } while(choice != -1);
    return 0;
}