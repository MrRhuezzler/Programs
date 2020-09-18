// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Sep-2020 (DD-MM-YYYY) 
// Language Used : C

#include <stdio.h>

void main(){

    int feet, inch;
    printf("Enter the length in feet and inches...\n");
    printf("Example input: 21 feet, 10 inches\n");
    scanf("%d feet, %d inches", &feet, &inch);
    int inches = 12 * feet + inch;
    printf("Your total length in inches is %d inches\n", inches);

}