#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};

    // 在末尾添加元素
    vec.push_back(4);
    std::cout << "Vector size after push_back: " << vec.size() << std::endl;

    // 移除末尾元素
    vec.pop_back();
    std::cout << "Vector size after pop_back: " << vec.size() << std::endl;

    return 0;
}