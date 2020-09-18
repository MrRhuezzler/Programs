// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Sep-2020 (DD-MM-YYYY) 
// Language Used : C

#include <stdio.h>

void main(){

    const double perUnit = 7.13;
    const double fixedCharge = 30.50;

    double oldMeterReading, newMeterReading;
    printf("Enter Old meter reading and New meter reading...\n");
    scanf("%lf %lf", &oldMeterReading, &newMeterReading);

    double meterConsumed = newMeterReading - oldMeterReading;
    double charges = meterConsumed * perUnit + fixedCharge;

    printf("Consumed : %.2lf \nTotal Charges: Rs.%.4lf\n", meterConsumed, charges);

}