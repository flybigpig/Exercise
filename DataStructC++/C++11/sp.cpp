// 智能指针sp

#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(10);

    std::cout << "sp: " << sp.use_count() << std::endl;

    return 0;
}

/**
 * 
// 0. 需要使用智能指针的类必须继承自 RefBase
class X：public RefBase
{
    void test() 
    {
        //......
    }
}

{   // 作用域开始
    // 1.被管理的指针
    X* p = new X();  
    // 2.构建强引用
    sp<X> spX(p);   // sp<X> spX = new X()  这样也行，注意不要写成 sp<X> spX = new sp<X>() 
    // 3.通过强引用，操作指针指向的对象
    spX->test();
}   // 作用域结束，调用强引用对象的析构函数，释放掉 p 指针指向的内存
 * 
 */


