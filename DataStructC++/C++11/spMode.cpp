// 智能指针的两种模式
#include <iostream>
#include <memory>

/**
 * 智能指针的两种生命周期模式:
 * 
 * 1. OBJECT_LIFETIME_STRONG
 * - 对象的生命周期由强引用(shared_ptr)完全控制
 * - 当最后一个强引用消失时,对象被销毁
 * - 适用于普通的对象管理场景
 * 
 * 2. OBJECT_LIFETIME_WEAK  
 * - 对象的生命周期不完全由强引用控制
 * - 即使还存在强引用,对象也可能被销毁
 * - 需要通过弱引用(weak_ptr)检查对象是否还存在
 * - 适用于缓存等需要自主控制生命周期的场景
 */

class StrongObject {
public:
    StrongObject() { std::cout << "StrongObject created\n"; }
    ~StrongObject() { std::cout << "StrongObject destroyed\n"; }
};

class WeakObject {
public:
    WeakObject() { std::cout << "WeakObject created\n"; }
    ~WeakObject() { std::cout << "WeakObject destroyed\n"; }
    void destroy() { std::cout << "WeakObject self-destroying\n"; delete this; }
};

int main() {
    // OBJECT_LIFETIME_STRONG 示例
    {
        std::shared_ptr<StrongObject> sp = std::make_shared<StrongObject>();
        std::weak_ptr<StrongObject> wp = sp;
        
        std::cout << "Strong object exists: " << !wp.expired() << std::endl;
        sp.reset(); // 强引用消失,对象被销毁
        std::cout << "Strong object exists: " << !wp.expired() << std::endl;
    }

    std::cout << "\n";

    // OBJECT_LIFETIME_WEAK 示例
    {
        WeakObject* obj = new WeakObject();
        std::shared_ptr<WeakObject> sp(obj);
        std::weak_ptr<WeakObject> wp = sp;

        std::cout << "Weak object exists: " << !wp.expired() << std::endl;
        obj->destroy(); // 对象自行销毁,即使还存在强引用
        std::cout << "Weak object exists: " << !wp.expired() << std::endl;
    }

    return 0;
}

