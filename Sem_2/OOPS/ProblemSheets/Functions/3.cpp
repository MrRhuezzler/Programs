// 3. Write a function that accepts two parameters: a string name of a movie and an integer
// running time in minutes. Provide a default value for the minutes so that if you call the
// function without an integer argument, the minutes default to 90. Write a main()
// function that proves you can call the function with a string argument alone as well as
// with a string and an integer.

#include <iostream>
#include <string>

void printMoive(std::string movie, int minutes = 90){
    std::cout << "Name : " << movie << "\nMinutes : " << minutes << std::endl;
}

int main(){

    printMoive("Endgame");
    printMoive("Startgame", 120);

    return 0;
}


