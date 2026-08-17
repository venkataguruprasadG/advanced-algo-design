#include <iostream>
using namespace std;

bool isFull(int top)
{
    return top == 4;
}

bool isEmpty(int top)
{
    return top == -1;
}

void push(int stack[], int &top, int num)
{
    if (isFull(top))
    {
        cout << "No space to add anymore." << endl;
    }
    else
    {
        top++;
        stack[top] = num;

        cout << num << " pushed into stack." << endl;
    }
}

void pop(int stack[], int &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        int value = stack[top];
        top--;

        cout << value << " popped from stack." << endl;
    }
}

int main()
{
    int stack[5];
    int top = -1;

    int n;

    cout << "Enter number you want to push: ";
    cin >> n;

    push(stack, top, n);

    pop(stack, top);

    return 0;
}