#include <iostream>

int main() {
    // 只分配一个int类型内存的情况
    int* singleHandle = nullptr;
    singleHandle = new int;
    *singleHandle = 42;
    std::cout << "Single handle value: " << *singleHandle << std::endl;
    delete singleHandle;

    // 使用多级指针的情况
    int** doubleHandle = nullptr;
    doubleHandle = new int*;
    *doubleHandle = new int;
    **doubleHandle = 42;
    std::cout << "Double handle value: " << **doubleHandle << std::endl;
    delete *doubleHandle;
    delete doubleHandle;

    return 0;
}