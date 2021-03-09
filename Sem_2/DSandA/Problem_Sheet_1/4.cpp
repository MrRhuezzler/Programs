#include <bits/stdc++.h>
#include <cmath>

std::pair<int, int> findKey(std::vector<int> *array, int n, int key){

    int i,j;
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++){
            if(pow(array->at(i),2) + pow(array->at(j),2) == key){
                return {i,j};
            }
        }

    return {-1, -1};
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

    int key;
    std::cout << "Enter key : ";
    std::cin >> key;

    auto result = findKey(&array, n, key);

    if(result.first == -1 || result.second == -1){
        std::cout << "NOT FOUND";
    }else{
        std::cout << "FOUND\n"
                  << "(" << result.first << ", " << result.second << ")\n"
                  << "A[i] = " << array[result.first] << "\n"
                  << "A[j] = " << array[result.second] << "\n"
                  << array[result.first] << "^2" << " + " << array[result.second] << "^2" << " = " << key;
    }

    return 0;
}