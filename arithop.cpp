#include <iostream>
using namespace std;

int main()
{

    int num1, num2;

    std::cout << "Enter number 1 ";
    std::cin >> num1;

    std::cout << "Enter number 2 ";
    std::cin >> num2;

    std::cout << "Addition: " << num1 + num2 << std::endl;

    std::cout << "Subtraction: " << num1 - num2 << std::endl;

    std::cout << "Product: " << num1 * num2 << std::endl;

    std::cout << "Division: " << num1 / num2 << std::endl;

    return 0;
}