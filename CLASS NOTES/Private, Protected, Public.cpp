#include<iostream>

class Entity {
    // private:
    // protected: 
    public: // CHANGE THIS TO PRIVATE / PROTECTED / PUBLIC TO SEE THE RESULTS IN REST OF THE CODE
        int X, Y;
        Entity() {
            X = 0;
        }

        void ChangeValue(int new_num) {
            X = new_num;
        }
};

class Player : public Entity {
    Player() {
            X = 2;
        }
};

class New_Class {
    // int X;
    X = 5;
};

int main() {
    Entity e;
    e.ChangeValue(5); 
}