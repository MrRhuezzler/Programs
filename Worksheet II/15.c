// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 14-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>
#include <math.h>

int main(){
    
    int number;
    printf("Enter a number...\n");
    scanf("%d", &number);

    int num_copy = number;
    int check = 0;
    int n = floor(log10(num_copy) + 1);
    while (number)
    {
        check += pow((number % 10), n);
        number /= 10;
    }
    
    printf("\'%d\' is %s a Armstrong number.\n", num_copy, (num_copy == check) ? "\b" : "not");

    return 0;
}