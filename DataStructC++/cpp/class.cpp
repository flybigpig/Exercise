#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }

    virtual void sound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* a;
    Dog d;
    Cat c;

    a = &d;
    a->sound();  // 输出 "Bark!"

    a = &c;
    a->sound();  // 输出 "Meow!"

    a->eat();

    return 0;
}