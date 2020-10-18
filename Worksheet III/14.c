// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int main()
{
    int volume, mins;
    float rate;

    printf("Enter Volume to be Infused: ");
    scanf("%d",&volume);

    printf("Enter Minutes over which to Infuse: ");
    scanf("%d",&mins);
    
    rate = (60.0 * volume) / mins;
    
    printf("VTBI: %d (ml)\n",volume);
    printf("Rate: %.2f (ml/h)\n",rate);
    return 0;
}
