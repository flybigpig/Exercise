#include <iostream>
#include <string>
using namespace std;

class CaffeineBeverage {
public:
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }

protected:
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

private:
    void boilWater() {
        cout << "Boiling water" << endl;
    }

    void pourInCup() {
        cout << "Pouring in cup" << endl;
    }
};


class Coffee : public CaffeineBeverage {
protected:
    void brew() override {
        cout << "Dripping coffee through filter" << endl;
    }

    void addCondiments() override {
        cout << "Adding sugar and milk" << endl;
    }
};


class Tea : public CaffeineBeverage {
protected:
    void brew() override {
        cout << "Steeping the tea" << endl;
    }

    void addCondiments() override {
        cout << "Adding lemon" << endl;
    }
};

int main() {
    CaffeineBeverage* coffee = new Coffee();
    coffee->prepareRecipe();
    
    cout << endl;
    
    CaffeineBeverage* tea = new Tea();
    tea->prepareRecipe();

    delete coffee;
    delete tea;

    return 0;
}