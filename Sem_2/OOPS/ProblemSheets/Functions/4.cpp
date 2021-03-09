// 4. Write a function called zeroSmaller() that is passed two int arguments by reference
// and then sets the smaller of the two numbers to 0. Write a main() program to exercise
// this function.

#include <iostream>


void zeroSmaller(int &a, int &b){

    if(a < b){
        a = 0;
    }else{
        b = 0;
    }

}

int main(){

    int a, b;

    a = 5;
    b = 4;
    std::cout << "Input : a = "<< a << " " << " b = " << b << std::endl;
    zeroSmaller(a, b);
    std::cout << "Output : a = "<< a << " " << " b = " << b << std::endl;

    return 0;
}



