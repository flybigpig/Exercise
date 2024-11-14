#include <iostream>
#include <string>
using namespace std;

// �Զ��Ƶ���������ʾ��
auto add(int a, int b) {
    return a + b;  // ���������Զ��Ƶ�Ϊint
}

auto multiply(double x, double y) {
    return x * y;  // ���������Զ��Ƶ�Ϊdouble
}

auto concatenate(string s1, string s2) {
    return s1 + s2;  // ���������Զ��Ƶ�Ϊstring
}

// ʹ��β�÷��������﷨
auto divide(int a, int b) -> double {
    return static_cast<double>(a) / b;
}

int main() {
    // �����Զ������Ƶ�
    cout << "�����ӷ�: " << add(5, 3) << endl;
    cout << "�������˷�: " << multiply(2.5, 3.0) << endl;
    cout << "�ַ���ƴ��: " << concatenate("Hello ", "World!") << endl;
    cout << "����(β�÷�������): " << divide(5, 2) << endl;
    
    // ʹ��auto��������
    auto result1 = add(10, 20);
    auto result2 = multiply(1.5, 2.5);
    auto result3 = concatenate("C++", "11");
    
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;
    cout << "result3: " << result3 << endl;
    
    return 0;
}
