#include<iostream>

int main() {

    // Stack Memory

    int array[8];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;
    array[6] = 7;
    array[7] = 8;

    for(int index = 0; index < 8; index++) {
        array[index] = index + 1;
    }

    std::cout << array[4] << std::endl;

    // Heap Memory
    
    int* array2 = new int[8];
    *(array2 + 0) = 1;
    *(array2 + 1) = 2;
    *(array2 + 2) = 3;
    *(array2 + 3) = 4;
    *(array2 + 4) = 5;
    *(array2 + 5) = 6;
    *(array2 + 6) = 7;
    *(array2 + 7) = 8;

    for(int index = 0; index < 8; index++) {
        *(array2 + index) = index + 1;
    }

    std::cout << *(array2 + 4) << std::endl;

    std::cin.get();
}