#include <iostream>
#include <algorithm>
#include <vector>

int main() {

    int n;
    std::cout << "Enter the number of toys: ";
    std::cin >> n;

    std::vector<int> w;
    w.resize(n);
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        w.push_back(x);
    }

    return 0;
}