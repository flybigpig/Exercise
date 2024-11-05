// ָ��
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// �����ռ�
using namespace  std;

// ����ָ��ʾ��
void pointerDemo() {
    cout << "\n=== ָ�������ʾ ===" << endl;
    
    // 1. ����ָ��������ʹ��
    int num = 10;
    int* ptr = &num;  // ����ָ�벢ָ��num�ĵ�ַ
    cout << "num��ֵ: " << num << endl;
    cout << "num�ĵ�ַ: " << &num << endl;
    cout << "ptr�洢�ĵ�ַ: " << ptr << endl;
    cout << "ͨ��ptr����num��ֵ: " << *ptr << endl;

    // 2. ͨ��ָ���޸�ֵ
    *ptr = 20;
    cout << "�޸ĺ�num��ֵ: " << num << endl;

    // 3. ָ�����������
    int arr[] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;  // ����������ָ���һ��Ԫ�ص�ָ��
    cout << "\n����Ԫ��:";
    for(int i = 0; i < 5; i++) {
        cout << " " << *(arrPtr + i);  // ָ������
    }
    cout << endl;

    // 4. ��ָ��
    int* nullPtr = nullptr;
    cout << "\n��ָ��ֵ: " << nullPtr << endl;

    // 5. ��̬�ڴ����
    int* dynamicPtr = new int;  // ���䵥���������ڴ�
    *dynamicPtr = 100;
    cout << "\n��̬������ڴ��е�ֵ: " << *dynamicPtr << endl;
    delete dynamicPtr;  // �ͷ��ڴ�

    // 6. ��̬����
    int* dynamicArray = new int[5];
    for(int i = 0; i < 5; i++) {
        dynamicArray[i] = i + 1;
    }
    cout << "\n��̬����Ԫ��:";
    for(int i = 0; i < 5; i++) {
        cout << " " << dynamicArray[i];
    }
    cout << endl;
    delete[] dynamicArray;  // �ͷ������ڴ�
}

// �޸�������������ʾ
int main() {
    string str = "Hello, World!";
    cout << str << endl;
    
    // ����ָ����ʾ����
    pointerDemo();
    
    return 0;
}
