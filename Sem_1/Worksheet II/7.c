// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){


    int mark;
    printf("Enter your mark...\n");
    scanf("%d", &mark);

    char grade = 'F';

    if(mark <= 100 && mark >= 90){
        grade = 'A';
    }else if(mark < 90 && mark >= 80){
        grade = 'B';
    }else if(mark < 80 && mark >= 70){
        grade = 'C';
    }else if(mark < 70 && mark >= 60){
        grade = 'D';
    }else if(mark < 60 && mark >= 50){
        grade = 'E';
    }

    printf("Your grade is %c\n", grade);

    return 0;
}