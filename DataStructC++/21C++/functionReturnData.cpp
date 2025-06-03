
#include <iostream>

// Function that returns an integer
int add(int a, int b) {
    return a + b;
}

// Function that returns a double
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    return 0; // Return 0 if division by zero
}

// Function that returns a boolean
bool isEven(int number) {
    return (number % 2 == 0);
}

int main() {
    // Using the return value of add function
    int sum = add(5, 3);
    std::cout << "Sum: " << sum << std::endl;

    // Using the return value of divide function
    double result = divide(10.0, 2.0);
    std::cout << "Division result: " << result << std::endl;

    // Using the return value of isEven function
    int number = 7;
    if (isEven(number)) {
        std::cout << number << " is even" << std::endl;
    } else {
        std::cout << number << " is odd" << std::endl;
    }

    return 0;
}

