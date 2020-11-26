#include <stdio.h>

int main(){

    int guess, num, islow = 0, ishigh = 0, isguess = 0;

    num = (rand() % 10) + 1;

    do{
        printf("\n\nEnter a guess:");
        scanf("%d", &guess);
        isguess += 1;

        if(num==guess){
            printf("\nCongratulations, You guessed it right.");
        }else if(guess > num){
            printf("\nThe guess is higher than the value.");
            ishigh += 1;
        }else{
            printf("\nThe guess is lower than the value.");
            islow += 1;
        }
    }while(guess!=num);

    printf("\n\nTotal number of guesses: %d", isguess);
    printf("\nNumber of lower guesses: %d", islow);
    printf("\nNumber of higher guesses: %d", ishigh);

    return 0;
}