#include "stack.hpp"
#include <iostream>

Stack::Stack(int n)
:n(n), t(-1)
{

    arr = new char[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }

}

Stack::~Stack(){
    delete[] arr;
}

void Stack::push(char elem){

    if(!isfull()){
        arr[++t] = elem;
    }else{
        std::cout << "[ERROR] Stack Overflow, when trying to push " << elem << std::endl;
    }

}

void Stack::pop(){

    if(!isempty()){
        t--;
    }else{
        std::cout << "[ERROR] Stack Underflow, when trying to pop" << std::endl;
    }

}

char Stack::top(){

    if(!isempty()){
        return arr[t];
    }
    exit(0);

}

int Stack::size(){
    return t + 1;
}

bool Stack::isfull(){
    return t == n - 1;
}

bool Stack::isempty(){
    return t == -1;
}

void Stack::print(){
    for(int i = 0; i < size(); i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

void Stack::reverse(){

    int *temp = new int[n];
    int n = size();

    for(int i = 0; i < n; i++){
        temp[i] = top();
        pop();
    }

    for(int i = 0; i < n; i++){
        push(temp[i]);
    }

    delete[] temp;

}
