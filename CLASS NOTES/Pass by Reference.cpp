#include<iostream>
#include"Log.cpp" 

/* int IncreaseValue(int* value) {
    (*value)++;
    std::cout << *value << std::endl;
} */

int IncreaseValue(int& value) {
    value++;
    std::cout << value << std::endl;
}

int main() {

    int number = 9;
    /* int* ptr = &number;
    int& ref = number;
    std::cout << ref << std::endl;
    ref = 15;
    std::cout << number << std::endl; */

    /* int ans = IncreaseValue(&number);
    std::cout << number << std::endl; */

    int ans = IncreaseValue(number);
    std::cout << number << std::endl;

    std::cin.get();
} 