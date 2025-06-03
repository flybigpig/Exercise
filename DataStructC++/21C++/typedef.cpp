#include <iostream>
using namespace std;

/**
 *  typedef unsigned int STRICTLY_POSITIVE_INTEGER; 
    STRICTLY_POSITIVE_INTEGER numEggsInBasket = 4532;
 * 
 */

// 使用typedef定义类型别名
typedef int INTEGER;  // 将int类型重命名为INTEGER
typedef unsigned long ULONG;  // 将unsigned long重命名为ULONG
typedef double REAL;  // 将double重命名为REAL

// 使用typedef定义结构体类型别名
typedef struct {
    int x;
    int y;
} Point;  // 定义Point类型

// 使用typedef定义函数指针类型
typedef int (*Operation)(int, int);  // 定义函数指针类型Operation

// 示例函数
int add(int a, int b) {
    return a + b;
}

int main() {
    // 使用typedef定义的类型
    INTEGER num1 = 10;
    ULONG num2 = 1000000;
    REAL pi = 3.14159;
    
    // 使用Point类型
    Point p = {5, 10};
    
    // 使用函数指针类型
    Operation op = add;
    
    // 输出结果
    cout << "INTEGER value: " << num1 << endl;
    cout << "ULONG value: " << num2 << endl;
    cout << "REAL value: " << pi << endl;
    cout << "Point coordinates: (" << p.x << ", " << p.y << ")" << endl;
    cout << "Operation result: " << op(5, 3) << endl;
    
    return 0;
}
