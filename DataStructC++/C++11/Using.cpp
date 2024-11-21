#include <iostream>

using Integer = int;
using String = std::string;

int main() {
    // C++11 提供了 using 关键字，用于定义类型别名，它是 typedef 的替代。
    Integer a = 42;
    String s = "Hello, world!";

    std::cout << a << std::endl;  // 输出 42
    std::cout << s << std::endl;  // 输出 Hello, world!

    return 0;
}