// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int value;
    char spacer;

    printf("Enter the daily temperatures seperated by spaces\n");
    printf("Make sure you give a enter right after the last number!\n");

    int n = 0;
    int hotDays = 0, pleasantDays = 0, coldDays = 0;
    int tempSum = 0;

    while (1)
    {
        scanf("%d%c", &value, &spacer);
        tempSum += value;

        if(value >= 85)
            hotDays++;
        else if(value >= 60)
            pleasantDays++;
        else
            coldDays++;

        n++;
        if(spacer == EOF || spacer == '\n')
            break;
    }

    printf("\n");
    printf("Total no.of Days: %d\n", n);
    printf("Avg Temp        : %.2f\n", (tempSum / (float)n));
    printf("Hot Days        : %d\n", hotDays);
    printf("Plesant Days    : %d\n", pleasantDays);
    printf("Cold Days       : %d\n", coldDays);

    return 0;
}