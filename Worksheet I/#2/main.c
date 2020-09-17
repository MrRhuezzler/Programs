#include <stdio.h>
#include <math.h>

void main(){

    int opt;

    do{

        printf("1 => Cylinder\n2 => Sphere\n3 => Pyramid\n4 => Cone\n5 => Quit\nYour Choice: ");
        scanf("%d", &opt);
        
        if(opt == 1)
            {
            double r,h;
            printf("Volume of a Cylinder\n");
            printf("Enter the radius and the height...\n");
            scanf("%lf %lf", &r, &h);
            double answer = M_PI * r * r * h;
            printf("The Volume of the entered Cylinder is : %lf\n", answer);
            printf("-------------------------------\n");
            }
        else if(opt == 2)
            {
            double r;
            printf("Volume of a Sphere\n");
            printf("Enter the radius...\n");
            scanf("%lf", &r);
            double answer = (4.0/3.0) * M_PI * r * r * r;
            printf("The Volume of the entered Sphere is : %lf\n", answer);
            printf("-------------------------------\n");
            }
        else if(opt == 3)
            {
            double w, l, h;
            printf("Volume of a Pyramid\n");
            printf("Enter the width, length and height...\n");
            scanf("%lf %lf %lf", &w, &l, &h);
            double answer = (1.0/3.0) * w * l * h;
            printf("The Volume of the entered Pyramid is : %lf\n", answer);
            printf("-------------------------------\n");
            }
        else if(opt == 4)
            {
            double r, h;
            printf("Volume of a Cone\n");
            printf("Enter the radius and height...\n");
            scanf("%lf %lf", &r, &h);
            double answer = (1.0/3.0) * M_PI * r * r * h;
            printf("The Volume of the entered Cone is : %lf\n", answer);
            printf("-------------------------------\n");
            }
        else if(opt == 5)
            printf("Thankyou !\n");
        else
            printf("Invalid Choice!\n");

    }while(opt != 5);

}