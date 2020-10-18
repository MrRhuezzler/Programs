// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){


    int numberOfMonth;
    printf("Enter the number of the month...\n");
    scanf("%d", &numberOfMonth);

    if(numberOfMonth <= 0 || numberOfMonth > 12){
        printf("Invalid Input\n");
        return 0;
    }

    char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


    if(numberOfMonth % 10 == 1)
        printf("The %dst month is %s \n", numberOfMonth, months[numberOfMonth - 1]);
    else if(numberOfMonth % 10 == 2)
        printf("The %dnd month is %s \n", numberOfMonth, months[numberOfMonth - 1]);
    else if(numberOfMonth % 10 == 3)
        printf("The %drd month is %s \n", numberOfMonth, months[numberOfMonth - 1]);
    else
        printf("The %dth month is %s \n", numberOfMonth, months[numberOfMonth - 1]);

    return 0;
}