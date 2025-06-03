#include <iostream>
using namespace std;

// Inline function to calculate square of a number
inline int square(int x) {
    return x * x;
}

// Inline function to find maximum of two numbers
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num = 5;
    cout << "Square of " << num << " is: " << square(num) << endl;
    
    int a = 10, b = 20;
    cout << "Maximum of " << a << " and " << b << " is: " << max(a, b) << endl;
    
    return 0;
}

