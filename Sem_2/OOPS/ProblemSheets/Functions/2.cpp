// 2. Raising a number n to a power p is the same as multiplying n by itself p times. Write a
// function called power() that takes a douult as a doubleble value for n and an int value for p, and
// returns the res value. Use a default argument of 2 for p, so that if this
// argument is omitted, the number n will be squared. Write a main() function that gets
// values from the user to test this function.

#include<iostream>

double power(double n, int p = 2){
    
    int answer = 1;
    for(int i = 0; i < p; i++){
        answer *= n;
    }

    return answer;
}

int main(){

    std::cout << "5 ^ 6 = "<< power(5, 6) << "\n2 ^ 2 = "<< power(2, 2) << std::endl;

    return 0;
}