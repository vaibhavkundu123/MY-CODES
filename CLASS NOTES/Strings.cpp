#include<iostream>

int main() {
    const char* str = "Sunny";
    char str_arr[6] = { 'S', 'u', 'n', 'n', 'y', 0 };
    std::cout << str << std::endl;
    std::cout << str_arr << std::endl;

    std::string apna_naam = "Sunny";
    std::cout << apna_naam << std::endl;

    bool contain = apna_naam.find("ny") != std::string::npos;
    std::cout << contain << std::endl;

    bool contains = apna_naam.find("o") != std::string::npos;
    std::cout << contains << std::endl;

    std::cin.get();
}