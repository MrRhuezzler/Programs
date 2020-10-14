// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
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

int returnDay(int y, int d)
{   
    //2017 is one of the years in which Jan 1 is Sunday(0)
    int ydiff = 2017 - y;

    if(ydiff < 0){
        ydiff = -ydiff;
    }

    int nol = ydiff / 4;
    if (leapyear(y==1)){
        nol +=1;
    }

    int ddiff = ydiff + nol;
    ddiff %= 7;

    return 0;
}

int main(){

    int y,d;
    int ydef = 2017, ddef = 0;
    printf("Enter year,y: ")
    scanf("%d", &y);
    printf("Enter day,d: ")
    scanf("%d", &d);
    int days[13] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(leapyear(y) == 1){
        days[1] = 29;
    }
    return 0;
}

