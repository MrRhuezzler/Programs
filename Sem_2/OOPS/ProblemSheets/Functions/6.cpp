// 6. Write a program that has a overloaded functions with the appropriate arguments to do
// the following.
#include <iostream>
#include <string>

typedef struct {
    int a;
    int b;
}ex;

// a) Swap two integers
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

// b) Swap two float values
void swap(float *a, float *b){
    float c = *a;
    *a = *b;
    *b = c;
}

// c) Swap two double values
void swap(double *a, double *b){
    double c = *a;
    *a = *b;
    *b = c;
}

// d) Swap two characters
void swap(char *a, char *b){
    char c = *a;
    *a = *b;
    *b = c;
}

// e) the swap() function inter-change two struct time values
void swap(ex *a, ex *b){
    ex c = *a;
    *a = *b;
    *b = c;
}

std::string ex_tostring(ex *s){
    std::string out = "A : ";
    out += std::to_string(s->a);
    out += " B: ";
    out += std::to_string(s->b);

    return out;
}

int main(){

    std::cout << "Ints" << std::endl;
    int a = 1, b = 2;
    std::cout << "Input : a = " << a << " | b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "Output : a = " << a << " | b = " << b << std::endl;

    std::cout << "Floats" << std::endl;
    float c = 2.0, d = 3.0;
    std::cout << "Input : a = " << c << " | b = " << d << std::endl;
    swap(&c, &d);
    std::cout << "Output : a = " << c << " | b = " << d << std::endl;

    std::cout << "Doubles" << std::endl;
    double e = 6.0, f = 7.0;
    std::cout << "Input : a = " << e << " | b = " << f << std::endl;
    swap(&e, &f);
    std::cout << "Output : a = " << e << " | b = " << f << std::endl;

    std::cout << "Structs" << std::endl;
    ex h = {5, 10}, i = {20, 30};
    std::cout << "Input : a = " << ex_tostring(&h) << " | b = " << ex_tostring(&i) << std::endl;
    swap(&h, &i);
    std::cout << "Output : a = " << ex_tostring(&h) << " | b = " << ex_tostring(&i) << std::endl;






}