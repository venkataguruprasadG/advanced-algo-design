#include <iostream>
using namespace std;

const int NUM_STACKS = 3;
const int SIZE = 5;

int stacks[NUM_STACKS][SIZE];
int top[NUM_STACKS] = {-1, -1, -1};

bool isEmpty(int stackNumber)
{
    return top[stackNumber] == -1;
}

bool isFull(int stackNumber)
{
    return top[stackNumber] == SIZE - 1;
}

void push(int stackNumber, int value)
{
    if (isFull(stackNumber))
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    top[stackNumber]++;
    stacks[stackNumber][top[stackNumber]] = value;
}

int pop(int stackNumber)
{
    if (isEmpty(stackNumber))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }

    int value = stacks[stackNumber][top[stackNumber]];
    top[stackNumber]--;

    return value;
}

int main()
{
    push(0, 10);
    push(0, 20);

    push(1, 100);
    push(1, 200);

    push(2, 50);

    cout << "Popped from Stack 0: " << pop(0) << endl;
    cout << "Popped from Stack 1: " << pop(1) << endl;
    cout << "Popped from Stack 2: " << pop(2) << endl;

    cout << "Stack 0 Empty: " << isEmpty(0) << endl;
    cout << "Stack 1 Full: " << isFull(1) << endl;

    return 0;
}