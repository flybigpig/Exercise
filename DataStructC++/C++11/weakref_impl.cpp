#include <iostream>
#include <memory>

class WeakRefImpl {
private:
    std::weak_ptr<int> weakPtr;

public:
    WeakRefImpl() {
        // Create a shared_ptr
        auto sharedPtr = std::make_shared<int>(42);
        
        // Create a weak_ptr from shared_ptr
        weakPtr = sharedPtr;
        
        // Check if weak_ptr is expired
        if (auto ptr = weakPtr.lock()) {
            std::cout << "Value: " << *ptr << std::endl;
        } else {
            std::cout << "Weak pointer expired" << std::endl;
        }
        
        // Let shared_ptr go out of scope
        sharedPtr.reset();
        
        // Try to access after shared_ptr is destroyed
        if (auto ptr = weakPtr.lock()) {
            std::cout << "Value: " << *ptr << std::endl;
        } else {
            std::cout << "Weak pointer expired" << std::endl;
        }
    }

    // Check if weak_ptr is expired
    bool isExpired() const {
        return weakPtr.expired();
    }

    // Get use count
    long getUseCount() const {
        return weakPtr.use_count();
    }

    // Reset weak_ptr
    void reset() {
        weakPtr.reset();
    }
};

int main() {
    WeakRefImpl weakRefTest;
    std::cout << "Is expired: " << (weakRefTest.isExpired() ? "Yes" : "No") << std::endl;
    std::cout << "Use count: " << weakRefTest.getUseCount() << std::endl;
    
    return 0;
}
