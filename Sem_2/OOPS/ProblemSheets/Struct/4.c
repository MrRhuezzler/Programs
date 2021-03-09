#include<stdio.h>
#include<stdlib.h>


typedef struct {

    int z;
    char name[15];
    char sym[3];
    char group[50];
    double a;
    int eleConfig[7];
    
} S_ELE;

void writeEle(S_ELE *ele){

    printf("Atomic Number : %d\n", ele->z);
    printf("Name : %s\n", ele->name);
    printf("Symbol : %s\n", ele->sym);
    printf("Special Group : %s\n", ele->group);
    printf("Atomic Number : %lf\n", ele->a);
    printf("Electronic Configuration (7 Shells) : ");

    for(int i = 0; i < 7; i++){
        printf("%d ", ele->eleConfig[i]);
    }

    printf("\n");

}

void readEle(S_ELE *ele){

    printf("Atomic Number : ");
    scanf("%d", &ele->z);
    printf("Name : ");
    scanf("%s", &ele->name);
    printf("Symbol : ");
    scanf("%s", &ele->sym);
    printf("Special Group : ");
    scanf("%s", &ele->group);
    printf("Atomic Number : ");
    scanf("%lf", &ele->a);
    printf("Electronic Configuration (7 Shells) : ");

    for(int i = 0; i < 7; i++){
        scanf("%d", &ele->eleConfig[i]);
    }

}

int main(){

    int n;
    printf("Enter the number of entries : ");
    scanf("%d", &n);

    S_ELE *pt = (S_ELE *)malloc(sizeof(S_ELE) * n);

    for(int i = 0; i < n; i++){
        readEle(&pt[i]);
    }

    for(int i = 0; i < n; i++){
        if(pt[i].z >= 11){
            writeEle(&pt[i]);
        }
    }

    return 0;
}




