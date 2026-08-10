#include <iostream>
using namespace std;

int sumofnatural(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sumofnatural(n - 1);
    }
}

int main()
{
    int num;

    cout << "Enter the number of which you want to find the sum of n natural numbers: ";

    cin >> num;

    cout << "The sum of first " << num << " natural numbers is: " << sumofnatural(num) << endl;
    return 0;
}