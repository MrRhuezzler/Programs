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

MATRIX * transpose(MATRIX *a){

    if(a->m != a->n){
        return NULL;
    }

    MATRIX *b = (MATRIX *) malloc(sizeof(MATRIX));
    b->n = a->n;
    b->m = a->m;

    int i, j;

    b->elements = (int **) malloc(sizeof(int *) * b->m);

    for(i = 0; i < b->m; i++){
        b->elements[i] = (int *) malloc(sizeof(int) * b->n);
        for(j = 0; j < b->n; j++){
            b->elements[i][j] = a->elements[j][i];
        }
    }

    return b;

}

//-------------

int main(){

    MATRIX *a = (MATRIX *) malloc(sizeof(MATRIX));
    printf("A : \n");
    initMatrix(a);

    MATRIX *b = transpose(a);

    printf("---\nINPUTS\n---\n");

    printf("A : \n");
    printMatrix(a);

    printf("---\nOUTPUT\n---\n");

    if(b != NULL){
        printf("Transpose : \n");
        printMatrix(b);
    }else{
        printf("Input must be a square matrix.\n");
    }

    freeMatrix(a);
    free(a);

    freeMatrix(b);
    free(b);

    return 0;
}