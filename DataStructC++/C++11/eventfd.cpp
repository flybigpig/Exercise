// eventfd
#include <iostream>
#include <sys/eventfd.h>
#include <unistd.h>
#include <thread>

// eventfd是Linux下的一个用于事件通知的文件描述符机制
// 它可以用于线程间或进程间的事件通知

class EventFD {
private:
    int efd; // eventfd文件描述符

public:
    EventFD(unsigned int initval = 0) {
        // 创建eventfd,EFD_NONBLOCK设置非阻塞,EFD_CLOEXEC设置fork时自动关闭
        efd = eventfd(initval, EFD_NONBLOCK | EFD_CLOEXEC);
        if (efd == -1) {
            throw std::runtime_error("Failed to create eventfd");
        }
    }

    ~EventFD() {
        if (efd != -1) {
            close(efd);
        }
    }

    // 写入事件计数
    bool write(uint64_t val) {
        return ::write(efd, &val, sizeof(val)) == sizeof(val);
    }

    // 读取事件计数
    bool read(uint64_t* val) {
        return ::read(efd, val, sizeof(*val)) == sizeof(*val);
    }

    int getFd() const { return efd; }
};

// 演示eventfd的使用
void demoEventFD() {
    EventFD efd;
    
    // 创建写线程
    std::thread writer([&efd]() {
        uint64_t counter = 1;
        std::cout << "Writer thread starting..." << std::endl;
        
        for(int i = 0; i < 3; i++) {
            std::cout << "Writing: " << counter << std::endl;
            efd.write(counter);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            counter++;
        }
    });

    // 创建读线程
    std::thread reader([&efd]() {
        uint64_t val;
        std::cout << "Reader thread starting..." << std::endl;
        
        for(int i = 0; i < 3; i++) {
            while(!efd.read(&val)) {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
            std::cout << "Read value: " << val << std::endl;
        }
    });

    writer.join();
    reader.join();
}

int main() {
    try {
        demoEventFD();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
