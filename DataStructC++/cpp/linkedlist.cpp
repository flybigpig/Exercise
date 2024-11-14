
#include <iostream>

// 定义双向链表节点结构
template <typename T>
struct Node {
    T data;           // 节点数据
    Node* prev;       // 指向前一个节点的指针
    Node* next;       // 指向后一个节点的指针
    
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// 双向链表类
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;    // 头节点指针
    Node<T>* tail;    // 尾节点指针
    int size;         // 链表大小

public:
    // 构造函数
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // 析构函数
    ~DoublyLinkedList() {
        clear();
    }

    // 在链表头部插入节点
    void pushFront(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // 在链表尾部插入节点
    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // 删除头部节点
    void popFront() {
        if (isEmpty()) return;
        
        Node<T>* temp = head;
        head = head->next;
        
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        delete temp;
        size--;
    }

    // 删除尾部节点
    void popBack() {
        if (isEmpty()) return;
        
        Node<T>* temp = tail;
        tail = tail->prev;
        
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        
        delete temp;
        size--;
    }

    // 在指定位置插入节点
    void insert(int position, const T& value) {
        if (position < 0 || position > size) return;
        
        if (position == 0) {
            pushFront(value);
            return;
        }
        
        if (position == size) {
            pushBack(value);
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }

    // 删除指定位置的节点
    void remove(int position) {
        if (position < 0 || position >= size) return;
        
        if (position == 0) {
            popFront();
            return;
        }
        
        if (position == size - 1) {
            popBack();
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }

    // 清空链表
    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    // 获取链表大小
    int getSize() const {
        return size;
    }

    // 判断链表是否为空
    bool isEmpty() const {
        return size == 0;
    }

    // 打印链表
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 反向打印链表
    void printReverse() const {
        Node<T>* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};
