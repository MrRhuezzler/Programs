#include <bits/stdc++.h>

int slopeChanges(std::vector<int> *array, int n){

    bool flag = false;

    for(int i = 1; i < n - 1; i++){

        if(((array->at(i - 1) < array->at(i)) && (array->at(i) > array->at(i + 1)))){
            return i;
        }else if(((array->at(i - 1) > array->at(i)) && (array->at(i) < array->at(i + 1)))){
            flag = true;
        }

    }

    if(!flag){
        if(array->at(0) > array->at(1)){
            return 0;
        }else{
            return n - 1;
        }
    }else{
        return -1;
    }
    
}


int main(){

    int n;
    std::cout << "Enter the total number of elements : ";
    std::cin >> n;

    std::vector<int> array(n);

    std::cout << "Enter the array value..." << std::endl;

    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }

    int output;

    if((output = slopeChanges(&array, n)) == -1){
        std::cout << "k doesn't exists";
    }else{
        std::cout << "k = " << output << " Satisfies Increasing sequence is given as A[0]...A[k] and decreasing sequence is given as A[k+1]...A[n-1].";
    }
    

    return 0;
}