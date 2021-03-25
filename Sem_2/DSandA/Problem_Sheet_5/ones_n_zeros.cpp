#include "stack.hpp"
#include <iostream>
#include <string>

bool ones_n_zeros(std::string input){

    Stack<char> s(100);

    for(char c : input){
        if(!s.isempty()){
            if((c == '1' && s.top() == '0') || (c == '0' && s.top() == '1')){
                s.pop();
            }
        }else{
            s.push(c);
        }
    }

    return s.isempty();

}

int main(){

    std::string input;
    std::cout << "Enter 1's n 0's String : ";
    std::cin >> input;

    if(ones_n_zeros(input)){
        std::cout << "Balanced !" << std::endl;
    }else{
        std::cout << "UnBalanced !" << std::endl;
    }

    return 0;
}
