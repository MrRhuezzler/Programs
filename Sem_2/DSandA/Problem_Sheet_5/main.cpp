#include <iostream>
#include "stack.hpp"

int main(){

    Stack s(10);

    for(int i = 0; i < 10; i++){
        s.push(i);
    }

    s.print();

    return 0;
}