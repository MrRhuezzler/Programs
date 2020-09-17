#include <stdio.h>

void main()
{
    int hrs;

    double HOURLY_RATE = 390.75;

    printf("Enter the number of working hours: ");
    scanf("%d", &hrs);

    double pay = HOURLY_RATE * hrs;

    printf("Your Pay is Rs. %.2lf / for working at %d Hour(s)\n", pay, hrs);


}