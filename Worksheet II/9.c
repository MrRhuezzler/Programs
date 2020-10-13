// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 13-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int fact(int x){
    int f = 1;
    if(x < 0){
        return 0;
    }else{
        for(int i = 1; i < x + 1; i++){
            f *= i;
        }
    }

    return f;
}

int main(){

    int x;
    printf("Computing sin(1/x)..Enter x..\n");
    scanf("%d", &x);

    if(x == 0){
        printf("x should be non zero !");
        return 0;
    }

    float answer = 0;

    for(int i = 0; i < 10; i++){
        float k = (pow(x, -(2 * i + 1)) / fact(2 * i + 1));
        if(i & 1){
            answer -= k;
        }else{
            answer += k;
        }

    }

    // printf("sin(1/%d) = %lf\n", x, sin(1.0/ x));
    printf("The approximation of sin(1/x) when x is %d, is %f\n", x, answer);

    return 0;
}