#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int m; // rows
    int n; // cols
    // Order : m x n
    int **elements;

}MATRIX;

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

MATRIX* mult(MATRIX *a, MATRIX *b){

    if(a->n != b->m){
        return NULL;
    }

    MATRIX *c = (MATRIX*) malloc(sizeof(MATRIX));
    c->m = a->m;
    c->n = b->n;

    c->elements = (int **) malloc(sizeof(int *) * c->m);

    int i, j, k, sum;
    for(i = 0; i < c->m; i++){
        c->elements[i] = (int *) malloc(sizeof(int) * c->n);
        for(j = 0; j < c->n; j++){
            sum = 0;
            for(k = 0; k < a->n; k++){
                sum += (a->elements[i][k] * b->elements[k][j]);
            }
            c->elements[i][j] = sum;
        }
    }

    return c;

}

void clearAdj(MATRIX *a, int i, int j){

    if(i < 0 || i >= a->m || j < 0 || j >= a->n || a->elements[i][j] == 0){
        return;
    }

    a->elements[i][j] = 0;
    clearAdj(a, i + 1, j);
    clearAdj(a, i - 1, j);
    clearAdj(a, i, j + 1);
    clearAdj(a, i, j - 1);
    clearAdj(a, i - 1, j - 1);
    clearAdj(a, i + 1, j + 1);
    clearAdj(a, i - 1, j + 1);
    clearAdj(a, i + 1, j - 1);

}

int findIslands(MATRIX *a){

    int i, j, count = 0;
    for(i = 0;i < a->m; i++){
        for(j = 0; j < a->n; j++){
            if(a->elements[i][j] == 1){
                count++;
                clearAdj(a, i, j);
            }
        }
    }

    return count;
}


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



int main(){

    int choice;

    MATRIX *a, *b, *c;

    do{

        printf("---\nMatrix Operations\n---\n");
        
        printf("1) M-Identical\n"
               "2) M-Addition\n"
               "3) M-Multiplication\n"
               "4) Island\n"
               "5) Quit\n"
               "Choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {

                a = (MATRIX *) malloc(sizeof(MATRIX));
                b = (MATRIX *) malloc(sizeof(MATRIX));

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

            }
                break;

            case 2:
            {

                a = (MATRIX *) malloc(sizeof(MATRIX));
                b = (MATRIX *) malloc(sizeof(MATRIX));

                printf("A : \n");
                initMatrix(a);

                printf("B : \n");
                initMatrix(b);

                c = add(a, b);

                if(c != NULL){

                    printf("---\nINPUTS\n---\n");

                    printf("A : \n");
                    printMatrix(a);

                    printf("B : \n");
                    printMatrix(b);

                    printf("---\nOUTPUT\n---\n");
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

            }
                break;
            case 3:
            {

                a = (MATRIX *) malloc(sizeof(MATRIX));
                b = (MATRIX *) malloc(sizeof(MATRIX));

                printf("A : \n");
                initMatrix(a);
                
                printf("B : \n");
                initMatrix(b);

                c = mult(a, b);

                if(c != NULL){
                    
                    printf("---\nINPUTS\n---\n");

                    printf("A : \n");
                    printMatrix(a);

                    printf("B : \n");
                    printMatrix(b);

                    printf("---\nOUTPUT\n---\n");
                    printf("C : \n");
                    printMatrix(c);                    

                    freeMatrix(c);
                    free(c);

                }else{
                    printf("Order Mismatch ( %d != %d )\n", a->n, b->m);
                }

                freeMatrix(a);
                free(a);

                freeMatrix(b);
                free(b);

            }
                break;

            case 4:
            {

                a = (MATRIX *) malloc(sizeof(MATRIX));
                printf("Island Matrix : \n");
                initMatrix(a);

                int count = findIslands(a);
                printf("The Number of Islands is : %d\n", count);

                freeMatrix(a);
                free(a);

            }
                break;
        }

    }while(choice != 5);

    return 0;
}