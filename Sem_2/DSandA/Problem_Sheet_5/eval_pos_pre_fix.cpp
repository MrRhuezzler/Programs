#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "stack.hpp"

int evalPRE(std::string prefix){

    reverse(prefix.begin(), prefix.end());

    Stack<int> s(100);

    for(char c : prefix){

        if(isalnum(c)){
            s.push(c - '0');
        }else{

            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            int out;

            switch (c)
            {
            case '+':
                out = (a + b);
                break;
            case '-':
                out = (a - b);
                break;
            case '*':
                out = (a * b);
                break;
            case '/':
                out = (a / b);
                break;
            case '^':
                out = pow(a, b);
                break;
            }

            s.push(out);

        }

    }

    return s.top();

}


int evalPOS(std::string postfix){

    Stack<int> s(100);

    for(char c : postfix){

        if(isalnum(c)){
            s.push(c - '0');
        }else{

            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            int out;

            switch (c)
            {
            case '+':
                out = (a + b);
                break;
            case '-':
                out = (a - b);
                break;
            case '*':
                out = (a * b);
                break;
            case '/':
                out = (a / b);
                break;
            case '^':
                out = pow(a, b);
                break;
            }

            s.push(out);

        }

    }

    return s.top();

}


int main(){


    std::string input;

    int a;
    std::cout << "1) Prefix\n2) Postfix\nYour Choice : ";
    std::cin >> a;

    std::cout << "Enter the expression : ";
    std::cin >> input;

    std::cout << "Evaluated Result : ";
    if(a == 1) std::cout << evalPRE(input);
    else if(a == 2) std::cout << evalPOS(input);
    std::cout << std::endl;

    return 0;
}