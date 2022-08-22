// Implement Karatsuba’s large integer multiplication

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

int add(std::string a, std::string b)
{
    return std::stoi(a) + std::stoi(b);
}

int multiply(std::string a, std::string b)
{

    int a_size = a.size();
    int b_size = b.size();

    while (a_size > b_size)
    {
        b = "0" + b;
        b_size++;
    }

    while (b_size > a_size)
    {
        a = "0" + a;
        a_size++;
    }


    if (a_size == 1 && b_size == 1)
    {
        return std::stoi(a) * std::stoi(b);
    }

    std::string a_l = a.substr(0, a_size / 2);
    std::string a_r = a.substr(a_size / 2, (a_size / 2) + 1);

    std::string b_l = b.substr(0, b_size / 2);
    std::string b_r = b.substr(b_size / 2, (b_size / 2) + 1);

    std::cout << a_l << " | " << a_r << " || " << b_l << " | " << b_r << std::endl;

    // (Al + Ar)*(Bl + Br)
    int p = multiply(std::to_string(add(a_l, a_r)), std::to_string(add(b_l, b_r)));
    // Al*Bl
    int q = multiply(a_l, b_l);
    // Ar*Br 
    int r = multiply(a_r, b_r);

    return q * powl(10, a_size) + (p - q - r) * powl(10, a_size / 2) + r;
    // return 0;
}

int main()
{

    std::cout << multiply("123455", "1234") << std::endl;

    return 0;
}