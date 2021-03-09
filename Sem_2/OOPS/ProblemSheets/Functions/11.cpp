// 11. Write a program that asks a user to enter a part number to order. The rules for
// creating a part number are as follows:
// » The first character must be an ‘A’, ‘B’, or ‘C’.
// » The second and third characters must be numeric; their value when taken as
// a pair must be between 10 and 49.
// » The fourth character must be a lowercase letter.
// » The fifth and sixth characters must be numeric; their values when taken as a
// pair must be between 22 and 66.

// Display a message indicating whether the entered part number is or is not valid.
#include <iostream>

bool isValid(std::string part){

    if(part.length() != 6){
        return false;
    }

    if(!(part[0] == 'A' || part[0] == 'B' || part[0] == 'C')){
        return false;
    }

    if(!(isdigit(part[1]) && isdigit(part[2]))){
        return false;
    }

    int num = ((part[1] - '0') * 10) + (part[2] - '0');
    if(num < 10 || num > 49){
        return false;
    }

    if(!(islower(part[3]))){
        return false;
    }

    if(!(isdigit(part[4]) && isdigit(part[5]))){
        return false;
    }

    num = (part[4] - '0') * 10 + (part[5] - '0');
    if(num < 22 || num > 66){
        return false;
    }

    return true;
}

int main(){

    std::string inp;
    std::cout << "Enter a string : ";
    std::cin >> inp;

    std::cout << "IsValid : " << isValid(inp) << std::endl;

    return 0;
}
