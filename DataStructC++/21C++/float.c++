#include <iostream>
#include <iomanip> // 用于控制输出格式

int main() {
    // 声明float和double类型的变量
    float floatNum = 3.14159f;  // 注意float类型需要加f后缀
    double doubleNum = 3.141592653589793;

    // 使用默认精度输出
    std::cout << "Float number: " << floatNum << std::endl;
    std::cout << "Double number: " << doubleNum << std::endl;

    // 使用setprecision控制输出精度
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Float with 6 decimal places: " << floatNum << std::endl;
    std::cout << "Double with 6 decimal places: " << doubleNum << std::endl;

    // 进行一些基本运算
    float floatSum = floatNum + 1.0f;
    double doubleSum = doubleNum + 1.0;

    std::cout << "Float sum: " << floatSum << std::endl;
    std::cout << "Double sum: " << doubleSum << std::endl;

    return 0;
}
