// ָ��
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace  std;

// 指针的基本概念和用法示例
void pointerDemo() {
    // 1. 声明和初始化指针
    int x = 10;
    int* p = &x;  // p存储x的地址
    
    // 2. 指针的解引用
    cout << "x的值: " << x << endl;
    cout << "通过指针访问x的值: " << *p << endl;
    
    // 3. 指针的算术运算
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    cout << "第一个元素: " << *ptr << endl;
    ptr++;  // 指针移动到下一个元素
    cout << "第二个元素: " << *ptr << endl;
    
    // 4. const指针
    int y = 20;
    // const int* cp = &y;  // 不能通过指针修改值
    // int* const pc = &y;  // 不能修改指针指向的地址
    
    // 5. 指针和数组
    int numbers[3] = {100, 200, 300};
    int* numPtr = numbers;
    for(int i = 0; i < 3; i++) {
        cout << "Element " << i << ": " << *(numPtr + i) << endl;
    }
    
    // 6. 空指针
    int* nullPtr = nullptr;
    if(nullPtr == nullptr) {
        cout << "这是一个空指针" << endl;
    }
    
    // 7. void指针
    void* voidPtr = &x;
    int* intPtr = static_cast<int*>(voidPtr);
    cout << "通过void指针访问值: " << *intPtr << endl;
    
    // 8. 指针的指针（二级指针）
    int value = 42;
    int* valuePtr = &value;
    int** ptrToPtr = &valuePtr;
    cout << "通过二级指针访问值: " << **ptrToPtr << endl;
}


int main() {
    
    
    pointerDemo();
    
    return 0;
}
