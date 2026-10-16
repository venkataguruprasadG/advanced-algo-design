
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

Node *createNode(string name, bool isDirectory)
{
    Node *newNode = new Node;
    newNode->name = name;
    newNode->isDirectory = isDirectory;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;
    return newNode;
}

int main()
{
    Node *root = createNode("Root", true);
    Node *academics = createNode("Academics", true);
    Node *personal = createNode("personal", false);
    Node *assignment = createNode("Assignment.pdf", false);

    root->llink = academics;
    academics->rlink = personal;
    academics->llink = assignment;

    personal->llink = nullptr;
    personal->rlink = nullptr;

    cout << root->name << endl;
    cout << root->llink->name << endl;
    cout << root->llink->rlink->name << endl;
    cout << root->llink->llink->name << endl;

    return 0;
}
