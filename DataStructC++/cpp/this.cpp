#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    
public:
    // 构造函数
    Person(string name, int age) {
        // 使用this指针区分成员变量和参数
        this->name = name;
        this->age = age;
    }
    
    // 返回对象本身的引用
    Person& addAge(int age) {
        this->age += age;
        return *this;  // 返回当前对象
    }
    
    // 打印信息
    void printInfo() {
        cout << "姓名: " << this->name << endl;
        cout << "年龄: " << this->age << endl;
    }
};

int main() {
    // 创建对象
    Person person("张三", 20);
    
    // 打印初始信息
    cout << "初始信息:" << endl;
    person.printInfo();
    
    // 链式调用演示
    cout << "\n增加年龄后:" << endl;
    person.addAge(1).addAge(2).printInfo();
    
    return 0;
}
