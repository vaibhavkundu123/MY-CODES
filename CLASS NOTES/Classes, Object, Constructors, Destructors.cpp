#include<bits/stdc++.h>
using namespace std;

/* class Student{
    public:
    string Name;
    int Roll;
    bool Gender;
    void PrintInformation() {
        cout << "Name: " << Name << endl;
        cout << "Roll: " << Roll << endl;
        cout << "Gender: " << Gender << endl;
    }
}; */

/* class Student{
    string Name;
    public:
    void SetNewName(string s) {
        Name = s;
    }
    int Roll;
    bool Gender;
    void PrintInformation() {
        cout << "Name: " << Name << endl;
        cout << "Roll: " << Roll << endl;
        cout << "Gender: " << Gender << endl;
    }
}; */

class Student{
    public:
    string Name;
    int Roll;
    bool Gender;
    Student() {
        cout << "Default Constructor" << endl;
    }
    Student(string n, int r, bool g) {
        Name = n;
        Roll = r;
        Gender = g;
        cout << "Parameterized Constructor" << endl;
    }
    Student(Student &C) {
        Name = C.Name;
        Roll = C.Roll;
        Gender = C.Gender;
        cout << "Copy Constructor" << endl;
    }
    ~Student() {
        cout << "Destructor" << endl;
    }
    void PrintInformation() {
        cout << "Name: " << Name << endl;
        cout << "Roll: " << Roll << endl;
        cout << "Gender: " << Gender << endl;
    }
}; 

int main() {
    
    /* Student A;
    A.Name = "Raju";
    A.Roll = 10;
    A.Gender = false;
    A.PrintInformation();
    
    Student B;
    B.Name = "Kaju";
    B.Roll = 2;
    B.Gender = false;
    B.PrintInformation();
    
    Student C;
    C.Name = "Saheli";
    C.Roll = 1;
    C.Gender = true;
    C.PrintInformation(); */

    /* Student A;
    A.SetNewName("Raju");
    A.Roll = 10;
    A.Gender = false;
    A.PrintInformation();
    
    Student B;
    B.SetNewName("Kaju");
    B.Roll = 2;
    B.Gender = false;
    B.PrintInformation();
    
    Student C;
    C.SetNewName("Saheli");
    C.Roll = 1;
    C.Gender = true;
    C.PrintInformation(); */

    Student A("Raju", 10, false);
    A.PrintInformation();

    Student B("Kaju", 2, false);
    B.PrintInformation();

    Student C("Saheli", 1, true);
    C.PrintInformation();

    Student D;

    Student E = C;
    E.PrintInformation();

    return 0;

}