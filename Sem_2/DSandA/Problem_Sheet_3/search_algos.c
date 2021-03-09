#include <stdio.h>
#include <stdlib.h>

#define printArray(a, n) for(int i = 0; i < n; i++){printf("%d, ", a[i]);} printf("\n");

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}


// a. Linear Search
// b. Binary Search
// c. Insertion Sort
// d. Bubble Sort
// e. Selection Sort
// f. Merge Sort
// g. Quick Sort
// h. Radix Sort

void bubbleSort(int *elem, int n){
    
    int i, j;
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(elem[i] > elem[i + 1]) swap(&elem[i], &elem[i+1]);
        }
    }

}

void insertionSort(int *elem, int n){

    int i, seeing, j;
    for(i = 1; i < n; i++){

        seeing = elem[i];
        j = i;
        while(seeing <= elem[j] && j > 0){
            elem[j] = elem[j - 1];
            j--;
        }

        elem[j] = seeing;

    }

}


void selectionSort(int *elem, int n){

    int i,j,currentMin;
    for(i = 0; i < n; i++){
        currentMin = i;
        for(j = i + 1; j < n; j++){
            if(elem[j] < elem[currentMin]){
                currentMin = j;
            }
        }
        swap(&elem[currentMin], &elem[i]);
    }

}

void merging(int *elem, int low, int mid, int high){

    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    int i = low;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= high){
        if(elem[i] > elem[j]){
            temp[k++] = elem[j];
            j++;
        }else{
            temp[k++] = elem[i];
            i++;
        }
    }

    for(;i <= mid; i++){
        temp[k++] = elem[i];
    }

    for(;j <= high; j++){
        temp[k++] = elem[j];
    }

    for(i = low; i <= high; i++){
        elem[i] = temp[i - low];
    }

}

void mergeSort(int *elem, int low, int high){

    if(low < high){

        int mid = (high + low) / 2;

        mergeSort(elem, low , mid);
        mergeSort(elem, mid + 1, high);

        merging(elem, low, mid, high);

    }


}

int partition (int* elem, int lo, int hi) 
{ 
    int pivot = elem[hi];
    int i = (lo - 1);
 
    for (int j = lo; j <= hi - 1; j++) 
    { 
        if (elem[j] < pivot) 
        { 
            i++;
            swap(&elem[i], &elem[j]); 
        } 
    } 
    swap(&elem[i + 1], &elem[hi]); 
    return (i + 1); 
} 
 

void quickSort(int *elem, int lo, int hi) 
{ 
    if (lo < hi) 
    { 
        int p = partition(elem, lo, hi);
        quickSort(elem, lo, p - 1); 
        quickSort(elem, p + 1, hi); 
    } 
}



int maxOf(int *elem, int n) 
{ 
    int max_ = elem[0]; 
    for (int i = 1; i < n; i++) 
        if (elem[i] > max_) 
            max_ = elem[i]; 
    return max_; 
} 
  

void arangIndices(int *elem, int n, int exp) 
{ 
    int *output = (int *) malloc(sizeof(int) * n);
    int i, count[10] = { 0 };
  
    for (i = 0; i < n; i++) 
        count[(elem[i] / exp) % 10]++; 

    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 

    for (i = n - 1; i >= 0; i--) { 
        output[count[(elem[i] / exp) % 10] - 1] = elem[i]; 
        count[(elem[i] / exp) % 10]--; 
    } 

    for (i = 0; i < n; i++) 
        elem[i] = output[i];

    free(output);
} 
  

void radixsort(int arr[], int n) 
{ 
    int m = maxOf(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) 
        arangIndices(arr, n, exp); 
} 




int linearSearch(int *elem, int n, int target){

    for(int i = 0; i < n; i++){
        if(elem[i] == target) return i;
    }

    return -1;
}

int binarySearch(int *elem, int n, int target){

    int hi = n, lo = 0;
    int mid = (hi - lo) / 2;

    while(hi > lo){

        if(elem[mid] > target){
            hi = mid;
        }else if(elem[mid] == target){
            return mid;
        }else{
            lo = mid;
        }

    }

    return -1;
}

int main(){

    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    printf("Enter the array elements...\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    printArray(array, n);

    quickSort(array, 0, n - 1);

    printArray(array, n);


    return 0;
}