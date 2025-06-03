#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 基本类型的auto推导
    auto i = 42;        // int
    auto d = 42.0;      // double
    auto c = 'a';       // char
    auto s = "hello";   // const char*
    auto str = string("hello"); // string
    
    // 容器类型的auto推导
    vector<int> vec = {1, 2, 3, 4, 5};
    auto it = vec.begin();  // vector<int>::iterator
    
    // 引用类型的auto推导
    int x = 10;
    auto& ref = x;      // int&
    
    // 常量类型的auto推导
    const int y = 20;
    auto const_val = y; // int (注意：auto不会保留const属性)
    const auto const_val2 = y; // const int
    
    // 输出验证
    cout << "i type: " << typeid(i).name() << endl;
    cout << "d type: " << typeid(d).name() << endl;
    cout << "c type: " << typeid(c).name() << endl;
    cout << "s type: " << typeid(s).name() << endl;
    cout << "str type: " << typeid(str).name() << endl;
    cout << "it type: " << typeid(it).name() << endl;
    cout << "ref type: " << typeid(ref).name() << endl;
    cout << "const_val type: " << typeid(const_val).name() << endl;
    cout << "const_val2 type: " << typeid(const_val2).name() << endl;
    
    return 0;
}
