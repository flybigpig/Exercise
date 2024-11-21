#include <iostream>
#include <memory>

int main() {
    // C++11 引入了智能指针 std::unique_ptr 和 std::shared_ptr 来自动管理内存，避免了手动 delete 的问题

    std::unique_ptr<int> ptr1 = std::make_unique<int>(42); // unique_ptr
    std::cout << *ptr1 << std::endl;

    std::shared_ptr<int> ptr2 = std::make_shared<int>(10); // shared_ptr
    std::cout << *ptr2 << std::endl;

    return 0;
}