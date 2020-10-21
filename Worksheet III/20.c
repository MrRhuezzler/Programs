// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int n;
    printf("Enter the total amount of entries: ");
    scanf("%d", &n);

    int value, sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        sum += value;
    }

    printf("The sum of the numbers is %d\n", sum);

    return 0;
}