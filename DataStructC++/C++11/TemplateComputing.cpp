#include <iostream>
using namespace std;


// 模板元编程是利用模板在编译期进行计算和决策，使得程序在运行时效率更高。C++的模板可以实现递归计算、类型推导等高级特性。
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    cout << Factorial<5>::value << endl;  // 输出 120
    return 0;
}