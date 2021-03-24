#include "stack.hpp"
#include <iostream>
#include <string>

bool isBalancedBrackets(std::string input){

    Stack s(100);

    for(char c : input){

        if(c == '(' || c == '[' || c == '{'){
            s.push(c);
        }else{

            if(s.isempty()){
                return false;
            }

            if(c == ')' && s.top() == '('){
                s.pop();
            }else if(c == '}' && s.top() == '{'){
                s.pop();
            }else if(c == ']' && s.top() == '['){
                s.pop();
            }else{
                return false;
            }
        }
    }

    return s.isempty();
}


int main(){

    std::string input;
    std::cout << "Enter Bracket String : ";
    std::cin >> input;

    if(isBalancedBrackets(input)){
        std::cout << "Balanced !!";
    }else{
        std::cout << "UnBalanced !!";
    }

    return 0;
}