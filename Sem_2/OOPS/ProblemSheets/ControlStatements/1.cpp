#include<iostream>
#include<cmath>

int main(){

    // 1. Given the following algebraic
    // expressions, write the equivalent C++ expressions

    // a. (w+x) / (y+2)+xt
    int w, x, y, t;
    std::cout << "a. " << ((w + x) / (y + 2)) + x * t << std::endl;

    // b. ax+bx-cx+d
    int a, b, c, d;
    std::cout << "b. "<< a * x + b * x - c * x + d << std::endl;

    // c. volume = length.width.height
    int length, width, height;
    std::cout << "c. Volume = " << length * width * height << std::endl;

    // d. force = mass.acceleration
    int mass, acceleration;
    std::cout << "d. force = " << mass * acceleration << std::endl;

    // e. h= flv / d^2 g
    int f, l, v, d, g;
    std::cout << "e. h = " << (f * l * v) / (d * d * g)<< std::endl;


    // f. q = k ^ (3/2)
    int k;
    std::cout << "f. q = " << pow(k , 3 / 2) << std::endl;


    // 2. Given the values of the int variables
    int a = 10, b = 6; // and float variables
    float x = 10.5, y = 12.0, w = 8.5; // determine
    // the value computed and the value
    // stored in each of the following
    // assignment statements. The variables
    // s,t,and r are type int, and l and m are
    // type float.
    // a. s=a-b*5-x/2+y;
    int s = a - (b * 5) - (x / 2) + y;
    // b. t=a*x+b-y/2;
    int t = a * x + b - (y / 2);
    // c. r = a/2+x+y;
    int r = (a / 2) + x + y;
    // d. l=a*5+b/2+x-y+w;
    float l = (a * 5) + (b / 2) + x - y + w;
    // e. m= x+a/2+b/y*5;
    float m = x + (a / 2) + (b / y) * 5;

    /* 3. Evaluate a && b ||(m < n) where */bool a = true;
    bool b = false; int m = 7, n = 9;
    std::cout << (a && b ||(m < n)) << std::endl;

    return 0;
}