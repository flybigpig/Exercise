#include <iostream>
using namespace std;

int main() {
    // 位运算符示例
    int a = 5;  // 二进制: 0101
    int b = 3;  // 二进制: 0011
    
    // NOT (~) 按位取反
    cout << "NOT (~) :" << endl;
    cout << "~" << a << " = " << ~a << endl;  // 输出: -6 (二进制: 1010)
    
    // AND (&) 按位与
    cout << "\nAND (&) :" << endl;
    cout << a << " & " << b << " = " << (a & b) << endl;  // 输出: 1 (二进制: 0001)
    
    // OR (|) 按位或
    cout << "\nOR (|) :" << endl;
    cout << a << " | " << b << " = " << (a | b) << endl;  // 输出: 7 (二进制: 0111)
    
    // XOR (^) 按位异或
    cout << "\nXOR (^) :" << endl;
    cout << a << " ^ " << b << " = " << (a ^ b) << endl;  // 输出: 6 (二进制: 0110)
    
    // 二进制表示
    cout << "\n binary:" << endl;
    cout << a << " binary: ";
    for(int i = 3; i >= 0; i--) {
        cout << ((a >> i) & 1);
    }
    cout << endl;
    
    cout << b << " binary: ";
    for(int i = 3; i >= 0; i--) {
        cout << ((b >> i) & 1);
    }
    cout << endl;
    
    return 0;
}
