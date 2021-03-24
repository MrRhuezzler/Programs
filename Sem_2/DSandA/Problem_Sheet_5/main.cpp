#include <iostream>
#include "stack.hpp"

int main(){

    Stack s(10);

    for(int i = 0; i < 8; i++){
        s.push(i);
    }

    s.print();
    s.reverse();
    s.print();

    return 0;
}