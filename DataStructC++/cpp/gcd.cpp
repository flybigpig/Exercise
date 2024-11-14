#include <iostream>

// ���������������Լ��
int gcd(int p, int q) {
    if (q == 0) {
        return p;
    }
    return gcd(q, p % q);
}

// ��������������С������
int lcm(int a, int b) {
    // ��С������ = ����֮���������Լ��
    return (a * b) / gcd(a, b);
}
// ��������������С��Լ��
int minGcd(int a, int b) {
    // ���ҳ����еĹ�Լ��
    int min = (a < b) ? a : b;
    int minGcd = 1;
    
    for(int i = 1; i <= min; i++) {
        if(a % i == 0 && b % i == 0) {
            minGcd = i;
            break;  // �ҵ���һ����Լ����Ϊ��С��Լ��
        }
    }
    
    return minGcd;
}

  


// �������Լ������
int main() {
    int num1 = 48; 

    int num2 = 36;
    
    std::cout << "����" << num1 << "��" << num2 << "�����Լ��" << std::endl;
    int result = gcd(num1, num2);
    std::cout << "���Լ����: " << result << std::endl;

    std::cout << "��С��������: " << lcm(num1, num2) << std::endl;

    std::cout << "��С��Լ����: " << minGcd(num1, num2) << std::endl;
    
    return 0;
}
