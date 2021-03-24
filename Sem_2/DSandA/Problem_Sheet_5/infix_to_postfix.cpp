#include "stack.hpp"
#include <iostream>
#include <string>

int preced(char c){

    if(c == '+' || c == '-') return 1;
    if(c == '*') return 2;
    if(c == '/') return 3;
    if(c == '^') return 4;

    return 0;
}


std::string inToPo(std::string infix){

    Stack s(100);
    std::string postfix;

    for(char c : infix){

        if(isalnum(c)){
            postfix += c;
        }else if(c == '(') s.push(c);
        else if(c == ')'){

            while (!s.isempty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            
        }else{

            while (preced(c) <= preced(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            
            s.push(c);
        }

    }

    while (!s.isempty())
    {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;

}

int main(){

    std::string infix;
    std::cout << "Enter an expression : ";
    std::cin >> infix;

    std::cout << "Postfix : " << inToPo(infix) << std::endl;

    return 0;
}