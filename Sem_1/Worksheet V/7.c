#include <stdio.h>

int main(){
    int precno=0, num1, num2, votesno;
    float p1percent, p2percent;
    int p1precwon = 0, p2precwon = 0, p1voteswon = 0, p2voteswon = 0;
    char opt;

    do{
        precno += 1;
        printf("\n\nPrecinct no.%d",precno);
        printf('\nEnter the number of votes for P1:');
        scanf("%d", &num1);
        printf('\nEnter the number of votes for P2:');
        scanf("%d", &num2);
        p1voteswon += num1;
        p2voteswon += num2;
        if(num1 > num2){
            p1precwon += 1;
        }else if(num1 < num2){
            p2precwon += 1;
        }
        printf("\nAre there any more precincts (y,n) :");
        scanf("%c", &opt);

        if(opt == 'Y'){
            opt = 'y';
        }

        if(opt == 'N'){
            opt = 'n';
        }

    }while(opt == 'y');

    votesno = p1voteswon + p2voteswon;

    printf("\n\nTotal no. of votes: %d", votesno);
    printf("\nTotal no. of precincts: %d", precno);
    
    printf("\n\nVPrecincts carried by P1: %d", p1precwon);
    printf("\nPrecincts carried by P2: %d", p2precwon);

    p1percent = p1voteswon * 100 / votesno;
    p2percent = p2voteswon * 100 / votesno;

    printf("\nPercent won by P1: %f", p1percent);
    printf("\nPercent won by P2: %f", p2percent);

    return 0;
}