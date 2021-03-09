#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
    int* elements;
    int totalSize;
    int currentSize;

} ARRAY;


int search(ARRAY *arr, int target){

    for(int i = 0; i < arr->currentSize; i++){
        if(arr->elements[i] == target){
            return i;
        }
    }

    return -1;

}

void delete(ARRAY *arr,int index){

    arr->currentSize--;

    for(int i = index; i < arr->currentSize + 1; i++){
        arr->elements[i] = arr->elements[i+1];
    }

}

void insert(ARRAY *arr, int element, int index){

    arr->currentSize++;

    // Logic to resize the array
    if(arr->currentSize > arr->totalSize){

        printf("[INFO] Array Size exceeded resizing !\n");

        arr->totalSize *= 2;
        int * temp = (int *) malloc(sizeof(int) * arr->totalSize);

        for(int i = 0; i < arr->currentSize - 1; i++){
            temp[i] = arr->elements[i];
        }
        free(arr->elements);

        arr->elements = temp;

    }

    // Logic to insert the element
    for(int i = arr->currentSize; i > index; i--){
        arr->elements[i] = arr->elements[i-1]; 
    }

    arr->elements[index] = element;


}

void initArray(ARRAY *arr, int n){
    arr->totalSize = n;
    arr->currentSize = n;
    arr->elements = (int *) malloc(sizeof(int) * arr->totalSize);
}

void printArray(ARRAY *arr){

    printf("ARRAY ELEMENTS : ");
    for(int i = 0; i < arr->currentSize; i++){
        printf("%d, ", arr->elements[i]);
    }
    printf("\n");

}

int main(){

    ARRAY *arr = (ARRAY *) malloc(sizeof(ARRAY));
    int n;

    printf("Enter the total number of entries : ");
    scanf("%d", &n);

    initArray(arr, n);

    printf("Enter the array elements : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr->elements[i]);
    }

    printArray(arr);

    int choice;

    do{

        printf("1) Insert\n2) Delete\n3) Search\n0) Quit\nYour Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int elem, ind;
                printf("What to insert : ");
                scanf("%d", &elem);
                printf("Where to insert : ");
                scanf("%d", &ind);
                insert(arr, elem, ind);
                printArray(arr);
                break;
            }
            case 2:
            {
                int index;
                printf("Where to delete : ");
                scanf("%d", &index);
                delete(arr, index);
                printArray(arr);
                break;
            }
            case 3:
            {
                int target;
                printf("What to search : ");
                scanf("%d", &target);

                int result = search(arr, target);

                if(result == -1){
                    printf("%d not found in the array\n", target);
                }else{
                    printf("%d is located at the index %d\n", target, result);
                }
                break;
            }
        }

    }while(choice);

    free(arr->elements);
    free(arr);

    return 0;
}