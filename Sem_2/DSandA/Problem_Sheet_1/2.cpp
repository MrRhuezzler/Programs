#include <bits/stdc++.h>

int printPairs(std::vector<int> *array, int n){

    std::vector<std::pair<int, int>> seenItems;
    int totalCount = 0, i, j;

    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++){
            std::pair<int, int> p = {array->at(i) , array->at(j)};
            auto it = std::find(seenItems.begin(), seenItems.end(), p);
            if(it == seenItems.end()){
                std::cout << "(" << p.first << ", "<< p.second << ")" << ", ";
                totalCount++;
                seenItems.push_back(p);
            }
        }

    std::cout << std::endl;
    return totalCount;

}

int main(){

    int n, i, j;
    std::cout << "Enter the total number of elements : ";
    std::cin >> n;

    std::vector<int> array(n);

    std::cout << "Enter the array values..." << std::endl;
    for(i = 0; i < n; i++){
        std::cin >> array[i];
    }

    std::cout << printPairs(&array, n);
    return 0;
}