// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 15-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

typedef struct 
{
    int day;
    int month;
    int year;        
} date;

int getDOW(date inputDate){

    int month = inputDate.month;
    int year = inputDate.year;
    int day = inputDate.day;


    int Decade, Century;


    if(month == 1){
        month = 13;
        year--;
    }

    if(month == 2){
        month = 14;
        year--;
    }

    Decade = year % 100;
    Century = year / 100;

    int f = day + 13 * (month + 1) / 5 + Decade + Decade / 4 + Century / 4 + 5 * Century;

    return ( ( f % 7 ) + 7 ) % 7;
}

 
int main(){
    
    date inputDate;

    int c; // Useless variable, but still vitale to make the program stable
    printf("Date Format : dd/mm/yyyy (slashes are important)\n");
    while(printf("Enter a date : ") && scanf("%d/%d/%d", &inputDate.day, &inputDate.month, &inputDate.year) != 3){
        printf("Incorrect Input.. Try again!\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }

    char* DaysOfWeek[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("It is a %s\n", DaysOfWeek[getDOW(inputDate)]);

    return 0;
}