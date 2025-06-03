#include <iostream>

int main() {
    // 声明变量用于存储用户输入
    int number;
    std::string name;
    
    // 使用std::cin获取用户输入
    std::cout << "cin number: ";
    std::cin >> number;
    
    std::cout << "cin name: ";
    std::cin >> name;
    
    // 使用std::cout输出用户输入的内容
    std::cout << "number: " << number << std::endl;
    std::cout << "name: " << name << std::endl;
    
    return 0;
}
