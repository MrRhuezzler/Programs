#include <iostream>
#include <string>
#include <algorithm>
#include "stack.hpp"

std::string prToIn(std::string prefix){

    reverse(prefix.begin(), prefix.end());

    Stack<std::string> s(100);

    for(char c : prefix){

        if(isalnum(c)){
            s.push(std::string(1, c));
        }else{
            std::string temp;

            std::string o1 = s.top(); s.pop();
            std::string o2 = s.top(); s.pop();

            temp += "(";
            temp += o1;
            temp += c;
            temp += o2;
            temp += ")";

            s.push(temp);

        }

    }

    return s.top();

}


int main(){


    std::string prefix;

    std::cout << "Enter the prefix expression : ";
    std::cin >> prefix;

    std::cout << "Infix Notation : " << prToIn(prefix) << std::endl;


    return 0;
}