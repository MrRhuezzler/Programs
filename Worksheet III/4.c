// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C


#include<stdio.h>


int main(){

    int denomination;
    printf("Enter the card's denomination...\n");
    scanf("%d", &denomination);

    if(denomination < 1 || denomination > 52){
        printf("Numbers only from 1 to 52\n");
        return 0;
    }

    char* suites[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    char* cards[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    int wCard = denomination % 13;
    int wSuite = (denomination / 13) - 1;

    wCard--;
    if(wCard < 0){
        wCard = 12;
    }


    printf("%s of %s\n", cards[wCard], suites[wSuite]);

    return 0;
}