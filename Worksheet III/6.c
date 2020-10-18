// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 16-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main()
{
    char c;
    scanf("%c",&c);

    if(c=='A'|c=='B'|c=='C')
        printf("2");
    else if (c=='D'|c=='E'|c=='F')
        printf("3");
    else if (c=='G'|c=='H'|c=='I')
        printf("4");
    else if (c=='J'|c=='K'|c=='L')
        printf("5");
    else if (c=='M'|c=='N'|c=='O')
        printf("6");
    else if (c=='P'|c=='R'|c=='S')
        printf("7");
    else if (c=='T'|c=='U'|c=='V')
        printf("8");
    else if (c=='W'|c=='X'|c=='Y')
        printf("9");
    else
        printf("Input is invalid."); 
    
    return 0;
}