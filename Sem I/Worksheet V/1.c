// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 09-Nov-20 (DD-MM-YY)
// Language Used : C

#include <stdio.h>

int main(){

    int temperature;

    printf("Enter the temperature: ");
    scanf("%d", &temperature);

    if(temperature < 95 && temperature >= 80)
        printf("swimming");
    else if(temperature < 80 && temperature >= 60)
        printf("tennis");
    else if(temperature < 60 && temperature >= 40)
        printf("golf");
    else if(temperature < 40 && temperature >= 20)
        printf("skiing");
    else
        printf("Visit our Labs!");

    return 0;
}
