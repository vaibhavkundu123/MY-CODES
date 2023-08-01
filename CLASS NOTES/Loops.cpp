#include<iostream>
#include"Log.cpp" 

int main() {

    /* int index = 0;
    for(; index < 5;) {
        Log("Hello world!");
        index++;
    } */

    /* int index = 0;
    bool condition = true;
    for(; condition;) {
        Log("Hello world!");
        index++;
        if(index == 5) {
            condition = false;
        }
    } */

    for(int index = 0; index < 5; index++) {
        /* if(index == 2)
            continue; */
        if(index == 3)
            break;
        std::cout << index << " - "; 
        Log("Hello world!");
    }

    /* Log("###################################");
    Log("Hello world!");
    Log("Hello world!");
    Log("Hello world!");
    Log("Hello world!");
    Log("Hello world!"); */

    std::cin.get();
}