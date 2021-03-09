// 1. Write a function that, when you call it, displays a message telling how many times it
// has been called: “I have been called 3 times”, for instance. Write a main() program
// that calls this function at least 10 times. Try implementing this function in two
// different ways. First, use a global variable to store the count. Second, use a local static
// variable. 
// Which is more appropriate? Second Method
// Why can’t you use a local variable?
// The Stack Frame is created each time, which indeed resets the local variables.


#include<iostream>

int times;
void functionUsingGlobalVar(){
    ::times++;
    std::cout << "GV> I have been called " << ::times << " times" << std::endl;
}

// This is more appropriate, because this is going to local to this function
// and can used for many functions, the above method is not appropriate because global variables
// can be changed my other functions.
void functionUsingStaticVar(){

    static int times = 0;
    times++;
    std::cout << "SV> I have been called " << times << " times" << std::endl;

}

int main(){

    for(int i = 0; i < 10; i++){
        functionUsingGlobalVar();
    }
    
    for(int i = 0; i < 10; i++){
        functionUsingStaticVar();
    }

    return 0;
}

