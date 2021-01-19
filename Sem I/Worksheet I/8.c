// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Sep-2020 (DD-MM-YYYY) 
// Language Used : C

#include <stdio.h>

void main(){

    const double timeAndHalfCutoff = 40;
    double hourlyPay, workedHours;
    printf("Enter your hourly pay and worked hours...\n");
    scanf("%lf %lf", &hourlyPay, &workedHours);

    double extras = (workedHours - timeAndHalfCutoff);
    double payment = workedHours * hourlyPay + extras * hourlyPay * 0.5 * (extras > 0);

    printf("Your payment: %.2lf\n", payment);

}