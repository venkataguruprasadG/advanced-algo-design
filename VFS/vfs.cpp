#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    bool isDirectory;
    Node *llink;
    Node *rlink;
};

int main()
{
    Node root;
    root.name = "root";
    root.isDirectory = true;
    root.llink = nullptr;
    root.rlink = nullptr;

    cout << root.name << endl;

    return 0;
}