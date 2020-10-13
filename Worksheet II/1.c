// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 12-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int start, end;
    
    const float COST_PER_HOUR = 150.0f;
    const int EXTRA_TIME = 17;
    const float EXTRA_COST_PER_HOUR = 100.0f;

    printf("Enter Start and End time of the Employee\n");
    scanf("%d%d", &start, &end);

    if(start > end || start < 8 || end > 24){
        printf("INVALID INPUTS\n");
        return 0;
    }

    float pay = (end - start) * COST_PER_HOUR;
    float extras = 0;
    int elapsed = 0;

    if(end > EXTRA_TIME){
        if(start > EXTRA_TIME){
            elapsed = -(start - end);
            extras += elapsed * EXTRA_COST_PER_HOUR;
        }else{
            elapsed = -(EXTRA_TIME - end);
            extras += elapsed * EXTRA_COST_PER_HOUR;
        }
    }

    printf("Start Time    : %d\n", start);
    printf("End Time      : %d\n", end);
    printf("Elapsed Time  : %d\n", end - start);
    printf("Pay(Standard) : %.2f\n", pay);
    printf("--Extras--\n");
    printf("Elapsed Time  : %d\n", elapsed);
    printf("Pay(Extras)   : %.2f\n", extras);
    printf("----------\n");
    printf("Total Pay     : %.2f\n", pay + extras);

    return 0;

}