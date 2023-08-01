#include<iostream>

class ParentClass {
    public:
    float X, Y;
    void BringYourChild(float xa, float ya) {
        X = X + xa;
        Y = Y + ya;
    }
};

class ChildClass : public ParentClass {
    public:
    const char* Name;
    void PrintChildName() {
        std::cout << Name << std::endl;
    }
    void PrintSchoolCoordinate() {
        std::cout << X << std::endl;
        std::cout << Y << std::endl;
    }
};

int main() {

    ChildClass a;
    a.X = 10;
    a.Y = 15;
    a.BringYourChild(10.5, 15.5);
    a.Name = "Boby";
    a.PrintChildName();
    a.PrintSchoolCoordinate();
    std::cout << sizeof(ParentClass) << std::endl;
    std::cout << sizeof(ChildClass) << std::endl;
    
    std::cin.get();

}