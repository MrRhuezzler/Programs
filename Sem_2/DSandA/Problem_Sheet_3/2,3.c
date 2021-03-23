#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int size;
    int **matrix;
    int m;
    int n;

}sparseMatrix;

sparseMatrix* initSparseMatrix(int k, int m, int n){

    sparseMatrix* temp = (sparseMatrix *) malloc(sizeof(sparseMatrix));

    temp->size = k;
    temp->m = m;
    temp->n = n;
    temp->matrix = (int **) malloc(k * sizeof(int *));

    for(int i = 0; i < k; i++){
        temp->matrix[i] = (int *) malloc(3 * sizeof(int));
    }

    return temp;

}

sparseMatrix* createSparseMatrix(int **elem, int m, int n){

    int k = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(elem[i][j] != 0){
                k++;
            }
        }
    }

    sparseMatrix *temp = initSparseMatrix(k, m, n);

    k = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(elem[i][j] != 0){
                temp->matrix[k][0] = i;
                temp->matrix[k][1] = j;
                temp->matrix[k][2] = elem[i][j];
                k++;
            }
        }
    }

    return temp;

}


sparseMatrix* addSparseMatrices(sparseMatrix *a, sparseMatrix *b){

    if(a->m != b->m || b->n != a->n){
        return NULL;
    }

    sparseMatrix *ans = initSparseMatrix(a->size + b->size, a->m, a->n);

    int i = 0;
    int j = 0;
    int k = 0;

    int *a_sub, *b_sub;

    while (i < a->size && j < b->size)
    {
        a_sub = a->matrix[i];
        b_sub = b->matrix[j];

        if(a_sub[0] == b_sub[0] && a_sub[1] == b_sub[1]){

            ans->matrix[k][0] = a_sub[0];
            ans->matrix[k][1] = a_sub[1];
            ans->matrix[k][2] = a_sub[2] + b_sub[2];

            i++;
            j++;
            k++;

        }else{

            if(a_sub[0] < b_sub[0]){

                ans->matrix[k][0] = a_sub[0];
                ans->matrix[k][1] = a_sub[1];
                ans->matrix[k][2] = a_sub[2];

                i++;
                k++;

            }else if(a_sub[0] > b_sub[0]){

                ans->matrix[k][0] = b_sub[0];
                ans->matrix[k][1] = b_sub[1];
                ans->matrix[k][2] = b_sub[2];

                j++;
                k++;

            }else{

                if(a_sub[1] < b_sub[1]){

                    ans->matrix[k][0] = a_sub[0];
                    ans->matrix[k][1] = a_sub[1];
                    ans->matrix[k][2] = a_sub[2];

                    i++;
                    k++;

                }else {

                    ans->matrix[k][0] = b_sub[0];
                    ans->matrix[k][1] = b_sub[1];
                    ans->matrix[k][2] = b_sub[2];

                    j++;
                    k++;

                }

            }
        }
    }

    for(; i < a->size; i++){
        a_sub = a->matrix[i];
        ans->matrix[k][0] = a_sub[0];
        ans->matrix[k][1] = a_sub[1];
        ans->matrix[k][2] = a_sub[2];
        k++;
    }


    for(; j < b->size; j++){
        b_sub = b->matrix[j];
        ans->matrix[k][0] = b_sub[0];
        ans->matrix[k][1] = b_sub[1];
        ans->matrix[k][2] = b_sub[2];
        k++;
    }

    ans->size = k;

    return ans;

}


void freeMatrix(sparseMatrix *sm){

    for(int i = 0; i < sm->size; i++){
        free(sm->matrix[i]);
    }

    free(sm->matrix);

}

void printSparseMatrix(sparseMatrix *sm){
    
    printf("I ");
    for(int i = 0; i < sm->size; i++){
        printf("%3d ", i);
    }
    printf("\nR ");

    for(int i = 0; i < sm->size; i++){
        printf("%3d ", sm->matrix[i][0]);
    }
    printf("\nC ");

    for(int i = 0; i < sm->size; i++){
        printf("%3d ", sm->matrix[i][1]);
    }
    printf("\nV ");

    for(int i = 0; i < sm->size; i++){
        printf("%3d ", sm->matrix[i][2]);
    }
    printf("\n");

}

int main(){

    // int m = 4, n = 5;
    // int sparse[4][5] = {{0,0,3,0,4},{0,0,5,7,0},{0,0,0,0,0},{0,2,6,0,0}};
    // int sparse2[4][5] = {{0,0,2,3,0},{0,0,6,2,7},{0,0,5,0,0},{0,2,6,0,0}};

    int rows1, rows2, cols1, cols2;

    printf("First Matrix\n");
    printf("Enter number of rows : ");
    scanf("%d", &rows1);
    printf("Enter number of cols : ");
    scanf("%d", &cols1);
    printf("Enter array elements...\n");
    int **elem = (int **) malloc(rows1 * sizeof(int *));
    for(int i = 0; i < rows1; i++){
        elem[i] = (int *) malloc(cols1 * sizeof(int));
        for(int j = 0; j < cols1; j++){
            scanf("%d", &elem[i][j]);
        }
    }

    printf("Second Matrix\n");
    printf("Enter number of rows : ");
    scanf("%d", &rows2);
    printf("Enter number of cols : ");
    scanf("%d", &cols2);
    printf("Enter array elements...\n");
    int **elem2 = (int **) malloc(rows2 * sizeof(int *));
    for(int i = 0; i < rows2; i++){
        elem2[i] = (int *) malloc(cols2 * sizeof(int));
        for(int j = 0; j < cols2; j++){
            scanf("%d", &elem2[i][j]);
        }
    }


    sparseMatrix *left = createSparseMatrix(elem, rows1, cols1);
    sparseMatrix *right = createSparseMatrix(elem2, rows2, cols2);

    sparseMatrix *sm = addSparseMatrices(left, right);

    printSparseMatrix(left);
    printf("\n");    
    printSparseMatrix(right);
    printf("\n");

    if (sm != NULL){
        printSparseMatrix(sm);
        printf("\n");
        freeMatrix(sm);
        free(sm);
    }else{
        printf("Orders don't match !\n");
    }


    freeMatrix(left);
    free(left);

    freeMatrix(right);
    free(right);

    return 0;
}