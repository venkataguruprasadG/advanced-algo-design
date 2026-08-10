#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int num1;
    cout << "Enter a number: ";
    cin >> num1;

    factorial(num1);
    cout << "The factorial of the number is: " << factorial(num1) << endl;
}