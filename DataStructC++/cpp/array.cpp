#include <iostream>
using namespace std;

// ���������
class ArrayOperations {
private:
    int* arr;        // ����ָ��
    int size;        // �����С
    int capacity;    // ��������

public:
    // ���캯��
    ArrayOperations(int initialCapacity = 10) {
        capacity = initialCapacity;
        arr = new int[capacity];
        size = 0;
    }

    // ��������
    ~ArrayOperations() {
        delete[] arr;
    }

    // ������ĩβ���Ԫ��
    void append(int element) {
        if (size >= capacity) {
            // �����������������Ϊԭ����2��
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity];
            
            // ����ԭ����Ԫ��
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[size++] = element;
    }

    // ��ָ��λ�ò���Ԫ��
    bool insert(int index, int element) {
        if (index < 0 || index > size) {
            cout << "Invalid index" << endl;
            return false;
        }

        if (size >= capacity) {
            // ����
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity];
            
            // ����ǰ�벿��
            for (int i = 0; i < index; i++) {
                newArr[i] = arr[i];
            }
            
            // ������Ԫ��
            newArr[index] = element;
            
            // ���ƺ�벿��
            for (int i = index; i < size; i++) {
                newArr[i + 1] = arr[i];
            }
            
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        } else {
            // �ƶ�Ԫ���ڳ�λ��
            for (int i = size; i > index; i--) {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
        }
        size++;
        return true;
    }

    // ɾ��ָ��λ�õ�Ԫ��
    bool remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return false;
        }

        // �ƶ�Ԫ�����ȱ
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return true;
    }

    // ��ȡָ��λ�õ�Ԫ��
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return arr[index];
    }

    // �޸�ָ��λ�õ�Ԫ��
    bool set(int index, int element) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return false;
        }
        arr[index] = element;
        return true;
    }

    // ��ȡ�����С
    int getSize() {
        return size;
    }

    // ��ӡ����
    void print() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ����������
int main() {
    ArrayOperations array;
    
    // �������Ԫ��
    array.append(1);
    array.append(2);
    array.append(3);
    cout << "After appending 1, 2, 3:" << endl;
    array.print();

    // ���Բ���Ԫ��
    array.insert(1, 4);
    cout << "After inserting 4 at index 1:" << endl;
    array.print();

    // ����ɾ��Ԫ��
    array.remove(2);
    cout << "After removing element at index 2:" << endl;
    array.print();

    // ���Ի�ȡ���޸�Ԫ��
    cout << "Element at index 1: " << array.get(1) << endl;
    array.set(1, 5);
    cout << "After setting element at index 1 to 5:" << endl;
    array.print();

    return 0;
}
