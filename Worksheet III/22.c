// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <limits.h>

int min(int a, int b){

    if(a < b)
        return a;
    
    return b;
}

int main(){

    int n, value, min_value = INT_MAX;

    printf("Enter the total entries and followed by the entries..\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        min_value = min(value, min_value);
    }

    printf("The minimum value is %d\n", min_value);

    return 0;
}