#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int **matrix;
    int size;

} poly;

int max(int a, int b){
    return a >= b ? a : b;
}

poly* initPoly(int hiOrder){

    poly *temp = (poly *) malloc(sizeof(poly));

    temp->size = hiOrder + 1;
    temp->matrix = (int **) malloc((hiOrder + 1) * sizeof(int *));

    for(int i = hiOrder; i >= 0; i--){

        temp->matrix[hiOrder - i] = (int *) malloc(2 * sizeof(int *));

        printf("Coeff of X^%d : ", i);
        scanf("%d", &temp->matrix[hiOrder - i][0]);

        temp->matrix[hiOrder - i][1] = i;

    }

    return temp;

}


poly* add(poly *a, poly *b){

    poly *ans = (poly *) malloc(sizeof(poly));

    ans->size = max(a->size, b->size);
    ans->matrix = (int **) malloc(ans->size * sizeof(int *));

    for(int i = 0; i < ans->size; i++){
        ans->matrix[i] = (int *) malloc(2 * sizeof(int));
    }

    int i = 0;
    int j = 0;
    int k = 0;

    int *a_sub, *b_sub;

    while (i < a->size && j < b->size)
    {
        a_sub = a->matrix[i];
        b_sub = b->matrix[j];

        if(a_sub[1] == b_sub[1]){
            ans->matrix[k][0] = a_sub[0] + b_sub[0];
            ans->matrix[k][1] = a_sub[1];
            i++;
            j++;
        }else if(a_sub[1] < b_sub[1]){
            ans->matrix[k][0] = a_sub[0];
            ans->matrix[k][1] = a_sub[1];
            i++;
        }else{
            ans->matrix[k][0] = b_sub[0];
            ans->matrix[k][1] = b_sub[1];
            j++;
        }

        k++;

    }
    
    for(; i < a->size; i++){
        a_sub = a->matrix[i];
        ans->matrix[k][0] = a_sub[0];
        ans->matrix[k][1] = a_sub[1];
        k++;
    }

    for(; j < b->size; j++){
        b_sub = b->matrix[j];
        ans->matrix[k][0] = b_sub[0];
        ans->matrix[k][1] = b_sub[1];
        k++;
    }

    ans->size = k;

    return ans;
}

void printPoly(poly *a){

    for(int i = 0; i < a->size; i++){
        printf("%+dX^%d", a->matrix[i][0], a->matrix[i][1]);
    }
    printf("\n");

}


int main(){

    int order;
    printf("Polynomial 1\n");
    printf("Enter the highest order of the polynomial : ");
    scanf("%d", &order);
    poly* poly1 = initPoly(order);

    printf("Polynomial 2\n");
    printf("Enter the highest order of the polynomial : ");
    scanf("%d", &order);
    poly* poly2 = initPoly(order);

    printPoly(poly1);
    printPoly(poly2);
    printPoly(add(poly1, poly2));


    return 0;
}