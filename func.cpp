#include <iostream>
using namespace std;

int square(int n)
{
    return n * 2;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    square(n);
    cout << "the square of the number is: " << square(n) << endl;
    return 0;
}