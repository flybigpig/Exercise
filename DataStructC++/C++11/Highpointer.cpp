#include <iostream>
void swapPointers(int **pp1, int **pp2)
{
    int *temp = *pp1;
    *pp1 = *pp2;
    *pp2 = temp;
}
int main()
{
    int num1 = 10;
    int num2 = 20;
    int *p1 = &num1;
    int *p2 = &num2;
    std::cout << "Before swap: *p1 = " << *p1 << ", *p2 = " << *p2 << std::endl;
    swapPointers(&p1, &p2);
    std::cout << "After swap: *p1 = " << *p1 << ", *p2 = " << *p2 << std::endl;
    return 0;
}