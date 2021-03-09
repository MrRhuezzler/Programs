// 9. Write a function that accepts either a pointer to C-string or a string object, as its
// argument. The function should return the character that appears most frequently in the
// string. Demonstrate the function in a complete program.

#include <iostream>
#include <string>

char frequentChar(std::string str){

    int length = str.length();

    char charArray[256] = {0};
    int max = 0;
    char freqChar;

    for(int i = 0; i < length; i++){
        charArray[str[i]]++;
        if(max < charArray[str[i]]){
            freqChar = str[i];
            max = charArray[str[i]];
        }
    }

    return freqChar;

}

int main(){

    std::string inp;
    std::cout << "Enter a string : ";
    std::cin >> inp;

    std::cout << "Frequent Char is : " << frequentChar(inp) << std::endl;
    
    return 0;
}