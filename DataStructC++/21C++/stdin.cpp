#include <iostream>

int main() {
    // �����������ڴ洢�û�����
    int number;
    std::string name;
    
    // ʹ��std::cin��ȡ�û�����
    std::cout << "cin number: ";
    std::cin >> number;
    
    std::cout << "cin name: ";
    std::cin >> name;
    
    // ʹ��std::cout����û����������
    std::cout << "number: " << number << std::endl;
    std::cout << "name: " << name << std::endl;
    
    return 0;
}
