// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

struct pollutant
{
    char* name;
    float emmisionRates[2];
    
};

typedef struct pollutant pollutant;

int main(){

    pollutant gases[4] = {
        {"Carbon monoxide", {3.4, 4.2}},
        {"Hydrocarbons", {0.4, 0.5}},
        {"Nitrogen oxides", {0.31, 0.39}},
        {"Nonmethane hydrocarbons", {0.25, 0.31}},
    };

    int pollutantIndex, odometerReading;
    float emissionRate;

    printf("(1) Carbon monoxide\n(2) Hydrocarbons\n(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\n");
    
    printf("Enter pollutant number: ");
    scanf("%d", &pollutantIndex);

    if(pollutantIndex > 4 || pollutantIndex < 1){
        printf("Invalid Index (1 => 4)\n");
        return 0;
    }
    
    printf("Enter number of grams emitted per mile: ");
    scanf("%f", &emissionRate);

    if(emissionRate < 0){
        printf("Invalid emission rate.\n");
        return 0;
    }

    printf("Enter odometer reading: ");
    scanf("%d", &odometerReading);

    if(odometerReading < 0){
        printf("Invalid odometer reading.\n");
        return 0;
    }

    float advisableRate;

    if(odometerReading <= 50000)
        advisableRate = gases[pollutantIndex - 1].emmisionRates[0];
    else
        advisableRate = gases[pollutantIndex - 1].emmisionRates[1];

    if(advisableRate < emissionRate)
        printf("Emissions exceed permitted level of %.2f grams/mile.\n", advisableRate);
    else 
        printf("Emissions are within the permitted level of %.2f grams/mile.\n", advisableRate);

    return 0;
}