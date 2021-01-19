// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    char grade;
    printf("Enter the grade...\n");
    scanf("%c", &grade);

    int qualityPoints = 0;

    switch (grade)
    {
    case 'A':
        qualityPoints = 4;
        break;
    
    case 'B':
        qualityPoints = 3;
        break;

    case 'C':
        qualityPoints = 2;
        break;
    
    case 'D':
        qualityPoints = 1;
        break;

    default:
        break;
    }

    printf("The Quality points is %d\n", qualityPoints);

    return 0;
}