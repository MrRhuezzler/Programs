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

void clearAdj(MATRIX *a, int i, int j){

    if(i < 0 || i >= a->m || j < 0 || j >= a->n || a->elements[i][j] == 0){
        return;
    }

    a->elements[i][j] = 0;
    // Adjacent
    clearAdj(a, i + 1, j);
    clearAdj(a, i - 1, j);
    clearAdj(a, i, j + 1);
    clearAdj(a, i, j - 1);
    // Diagonals
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

//-------------

int main(){

    MATRIX *a = (MATRIX *) malloc(sizeof(MATRIX));
    printf("Island Matrix : \n");
    initMatrix(a);

    int count = findIslands(a);
    printf("The Number of Islands is : %d\n", count);

    freeMatrix(a);
    free(a);

    return 0;
}