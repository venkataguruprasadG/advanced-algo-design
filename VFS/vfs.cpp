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

    Node Academics;
    Academics.name = "Academics";
    Academics.isDirectory = true;

    Academics.llink = nullptr;
    Academics.rlink = nullptr;

    root.llink = &Academics;
    root.rlink = nullptr;

    cout << root.name << endl;

    return 0;
}