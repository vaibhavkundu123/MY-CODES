#include<iostream>
#include"Log.cpp" 

int main() {

    int number = 9;
    int* ptr = &number ;
    int* nptr = nullptr;
    std::cout << ptr << std::endl;
    std::cout << nptr << std::endl;
    std::cout << *ptr << std::endl;
    *ptr = 10;
    std::cout << *ptr << std::endl;
    int** ptr_to_ptr = &ptr;
    std::cout << ptr_to_ptr << std::endl;
    std::cout << *ptr_to_ptr << std::endl;
    std::cout << **ptr_to_ptr << std::endl;

    std::cin.get();
}