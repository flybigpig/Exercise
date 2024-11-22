#include <iostream>
#include <type_traits>
using namespace std;

/*

SFINAE (Substitution Failure Is Not An Error)
SFINAE 是 C++ 模板编程中的一个重要概念，它的全称是替换失败不是错误

SFINAE 使得我们可以在编译时选择是否启用某个模板，而不是依赖运行时检查。

使用 std::enable_if 和 类型特征 可以非常方便地做类型限制，避免了不必要的错误或不匹配的模板实例化。

它非常适用于模板元编程和类型约束，尤其是在函数重载和类模板选择的场景中。

SFINAE 是 C++ 模板编程的一个重要特性，可以帮助你写出更加灵活、类型安全的代码。

*/



// 整型相加
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
add(T a, T b) {
    cout << "Using integral version" << endl;
    return a + b;
}

// 浮动类型相加
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
add(T a, T b) {
    cout << "Using floating-point version" << endl;
    return a + b;
}

int main() {
    cout << add(1, 2) << endl;       // 使用整型版本
    cout << add(1.1, 2.2) << endl;   // 使用浮动类型版本
    return 0;
}

