// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int main(){
    float t, v, wci;
    printf("Enter wind speed: ");
    scanf("%f", &v);
    printf("\nEnter temperature(in Fahren.): ");
    scanf("%f", &t);
    if((v>=0) && (v<=4)){
        wci = t;
    }else if (v > 45){
        wci = 1.6*t - 55;
    }else{
        float s = sqrt(v);
        wci = 91.4 + (91.4-t)*(0.0203*v - 0.304*s - 0.474);
    }

    printf("\nThe Wind Chill Index is %f", wci);
    

    return 0;
}