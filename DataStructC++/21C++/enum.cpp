#include <iostream>
using namespace std;

// 定义一个枚举类型
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2
};

// 定义一个带初始值的枚举类型
enum Direction {
    NORTH = 10,
    EAST = 20,
    SOUTH = 30,
    WEST = 40
};

// 定义一个作用域枚举类型（C++11）
enum class Status {
    OK,
    ERROR,
    PENDING
};

int main() {
    // 使用普通枚举
    Color c = RED;
    cout << "Color value: " << c << endl;  // 输出: 0
    
    // 使用带初始值的枚举
    Direction d = NORTH;
    cout << "Direction value: " << d << endl;  // 输出: 10
    
    // 使用作用域枚举
    Status s = Status::OK;
    // 注意：作用域枚举不能直接转换为整数
    cout << "Status value: " << static_cast<int>(s) << endl;  // 输出: 0
    
    // 枚举类型的大小
    cout << "Size of Color enum: " << sizeof(Color) << " bytes" << endl;
    cout << "Size of Direction enum: " << sizeof(Direction) << " bytes" << endl;
    cout << "Size of Status enum class: " << sizeof(Status) << " bytes" << endl;
    
    return 0;
}
