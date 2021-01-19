// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 14-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>
#include <math.h>

double abso(double x){
    if( x < 0){
        return -x;
    }
    return x;
}

int main(){


    double a, b, c;
    printf("a * x² + b * x + c\n");
    printf("Enter the values for a, b, c...\n");
    scanf("%lf%lf%lf",&a, &b, &c);

    double D = (b * b) - ( 4.0 * a * c);

    typedef struct {
        double real;
        double img;
    } cmplx;
    
    cmplx x1, x2;

    if(D >= 0){
        x1.real = (-b + pow(D, 0.5)) / (2.0 * a);
        x2.real = (-b - pow(D, 0.5)) / (2.0 * a);
    }else{
        double real = -b / (2.0 * a);
        double img = pow(-D, 0.5) / (2.0 * a);
        x1.real = real;
        x1.img  = img;
        x2.real = real;
        x2.img  = -img;
    }

    printf("The Roots are...\n");
    if(D < 0){
        printf("x1 = %lf %c i(%lf)\n", x1.real, (x1.img < 0) ? '-':'+', abso(x1.img));
        printf("x2 = %lf %c i(%lf)\n", x2.real, (x2.img < 0) ? '-':'+', abso(x2.img));
    }else{
        printf("x1 = %lf\n", x1.real);
        printf("x2 = %lf\n", x2.real);
    }

    return 0;
}