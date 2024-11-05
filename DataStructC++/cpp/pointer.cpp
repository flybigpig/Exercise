// 指针
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// 命名空间
using namespace  std;

// 基本指针示例
void pointerDemo() {
    cout << "\n=== 指针基础演示 ===" << endl;
    
    // 1. 基本指针声明和使用
    int num = 10;
    int* ptr = &num;  // 声明指针并指向num的地址
    cout << "num的值: " << num << endl;
    cout << "num的地址: " << &num << endl;
    cout << "ptr存储的地址: " << ptr << endl;
    cout << "通过ptr访问num的值: " << *ptr << endl;

    // 2. 通过指针修改值
    *ptr = 20;
    cout << "修改后num的值: " << num << endl;

    // 3. 指针的算术运算
    int arr[] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;  // 数组名就是指向第一个元素的指针
    cout << "\n数组元素:";
    for(int i = 0; i < 5; i++) {
        cout << " " << *(arrPtr + i);  // 指针算术
    }
    cout << endl;

    // 4. 空指针
    int* nullPtr = nullptr;
    cout << "\n空指针值: " << nullPtr << endl;

    // 5. 动态内存分配
    int* dynamicPtr = new int;  // 分配单个整数的内存
    *dynamicPtr = 100;
    cout << "\n动态分配的内存中的值: " << *dynamicPtr << endl;
    delete dynamicPtr;  // 释放内存

    // 6. 动态数组
    int* dynamicArray = new int[5];
    for(int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 1;
    }
    cout << "\n动态数组元素:";
    for(int i = 0; i < 5; i++) {
        cout << " " << dynamicArray[i];
    }
    cout << endl;
    delete[] dynamicArray;  // 释放数组内存
}

// 修改主函数调用演示
int main() {
    string str = "Hello, World!";
    cout << str << endl;
    
    // 调用指针演示函数
    pointerDemo();
    
    return 0;
}
