// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int main()
{
    int r2;
    float weight,height,BMI,r1;

    printf("Enter Weight in Pounds: ");
    scanf("%f",&weight);
    
    printf("Enter Height in Inches: ");
    scanf("%f",&height);
    
    BMI = (703.0 * weight) / (height * height);
    
    if(BMI < 0)
        printf("Invalid Input(s).\n");
    else
    {
        r1 = BMI;
        r2 = BMI;
        
        // To get BMI to a precision of one.
        r1 = round((r1-r2)*10);
        BMI = r2 + ( r1 / 10.0);

        if(BMI < 18.5)
            printf("Underweight.\n");
        else if(BMI <= 24.9)
            printf("Normal.\n");
        else if(BMI <= 29.9)
            printf("Overweight.\n");
        else
            printf("Obese.\n");
    }

    return 0;
}