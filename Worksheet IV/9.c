// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){

    int f,s,w;
    char* fname, sname, wname;

    printf("\n\nPerson 1:\nName: ");
    scanf("%s", &fname);
    printf("\nScore: ");
    scanf("%d",&f);

    printf("\n\nPerson 2:\nName: ");
    scanf("%s", &sname);
    printf("\nScore: ");
    scanf("%d",&s);

    if (f<s){
        wname = sname;
        w = s-f;
    }else{
        w = f-s;
        wname = fname;
    }

    printf("\n\nResult:\n\t %s won by %d points.", wname, w);

    return 0;
}