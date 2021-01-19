// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 12-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>


int main(){

    typedef struct {
        int day;
        int month;
        int year;
    } Date;

    int c;

    int HEART_RATE_CONSTANT = 220;

    Date birthday, currentday;
    printf("Date Input Format            : dd/mm/yy (Slashes are important !)\n");


    while(printf("Enter your birthdate         : ") && scanf("%d/%d/%d", &birthday.day, &birthday.month, &birthday.year) != 3){
        printf("Incorrect Input.. Try again!\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }

    while(printf("Enter today's date           : ") && scanf("%d/%d/%d", &currentday.day, &currentday.month, &currentday.year) != 3){
        printf("Incorrect Input.. Try again!\n");
        while ((c = getchar()) != '\n' && c != EOF);
    }

    int age = -1;
    age += (currentday.year - birthday.year);

    if(currentday.month >= birthday.month && currentday.day > birthday.day){
        age += 1;
    }

    int heartRate;

    printf("Age                          : %d\n", age);
    printf("Max. HeartRate               : %d\n", (heartRate = (HEART_RATE_CONSTANT - age)));
    printf("The Target range (15%% - 85%%) : %.2f - %.2f\n", (heartRate * (15/100.0)), (heartRate * (85 / 100.0)));

    return 0;
}