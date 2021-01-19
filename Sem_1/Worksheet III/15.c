// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>
#include <math.h>

int main()
{
    double x1,y1,x2,y2;
    printf("Enter the 2 points (x1 y1 x2 y2): ");
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    double midX = (x1 + x2) / 2.0;
    double midY = (y1 + y2) / 2.0;
    
    if(y1 == y2){
        printf("The equation is...\nx = %+0.2f\n", midX);
        return 0;
    }

    double slope = (x1 - x2) / (y2 - y1);
    double constant = midY - slope * midX;
    
    printf("The equation is...\ny = %+0.2fx %+0.2f\n",slope, constant);

    return 0;
}
