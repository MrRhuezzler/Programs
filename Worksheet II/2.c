// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 12-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){


    int ORANGE_PRICE = 3;
    int LEMON_PRICE = 5;

    int noOfOranges, noOfLemons;

    printf("Enter the number of Oranges and Lemons..\n");
    scanf("%d%d", &noOfOranges, &noOfLemons);

    int totalCost = (noOfOranges * ORANGE_PRICE) + (noOfLemons * LEMON_PRICE);

    printf("The Total Amount for %d Oranges and %d Lemons is Rs. %d\n", noOfOranges, noOfLemons, totalCost);

    return 0;
}