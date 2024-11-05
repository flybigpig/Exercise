// ???
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace  std;

// ָ��Ļ���������÷�ʾ��
void pointerDemo() {
    // 1. �����ͳ�ʼ��ָ��
    int x = 10;
    int* p = &x;  // p�洢x�ĵ�ַ
    
    // 2. ָ��Ľ�����
    cout << "x��ֵ: " << x << endl;
    cout << "ͨ��ָ�����x��ֵ: " << *p << endl;
    
    // 3. ָ�����������
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    cout << "��һ��Ԫ��: " << *ptr << endl;
    ptr++;  // ָ���ƶ�����һ��Ԫ��
    cout << "�ڶ���Ԫ��: " << *ptr << endl;
    
    // 4. constָ��
    // int y = 20;
    // const int* cp = &y;  // ����ͨ��ָ���޸�ֵ
    // int* const pc = &y;  // �����޸�ָ��ָ��ĵ�ַ
    
    // 5. ָ�������
    int numbers[3] = {100, 200, 300};
    int* numPtr = numbers;
    for(int i = 0; i < 3; i++) {
        cout << "Element " << i << ": " << *(numPtr + i) << endl;
    }
     
    // 6. ��ָ��
    int* nullPtr = nullptr;
    if(nullPtr == nullptr) {
        cout << "����һ����ָ��" << endl;
    }
    
    // 7. voidָ��
    void* voidPtr = &x;
    int* intPtr = static_cast<int*>(voidPtr);
    cout << "ͨ��voidָ�����ֵ: " << *intPtr << endl;
    
    // 8. ָ���ָ�루����ָ�룩
    int value = 42;
    int* valuePtr = &value;
    int** ptrToPtr = &valuePtr;
    cout << "ͨ������ָ�����ֵ: " << **ptrToPtr << endl;
}


int main() {

    
    pointerDemo();
    
    return 0;
}
