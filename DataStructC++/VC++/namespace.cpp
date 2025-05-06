#include <iostream>

// 定义命名空间
namespace Math {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }
}

namespace Geometry {
    double areaOfCircle(double radius) {
        return 3.14159 * radius * radius;
    }
}

int main() {
    // 使用作用域解析运算符调用 Math 命名空间中的函数
    int sum = Math::add(5, 3);
    std::cout << "Sum: " << sum << std::endl;

    // 使用 using 声明调用 Math 命名空间中的函数
    using Math::subtract;
    int difference = subtract(10, 4);
    std::cout << "Difference: " << difference << std::endl;

    // 使用 using 指令调用 Geometry 命名空间中的函数
    using namespace Geometry;
    double circleArea = areaOfCircle(2.0);
    std::cout << "Area of circle: " << circleArea << std::endl;

    return 0;
}