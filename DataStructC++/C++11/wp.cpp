// 弱引用

#include <iostream>
#include <memory>
/**
 * weak_ptr 弱引用的特点:
 * 1. weak_ptr不会增加引用计数
 * 2. weak_ptr不能直接访问对象，需要先转换为shared_ptr   //不能直接通过弱引用使用对象，升级为强指针再使用   sp<X> spX2 = wpx.promote()
 * 3. 可以用来解决shared_ptr循环引用的问题
 * 4. expired()用于检查指针是否已经失效
 * 5. lock()用于获取shared_ptr，如果原始对象已被释放则返回空指针
 */

int main() {
    // 创建一个shared_ptr
    std::shared_ptr<int> sp = std::make_shared<int>(10);
    
    // 创建一个weak_ptr指向shared_ptr管理的对象
    std::weak_ptr<int> wp = sp;

    std::cout << "sp use count: " << sp.use_count() << std::endl;
    std::cout << "wp expired: " << std::boolalpha << wp.expired() << std::endl;

    // 通过weak_ptr获取shared_ptr
    if(auto temp = wp.lock()) {
        std::cout << "Value: " << *temp << std::endl;
    } else {
        std::cout << "wp is expired" << std::endl;
    }

    // 释放shared_ptr
    sp.reset();
    
    std::cout << "\nAfter sp.reset():" << std::endl;
    std::cout << "wp expired: " << wp.expired() << std::endl;

    // 尝试通过已经过期的weak_ptr获取shared_ptr
    if(auto temp = wp.lock()) {
        std::cout << "Value: " << *temp << std::endl;
    } else {
        std::cout << "wp is expired" << std::endl;
    }

    return 0;
}




