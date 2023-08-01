#include<iostream>

int main() {
    const int MAX_AGE = 90;
    // int MAX_AGE = 90;

    int* a = new int;
    // const int* a = new int;
    // int* const a = new int;
    // const int* const a = new int;
    *a = 2;

    a = (int*) &MAX_AGE;
    std::cout << a << std::endl;
    std::cout << *a << std::endl;

    std::cin.get();




}