// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <string.h>

int leapyear(int y){
    if(y%4 == 0){
        if(y%100 == 0){
            if(y%400==0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int getMonthIndex(char month[]){

    if(!strcmp(month,"January")){
        return 0;
    }else if(!strcmp(month,"February")){
        return 1;
    }else if(!strcmp(month,"March")){
        return 2;
    }else if(!strcmp(month,"April")){
        return 3;
    }else if(!strcmp(month,"May")){
        return 4;
    }else if(!strcmp(month,"June")){
        return 5;
    }else if(!strcmp(month,"July")){
        return 6;
    }else if(!strcmp(month,"August")){
        return 7;
    }else if(!strcmp(month,"September")){
        return 8;
    }else if(!strcmp(month,"October")){
        return 9;
    }else if(!strcmp(month,"November")){
        return 10;
    }else if(!strcmp(month,"December")){
        return 11;
    }else
        return -1;
}

int main(){

    char month[20];
    int year, day;

    printf("Date Format : January 31 1996\n");
    printf("Enter a date...\n");

    scanf("%s", &month);
    scanf("%d%d", &day, &year);

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(leapyear(year)){
        days[1] = 29;
    }

    int monthIndex = getMonthIndex(month);
    
    if(monthIndex < 0){
        printf("Invalid input for month");
        return 0;
    }

    int dayOfTheYear = 0;

    for(int i = 0; i < monthIndex; i++)
        dayOfTheYear += days[i];

    dayOfTheYear += day;

    switch(dayOfTheYear % 10){
        case 1:
            printf("%s %d is %dst day of the year %d\n", month, day, dayOfTheYear, year);
            break;
        case 2:
            printf("%s %d is %dnd day of the year %d\n", month, day, dayOfTheYear, year);
            break;
        case 3:
            printf("%s %d is %dth day of the year %d\n", month, day, dayOfTheYear, year);
            break;
        default:
            printf("%s %d is %dth day of the year %d\n", month, day, dayOfTheYear, year);
            break;
    };

    return 0;
}