#include <iostream>
#include <string>
using namespace std;

// 自动推导返回类型示例
auto add(int a, int b) {
    return a + b;  // 返回类型自动推导为int
}

auto multiply(double x, double y) {
    return x * y;  // 返回类型自动推导为double
}

auto concatenate(string s1, string s2) {
    return s1 + s2;  // 返回类型自动推导为string
}

// 使用尾置返回类型语法
auto divide(int a, int b) -> double {
    return static_cast<double>(a) / b;
}

int main() {
    // 测试自动类型推导
    cout << "整数加法: " << add(5, 3) << endl;
    cout << "浮点数乘法: " << multiply(2.5, 3.0) << endl;
    cout << "字符串拼接: " << concatenate("Hello ", "World!") << endl;
    cout << "除法(尾置返回类型): " << divide(5, 2) << endl;
    
    // 使用auto声明变量
    auto result1 = add(10, 20);
    auto result2 = multiply(1.5, 2.5);
    auto result3 = concatenate("C++", "11");
    
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;
    cout << "result3: " << result3 << endl;
    
    return 0;
}
