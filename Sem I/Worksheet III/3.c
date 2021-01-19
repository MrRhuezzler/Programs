// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

typedef struct 
{
    int day;
    int month;
    int year;

} date;


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

date returnDate(int year, int day){

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(leapyear(year)){
        days[1] = 29;
    }

    int month = 0;
    while (day > days[month])
    {
        day -=  days[month];
        month++;
    }
    
    date out = {day, month + 1, year};
    return out;

}

int main(){

    int year, day;
    printf("Enter year,y: ");
    scanf("%d", &year);
    printf("Enter day,d: ");
    scanf("%d", &day);

    date outputDate;

    outputDate = returnDate(year, day);

    if(day % 10 == 1)
        printf("The %dst day of the year %d is %d/%d/%d\n", day, year,outputDate.day, outputDate.month, outputDate.year);
    else if(day % 10 == 2)
        printf("The %dnd day of the year %d is %d/%d/%d\n", day, year,outputDate.day, outputDate.month, outputDate.year);    
    else if(day % 10 == 3)
        printf("The %drd day of the year %d is %d/%d/%d\n", day, year,outputDate.day, outputDate.month, outputDate.year);
    else
        printf("The %dth day of the year %d is %d/%d/%d\n", day, year,outputDate.day, outputDate.month, outputDate.year);

    return 0;

}

