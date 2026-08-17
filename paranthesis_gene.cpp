#include <iostream>
#include <string>
using namespace std;

void generateParentheses(string current, int open, int close, int n)
{
    // Base case
    if (current.length() == 2 * n)
    {
        cout << current << endl;
        return;
    }

    // Add opening parenthesis
    if (open < n)
    {
        generateParentheses(current + "(", open + 1, close, n);
    }

    // Add closing parenthesis
    if (close < open)
    {
        generateParentheses(current + ")", open, close + 1, n);
    }
}

int main()
{
    int n;

    cout << "Enter number of pairs: ";
    cin >> n;

    generateParentheses("", 0, 0, n);

    return 0;
}