// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Sep-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

void main()
{

    int secs, hrs, mins, gsecs;
    printf("Enter the time in seconds: ");
    scanf("%d", &secs);
    gsecs = secs;
    mins = secs / 60; secs %= 60;
    hrs = mins / 60; mins %= 60;

    printf("%d seconds is equivalent to %02d hours, %02d minutes and %02d seconds\n", gsecs, hrs, mins, secs);

}