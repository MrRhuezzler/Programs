#include "stack.hpp"
#include <iostream>
#include <string>
#include <algorithm>

int preced(char c){

    if(c == '+' || c == '-') return 1;
    if(c == '*') return 2;
    if(c == '/') return 3;
    if(c == '^') return 4;

    return 0;
}


std::string inToPo(std::string infix){

    Stack<char> s(100);
    std::string postfix;

    for(char c : infix){

        if(isalnum(c)){
            postfix += c;
        }else if(c == '(') s.push(c);
        else if(c == ')'){
            if(!s.isempty()){
                while (s.top() != '(')
                {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
            }else{
                return "Invalid Infix Expression";
            }            
        }else{

            while (!s.isempty() && (preced(c) <= preced(s.top())))
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

std::string inToPr(std::string infix){

    std::string infixCopy = infix;

    reverse(infixCopy.begin(), infixCopy.end());
    reverse(infix.begin(), infix.end());

    for(int i = 0; i < infix.length(); i++){

        if(infix[i] == '(') infixCopy[i] = ')';
        if(infix[i] == ')') infixCopy[i] = '(';

    }

    std::string rev_pre = inToPo(infixCopy);
    reverse(rev_pre.begin(), rev_pre.end());

    return rev_pre;

}

int main(){

    std::string infix;
    std::cout << "Enter an expression : ";
    std::cin >> infix;

    std::cout << "Postfix : " << inToPo(infix) << std::endl;
    std::cout << "Prefix : " << inToPr(infix) << std::endl;

    return 0;
}