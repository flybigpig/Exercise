#include <iostream>
#include <algorithm> // std::sort
#include <vector>

int main() {
    std::vector<int> vec = { 4, 2, 5, 1, 3 };

    // 排序前
    std::cout << "before: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用 std::sort 进行排序
    std::sort(vec.begin(), vec.end());

    // 排序后
    std::cout << "after: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}