
#include <iostream>

// ����˫������ڵ�ṹ
template <typename T>
struct Node {
    T data;           // �ڵ�����
    Node* prev;       // ָ��ǰһ���ڵ��ָ��
    Node* next;       // ָ���һ���ڵ��ָ��
    
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// ˫��������
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;    // ͷ�ڵ�ָ��
    Node<T>* tail;    // β�ڵ�ָ��
    int size;         // �����С

public:
    // ���캯��
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    // ��������
    ~DoublyLinkedList() {
        clear();
    }

    // ������ͷ������ڵ�
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

    // ������β������ڵ�
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

    // ɾ��ͷ���ڵ�
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

    // ɾ��β���ڵ�
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

    // ��ָ��λ�ò���ڵ�
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

    // ɾ��ָ��λ�õĽڵ�
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

    // �������
    void clear() {
        while (!isEmpty()) {
            popFront();
        }
    }

    // ��ȡ�����С
    int getSize() const {
        return size;
    }

    // �ж������Ƿ�Ϊ��
    bool isEmpty() const {
        return size == 0;
    }

    // ��ӡ����
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // �����ӡ����
    void printReverse() const {
        Node<T>* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};
