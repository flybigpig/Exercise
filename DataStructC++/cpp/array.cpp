#include <iostream>
using namespace std;

// 数组操作类
class ArrayOperations {
private:
    int* arr;        // 数组指针
    int size;        // 数组大小
    int capacity;    // 数组容量

public:
    // 构造函数
    ArrayOperations(int initialCapacity = 10) {
        capacity = initialCapacity;
        arr = new int[capacity];
        size = 0;
    }

    // 析构函数
    ~ArrayOperations() {
        delete[] arr;
    }

    // 在数组末尾添加元素
    void append(int element) {
        if (size >= capacity) {
            // 如果数组已满，扩容为原来的2倍
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity];
            
            // 复制原数组元素
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[size++] = element;
    }

    // 在指定位置插入元素
    bool insert(int index, int element) {
        if (index < 0 || index > size) {
            cout << "Invalid index" << endl;
            return false;
        }

        if (size >= capacity) {
            // 扩容
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity];
            
            // 复制前半部分
            for (int i = 0; i < index; i++) {
                newArr[i] = arr[i];
            }
            
            // 插入新元素
            newArr[index] = element;
            
            // 复制后半部分
            for (int i = index; i < size; i++) {
                newArr[i + 1] = arr[i];
            }
            
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        } else {
            // 移动元素腾出位置
            for (int i = size; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
        }
        size++;
        return true;
    }

    // 删除指定位置的元素
    bool remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return false;
        }

        // 移动元素填补空缺
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return true;
    }

    // 获取指定位置的元素
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return arr[index];
    }

    // 修改指定位置的元素
    bool set(int index, int element) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return false;
        }
        arr[index] = element;
        return true;
    }

    // 获取数组大小
    int getSize() {
        return size;
    }

    // 打印数组
    void print() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// 测试主函数
int main() {
    ArrayOperations array;
    
    // 测试添加元素
    array.append(1);
    array.append(2);
    array.append(3);
    cout << "After appending 1, 2, 3:" << endl;
    array.print();

    // 测试插入元素
    array.insert(1, 4);
    cout << "After inserting 4 at index 1:" << endl;
    array.print();

    // 测试删除元素
    array.remove(2);
    cout << "After removing element at index 2:" << endl;
    array.print();

    // 测试获取和修改元素
    cout << "Element at index 1: " << array.get(1) << endl;
    array.set(1, 5);
    cout << "After setting element at index 1 to 5:" << endl;
    array.print();

    return 0;
}
