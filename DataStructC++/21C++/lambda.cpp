#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 创建一个vector存储数字
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 使用lambda表达式打印每个数字
    cout << "Original numbers: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
    });
    cout << endl;
    
    // 使用lambda表达式计算偶数的平方
    vector<int> squares;
    for_each(numbers.begin(), numbers.end(), [&squares](int n) {
        if (n % 2 == 0) {
            squares.push_back(n * n);
        }
    });
    
    // 打印平方结果
    cout << "Squares of even numbers: ";
    for_each(squares.begin(), squares.end(), [](int n) {
        cout << n << " ";
    });
    cout << endl;
    
    // 使用lambda表达式进行排序
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;  // 降序排序
    });
    
    // 打印排序后的结果
    cout << "Numbers in descending order: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
    });
    cout << endl;
    
    return 0;
}
