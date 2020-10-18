// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C


#include <stdio.h>
#include <math.h>


int main(){

    char str[4];
    printf("Enter the string...\n");
    scanf("%s", &str);

    int flag = 0;

    for(int i = 1; i < 3; i++){

        if(str[i] == '.' && \
            (str[i - 1] > 47 && str[i - 1] < 58) && \
            (str[i + 1] > 47 && str[i + 1] < 58)){
                float number;
                number = (str[i - 1] - 48) + (str[i + 1] - 48) * 0.1;
                printf("The answer is %f\n", pow(number, 2));
                flag = 1;
                break;
        }


    }

    if(!flag)
        printf("Wrong input string !\n");

    return 0;
}

