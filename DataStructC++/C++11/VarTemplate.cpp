#include <iostream>
using namespace std;

// 基础模板
template <typename T>
void print(T t) {
    cout << t << endl;
}

// 变长模板
template <typename T, typename... Args>
void print(T t, Args... args) {
    cout << t << " ";
    print(args...);  // 递归调用
}

int main() {
    print(1, 2.5, "Hello", 'A');  // 输出 1 2.5 Hello A
    return 0;
}