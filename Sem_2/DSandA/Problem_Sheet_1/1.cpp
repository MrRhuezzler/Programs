#include <iostream>

int main(){

    int array[100];
    int n, k, l, r;
    
    std::cout << "Enter the total number of elements : ";
    std::cin >> n;

    std::cout << "Enter the array elements..." << std::endl;
    
    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }

    std::cout << "Enter k, l, r values : ";
    std::cin >> k >> l >> r;

    if(r < l || k > (r - l) || k <= 0){
        std::cout << "error in the inputs, please check the inputs" << std::endl;
    }else{
        std::cout << array[l + k - 1];
    }

    return 0;
}