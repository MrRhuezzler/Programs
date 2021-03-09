#include<stdio.h>
#include<stdlib.h>

typedef struct {

    int size;
    int *elements;

} S_SET;

void singleMerger(int *array, int low, int high, int mid){
    
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));
    int i = low;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= high){
        if(array[i] < array[j]){
            temp[k++] = array[i++];
        }else{
            temp[k++] = array[j++];
        }
    }

    for(; i <= mid; i++){
        temp[k++] = array[i];
    }

    for(; j <= high; j++){
        temp[k++] = array[j];
    }

    for(i = low; i <= high; i++){
        array[i] = temp[i - low];
    }


}

void mergeSort(int *array, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        singleMerger(array, low, high, mid);
    }

}


int removeDuplicates(int *elements, int size){

    int i,j,k;

    for(i = 0; i < size; i++){
        for(j = i + 1; j < size; j++){
            if(elements[i] == elements[j]){
                for(k = j; k < size - 1; k++){
                    elements[k] = elements[k + 1];
                }
                size--;
                j--;
            }
        }
    }

    return size;

}

int* merger(int *a, int *b, int a_size, int b_size, int *outputSize){

    int *temp = (int *)malloc((a_size + b_size) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while(i < a_size && j < b_size){
        if(a[i] < b[j]){
            temp[k] = a[i];
            k++;
            i++;
        }else if(a[i] > b[j]){
            temp[k] = b[j];
            k++;
            j++;
        }else{
            temp[k] = a[i];
            i++;
            j++;
            k++;
        }
    }

    for(; i < a_size; i++){
        temp[k++] = a[i];
    }

    for(; j < b_size; j++){
        temp[k++] = b[j];
    }

    if(k <= 10){
        *outputSize = k;
        return temp;
    }else{
        *outputSize = 0;
        free(temp);
        return NULL;
    }

}

S_SET* _createSet(int *elements, int size){

    S_SET *temp = (S_SET*)malloc(sizeof(S_SET));
    temp->size = size;
    temp->elements = (int *)malloc(sizeof(int) * size);

    for(int i = 0; i < temp->size; i++){
        temp->elements[i] = elements[i];
    }

    return temp;

}

S_SET* createSet(int *elements, int size){

    int i;
    S_SET* temp;

    size = removeDuplicates(elements, size);

    if(size > 10){
        return NULL;
    }

    mergeSort(elements, 0, size - 1);
    
    return _createSet(elements, size);

}

S_SET* setUnion(S_SET *a, S_SET *b){

    int outputSize;
    int* result = merger(a->elements, b->elements, a->size, b->size, &outputSize);

    if(outputSize > 0){
        return _createSet(result, outputSize);
    }else{
        return NULL;
    }

}

void printSet(S_SET *set){

    for(int i = 0; i < set->size - 1; i++){
        printf("%d, ", set->elements[i]);
    }
    printf("%d\n", set->elements[set->size]);

}

void freeMem(S_SET *set){
    free(set->elements);
    free(set);
}

int main(){

    int A_elements[10] = {2, 1, 4, 3, 5, 6, 6, 6};
    S_SET *a = createSet(A_elements, 8);

    int B_elements[10] = {2, 1, 4, 3, 5, 6, 7, 6};
    S_SET *b = createSet(B_elements, 8);

    S_SET *c = setUnion(a, b);


    printf("A : ");
    printSet(a);
    printf("B : ");
    printSet(b);
    printf("C : ");
    printSet(c);

    freeMem(a);
    freeMem(b);
    freeMem(c);

    return 0;
}