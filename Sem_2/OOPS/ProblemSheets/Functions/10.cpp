// 10. Write a program that accepts as input a sentence in which all of the words are run
// together, but the first character of each word is uppercase. Convert the sentence to a
// string in which the words are separated by spaces and only the first word stars with an
// uppercase letter. For example the string “StopAndSmellTheRoses.” would be
// converted to “Stop and smell the roses.”

#include <iostream>
#include <string>

std::string seperateWords(std::string str){

    std::string out = "";
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(isupper(str[i]) && i != 0){
            out += " ";
            out += tolower(str[i]);
        }else{
            out += str[i];
        }
    }

    return out;

}



int main(){

    std::string inp;
    std::cout << "Enter a string : ";
    std::cin >> inp;

    std::cout << "Fromatted : " << seperateWords(inp) << std::endl;

    return 0;
}