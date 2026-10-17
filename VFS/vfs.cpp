
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

const int MAX = 100;
int cnt = 0;

Node *createNode(string name, bool isDirectory)
{
    if (cnt >= MAX)
    {
        cout << "Maximum node limit reached\n";
        return nullptr;
    }

    Node *newNode = new Node;
    newNode->name = name;
    newNode->isDirectory = isDirectory;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;

    cnt++;
    return newNode;
}

void insertChild(Node *parent, Node *newNode)
{
    if (newNode == nullptr)
    {
        cout << "Invalid new node\n";
        return;
    }
    if (parent == nullptr || !parent->isDirectory)
    {
        cout << "Invalid parent directory\n";
        delete newNode;
        cnt--;
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

bool deleteDirectory(Node *parent, string target)
{
    if (parent == nullptr || !parent->isDirectory)
    {
        return false;
    }

    Node *current = parent->llink;
    Node *previous = nullptr;

    while (current != nullptr)
    {
        if (current->name == target)
        {
            // Target must be an empty directory
            if (!current->isDirectory ||
                current->llink != nullptr)
            {
                return false;
            }

            // Remove the directory from the sibling chain
            if (previous == nullptr)
            {
                parent->llink = current->rlink;
            }
            else
            {
                previous->rlink = current->rlink;
            }

            delete current;
            cnt--;
            return true;
        }

        previous = current;
        current = current->rlink;
    }

    return false;
}

void display(Node *node, int depth = 0)
{
    if (node == nullptr)
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

bool deleteFile(Node *parent, string target)
{
    if (parent == nullptr || !parent->isDirectory)
    {
        return false;
    }

    Node *current = parent->llink;
    Node *previous = nullptr;

    while (current != nullptr)
    {
        if (current->name == target)
        {
            if (current->isDirectory)
            {
                cout << "Target is a directory\n";
                return false;
            }

            if (previous == nullptr)
            {
                parent->llink = current->rlink;
            }
            else
            {
                previous->rlink = current->rlink;
            }

            delete current;
            cnt--;
            return true;
        }

        previous = current;
        current = current->rlink;
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

    if (deleteFile(academics, "Assignment.pdf"))
    {
        cout << "File deleted\n";
    }
    else
    {
        cout << "Deletion failed\n";
    }

    display(root);
    return 0;
}
