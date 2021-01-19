// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    printf("-------------------------\n");
    printf("| Dec\t| Oct\t| Hex\t|\n");
    printf("-------------------------\n");
    for(int i = 1; i < 257; i++){
        printf("| %d\t| %o\t| %X\t|\n", i, i, i);
    }

    return 0;
}