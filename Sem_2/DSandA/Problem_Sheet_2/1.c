#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int m; // rows
    int n; // cols
    // Order : m x n
    int **elements;

}MATRIX;

void initMatrix(MATRIX *mat){

    int i,j;

    printf("Enter Rows (m) : ");
    scanf("%d", &mat->m);
    printf("Enter Cols (n) : ");
    scanf("%d", &mat->n);

    mat->elements = (int **) malloc(sizeof(int *) * mat->m);

    // mat->elements[m][n];
    printf("Enter the matrix elements...\n");
    for(i = 0; i < mat->m; i++){
        mat->elements[i] = (int *) malloc(sizeof(int) * mat->n);
        for(j = 0; j < mat->n; j++){
            scanf("%d", &mat->elements[i][j]);
        }
    }

}

void printMatrix(MATRIX *a){

    int i, j;
    for(i = 0; i < a->m; i++){
        for(j = 0; j < a->n; j++){
            printf("%d ", a->elements[i][j]);
        }
        printf("\n");
    }
    printf("( %d, %d )\n\n", a->m, a->n);

}

void freeMatrix(MATRIX *a){

    int i, j;

    for(i = 0; i < a->m; i++){
        free(a->elements[i]);
    }

    free(a->elements);
}

//-------------

int isIdentical(MATRIX *a, MATRIX *b){

    if(a->m != b->m || a->n != b->n){
        return 0;
    }

    int i, j;
    for(i = 0; i < a->m; i++){
        for(j = 0; j < b->n; j++){
            if(a->elements[i][j] != b->elements[i][j])
                return 0;
        }
    }

    return 1;

}

//-------------

int main(){


    MATRIX *a = (MATRIX *) malloc(sizeof(MATRIX));
    MATRIX *b = (MATRIX *) malloc(sizeof(MATRIX));

    printf("A : \n");
    initMatrix(a);

    printf("B : \n");
    initMatrix(b);

    int isId = isIdentical(a, b);

    printf("---\nINPUTS\n---\n");

    printf("A : \n");
    printMatrix(a);

    printf("B : \n");
    printMatrix(b);

    printf("---\nOUTPUT\n---\n");

    if(isId){
        
        printf("The Matrices are Identical\n");

    }else{
        
        if(a->n != b->n){
            printf("Order Mismatch ("
                    " %d != %d )\n", a->n, b->n);
        }else if(a->m != b->m){
            printf("Order Mismatch ("
                    " %d != %d )\n", a->m, b->m);
        }else{
            printf("The Matrices are not identical\n");
        }

    }

    freeMatrix(a);
    free(a);

    freeMatrix(b);
    free(b);

    return 0;

}