#include <iostream>
#include <thread>

// 线程 1 执行的函数
void threadFunction1() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 1: " << i << std::endl;
    }
}

// 线程 2 执行的函数
void threadFunction2() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread 2: " << i << std::endl;
    }
}

int main() {
    // 创建线程 1
    std::thread t1(threadFunction1);
    // 创建线程 2
    std::thread t2(threadFunction2);

    // 等待线程 1 执行完毕
    t1.join();
    // 等待线程 2 执行完毕
    t2.join();

    std::cout << "Both threads have finished." << std::endl;
    return 0;
}