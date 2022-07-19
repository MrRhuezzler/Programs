#include <iostream>
#include <vector>
#define ROWS 4
#define COLS 4

int main() {

    int array[ROWS][COLS];

    std::cout << "Enter array : " << std::endl;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            std::cin >> array[i][j];
        }
    }

    int find;
    std::cout << "Enter a element to find : ";
    std::cin >> find;

    int currentI = 0;
    int currentJ = COLS - 1;
    bool flag = false;

    while(currentI > -1 && currentI < ROWS && currentJ > -1 && currentJ < COLS) {
        if(array[currentI][currentJ] < find) {
            currentI++;
        } else if(array[currentI][currentJ] > find) {
            currentJ--;
        } else {
            flag = true;
            break;
        }
    }

    if(flag) {
        std::cout << "Element " << find << " found at " << currentI << ", " << currentJ << std::endl;
    } else {
        std::cout << "No Element was found !" << std::endl;
    }

    return 0;
}