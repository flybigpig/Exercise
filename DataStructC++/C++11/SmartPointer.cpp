#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
    void sayHello() { std::cout << "Hello from MyClass\n"; }
};

int main() {
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();  // 创建 unique_ptr
    ptr1->sayHello();  // 调用成员函数
    
    // std::unique_ptr<MyClass> ptr2 = ptr1;  // 错误：无法拷贝 unique_ptr
    
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);  // 转移所有权
    // ptr1 不再指向对象，ptr2 现在拥有资源
    
    // ptr1->sayHello();  // 错误：ptr1 为空指针
    
    ptr2->sayHello();  // 正常调用
    
    return 0;
}