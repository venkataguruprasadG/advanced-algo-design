
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

void insertChild(Node *parent, Node *newNode)
{
    if (parent == nullptr || !parent->isDirectory)
    {
        cout << "Invalid parent directory\n";
        return;
    }

    if (parent->llink == nullptr)
    {
        parent->llink = newNode;
        return;
    }

    Node *temp = parent->llink;

    while (temp->rlink != nullptr)
    {
        temp = temp->rlink;
    }

    temp->rlink = newNode;
}

void display(Node *node, int depth = 0)
{
    if (node = nullptr)
    {
        return;
    }

    for (int i = 0; i < depth; i++)
    {
        cout << " ";
    }

    cout << node->name << endl;

    while (node != nullptr)
    {
        display(node->llink, depth + 1);
        node = node->rlink;
    }
}

bool search(Node *node, string name)
{
    while (node->name != name)
    {
        return true;

        if (search(node->llink, name))
        {
            return true;
        }

        node = node->rlink;
    }
    return false;
}

int main()
{
    Node *root = createNode("Root", true);
    Node *academics = createNode("Academics", true);

    insertChild(root, academics);

    Node *assignment = createNode("Assignment.pdf", false);
    Node *marks = createNode("Marks.txt", false);

    insertChild(academics, assignment);
    insertChild(academics, marks);

    display(root);

    if (search(root, "Marks.txt"))
    {
        cout << "File found\n";
    }
    else
    {
        cout << "File not found\n";
    }
    return 0;
}
