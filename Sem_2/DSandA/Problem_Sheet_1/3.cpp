#include <bits/stdc++.h>

int findLastOccurance(std::vector<int> *array, int n, int value){

    for(int j = n - 1; j > -1; j--){
        if(value == array->at(j)){
            return j;
        }
    }

    return -1;

}


int main(){


    int n;
    std::cout << "Enter the total number of elements : ";
    std::cin >> n;

    std::vector<int> array(n);
    std::cout << "Enter the array values..." << std::endl;

    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }

    int value;
    std::cout << "Enter the value to find : ";
    std::cin >> value;

    int output;

    if((output = findLastOccurance(&array, n, value)) == -1){
        std::cout << "Element not found" << std::endl;
    }else{
        std::cout << "The Last Occurance of " << value << " is " << output << std::endl;
    }

    return 0;
}




















