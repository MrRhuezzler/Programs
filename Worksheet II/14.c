// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 14-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>

int isLeapYear(int year){
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return 1;
            }else{
                return 0;
            }
        }

        return 1;
    }

    return 0;
}


int main(){

    int year;
    printf("Enter a year...\n");
    scanf("%d", &year);

    printf("\'%d\' is %s a Leap Year\n", year, isLeapYear(year) ? "\b" : "not");

    return 0;
}