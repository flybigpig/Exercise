#include <iostream>
#include <utility>
#include <tuple>

// 演示结构化绑定的不同用法

/**
    数组绑定 - a: 10, b: 20
    结构体绑定 - x: 3, y: 4
    pair绑定 - first: 1, second: 2.5
    tuple绑定 - num: 1, str: hello, dbl: 3.14


 */

int main() {
    // 1. 绑定数组
    int arr[] = {10, 20};
    auto [a, b] = arr;
    std::cout << "array binding - a: " << a << ", b: " << b << std::endl;

    // 2. 绑定结构体
    struct Point {
        int x;
        int y;
    };
    Point p = {3, 4};
    auto [x, y] = p;
    std::cout << "struct binding - x: " << x << ", y: " << y << std::endl;

    // 3. 绑定pair
    std::pair<int, double> pair = {1, 2.5};
    auto [first, second] = pair;
    std::cout << "pair binding - first: " << first << ", second: " << second << std::endl;

    // 4. 绑定tuple
    std::tuple<int, std::string, double> tuple = {1, "hello", 3.14};
    auto [num, str, dbl] = tuple;
    std::cout << "tuple binding - num: " << num << ", str: " << str << ", dbl: " << dbl << std::endl;

    return 0;//
}
