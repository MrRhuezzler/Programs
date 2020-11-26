#include <stdio.h>
#include <ctype.h>

char giveChar(int num){
    char result;
    switch(num){
        case 0:
            result =  'p';
            break;
        case 1:
            result =  's';
            break;
        case 2:
            result =  'r';
            break;
    }
    return result;
}

int main(){

    char playchar,compchar;
    int compint;

    printf("\nEnter your play(R,P, or S):");
    scanf("%c",&playchar);

    playchar = tolower(playchar);
    compint = rand() % 3;
    compchar = giveChar(compint);
    printf("\nComputer plays %c", compchar);

    if(playchar == compchar ){
        printf("\nNoone wins!");
    }else if(playchar == 'p' && compchar == 'r'){
        printf("\nPaper crushes rock, you win!");
    }else if(playchar == 'r' && compchar == 'p'){
        printf("\nPaper crushes rock, Computer wins!");
    }else if(playchar == 's' && compchar == 'p'){
        printf("\nScissors cut paper, you win!");
    }else if(playchar == 'p' && compchar == 's'){
        printf("\nScissors cut paper, Computer wins!");
    }else if(playchar == 'r' && compchar == 's'){
        printf("\nRock crushes scissors, you win!");
    }else if(playchar == 's' && compchar == 'r'){
        printf("\nRock crushes scissors, Computer wins!");
    }

    return 0;
}