#include <iostream>

// 计算两个数的最大公约数
int gcd(int p, int q) {
    if (q == 0) {
        return p;
    }
    return gcd(q, p % q);
}

// 计算两个数的最小公倍数
int lcm(int a, int b) {
    // 最小公倍数 = 两数之积除以最大公约数
    return (a * b) / gcd(a, b);
}
// 计算两个数的最小公约数
int minGcd(int a, int b) {
    // 先找出所有的公约数
    int min = (a < b) ? a : b;
    int minGcd = 1;
    
    for(int i = 1; i <= min; i++) {
        if(a % i == 0 && b % i == 0) {
            minGcd = i;
            break;  // 找到第一个公约数即为最小公约数
        }
    }
    
    return minGcd;
}

  


// 测试最大公约数函数
int main() {
    int num1 = 48; 

    int num2 = 36;
    
    std::cout << "计算" << num1 << "和" << num2 << "的最大公约数" << std::endl;
    int result = gcd(num1, num2);
    std::cout << "最大公约数是: " << result << std::endl;

    std::cout << "最小公倍数是: " << lcm(num1, num2) << std::endl;

    std::cout << "最小公约数是: " << minGcd(num1, num2) << std::endl;
    
    return 0;
}
