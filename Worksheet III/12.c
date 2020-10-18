// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main()
{
    float reading;
    printf("Enter Richter Scale Number: ");
    scanf("%f",&reading);

    if(reading < 5)
        printf("Little or no Damage.\n");
    else if(reading < 5.5)
        printf("Some Damage.\n");
    else if(reading < 6.5)
        printf("Serious Damage: Walls may crack or fall.\n");
    else if(reading < 7.5)
        printf("Disaster: Houses and Buildings may collapse.\n");
    else
        printf("Catastrophe: Most Buildings destroyed.\n");
        
    return 0;
}