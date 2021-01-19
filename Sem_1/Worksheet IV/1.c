// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    int d, arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    char ssh[][20]={"month","January","February","March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Enter number of days: ");
    scanf("%d",&d);
    printf("Month %s has %d of days.",ssh + d,arr[d]);
    return 0;
}