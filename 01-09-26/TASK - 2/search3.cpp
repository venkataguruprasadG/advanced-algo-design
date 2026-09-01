#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{

    // 1. Open the file visibly in Windows
    system("start TEST.txt");

    // 2. Open the same file in C++ for reading
    ifstream file("TEST.txt");

    string target = "what";

    string word;
    bool found = false;

    while (file >> word)
    {
        if (word == target)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Target word found!" << endl;
    else
        cout << "Target word not found!" << endl;

    file.close();

    return 0;
}