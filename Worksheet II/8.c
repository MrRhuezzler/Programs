// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <limits.h>

int max(int a, int b){
    if(a > b)
        return a;
    else return b;
}

int min(int a, int b){
    if(a < b)
        return a;
    else return b;
}

int main(){

    int numbers[4];
    printf("Enter four numbers...\n");
    for(int i = 0; i < 4; i++)
        scanf("%d", &numbers[i]);

    int max_ = INT_MIN;
    int min_ = INT_MAX;

    for(int i = 0; i < 4; i++){
        max_ = max(max_, numbers[i]);
        min_ = min(min_, numbers[i]);
    }

    printf("The Maximum is %d, The Minimum is %d\n", max_, min_);
    printf("The difference is %d\n", max_ - min_);

    return 0;
}