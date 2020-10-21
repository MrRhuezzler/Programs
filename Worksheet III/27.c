// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 20-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>
#include <limits.h>

int min_max(int a, int b, int flag){

    if(a < b){
        if(flag == 1)
            return b;
        return a;
    }

    if(flag == 0)
        return b;
    return a;
}

int main(){

    int n;
    printf("Enter the total number of entries: ");
    scanf("%d", &n);

    int sqSum = 0, sum = 0, value;

    int min_value = INT_MAX, max_value = INT_MIN;

    for(int i = 0; i < n ; i++){
        scanf("%d", &value);
        sqSum += (value * value);
        sum += value;
        min_value = min_max(value, min_value, 0);
        max_value = min_max(value, max_value, 1);
    }

    float avg = sum / (float)n;

    float SD = pow((sqSum/ (float)n) - (avg * avg), 0.5);

    printf("Range %d - %d\n", min_value, max_value);
    printf("Standard deviation = %.2f\n", SD);

    return 0;
}