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

MATRIX* add(MATRIX *a, MATRIX *b){

    if(a->m != b->m || a->n != b->n){
        return NULL;
    }

    int i, j;

    MATRIX *c = (MATRIX*) malloc(sizeof(MATRIX));
    c->m = a->m;
    c->n = b->n;

    c->elements = (int **) malloc(sizeof(int *) * c->m);

    for(i = 0; i < c->m; i++){
        c->elements[i] = (int *) malloc(sizeof(int) * c->n);
        for(j = 0; j < c->n; j++){
            c->elements[i][j] = a->elements[i][j] + b->elements[i][j];
        }
    }

    return c;

}

//-------------

int main(){

    MATRIX *a = (MATRIX *) malloc(sizeof(MATRIX));
    MATRIX *b = (MATRIX *) malloc(sizeof(MATRIX));

    printf("A : \n");
    initMatrix(a);

    printf("B : \n");
    initMatrix(b);

    MATRIX *c = add(a, b);

    printf("---\nINPUTS\n---\n");

    printf("A : \n");
    printMatrix(a);

    printf("B : \n");
    printMatrix(b);

    printf("---\nOUTPUT\n---\n");

    if(c != NULL){

        printf("C : \n");
        printMatrix(c);

        freeMatrix(c);
        free(c);

    }else{
        
        printf("Order Mismatch (");
        
        if(a->n != b->n){
            printf(" %d != %d )\n", a->n, b->n);
        }else{
            printf(" %d != %d )\n", a->m, b->m);
        }

    }

    freeMatrix(a);
    free(a);

    freeMatrix(b);
    free(b);

    return 0;
}