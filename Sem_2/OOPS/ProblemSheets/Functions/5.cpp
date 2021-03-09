// 5. Write a C++ program to calculate the area of circle, rectangle and triangle using
// function overloading.
#include<iostream>
#define PI 3.14159

// Circle
double area(double radius){
    return PI * radius * radius;
}

// Rectangle
int area(int length, int breadth){
    return length * breadth;
}

// Triangle
double area(double height, double base){
    return 0.5 * height * base;
}

int main(){

    std::cout << "Area of a circle = " << area(2.0) << std::endl
              << "Area of a rectangle = " << area(2 , 3) << std::endl
              << "Area of a triangle = " << area(5.0, 5.0);



}

