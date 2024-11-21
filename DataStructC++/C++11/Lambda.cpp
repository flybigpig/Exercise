#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 lambda 表达式进行排序
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;  // 按降序排序
    });

    for (int n : numbers) {
        std::cout << n << " ";  // 输出 5 4 3 2 1
    }

    return 0;
}