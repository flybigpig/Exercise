#include <iostream>
using namespace std;

// 类模板
template <typename T>
class Box {
public:
    T value;
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);           // 创建 Box 类型为 int
    Box<double> doubleBox(3.14);   // 创建 Box 类型为 double
    
    cout << intBox.getValue() << endl;     // 输出 10
    cout << doubleBox.getValue() << endl;  // 输出 3.14
    return 0;
}