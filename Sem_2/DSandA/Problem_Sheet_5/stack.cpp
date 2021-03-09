#include "stack.hpp"
#include <iostream>

Stack::Stack(int n)
:n(n), t(-1)
{

    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }

}

Stack::~Stack(){
    delete[] arr;
}

void Stack::push(int elem){
    
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

int Stack::top(){
    
    if(!isempty()){
        return arr[t];
    }else{
        std::cout << "[ERROR] Stack is empty !" << std::endl;
    }

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