
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
    Node root, academics, personal;
    Node assignment, resume;

    root.name = "Root";
    root.isDirectory = true;
    root.llink = &academics;
    root.rlink = nullptr;

    academics.name = "Academics";
    academics.isDirectory = true;
    academics.llink = &assignment;
    academics.rlink = &personal;

    personal.name = "Personal";
    personal.isDirectory = true;
    personal.llink = &resume;
    personal.rlink = nullptr;

    assignment.name = "Assignment.pdf";
    assignment.isDirectory = false;
    assignment.llink = nullptr;
    assignment.rlink = nullptr;

    resume.name = "Resume.pdf";
    resume.isDirectory = false;
    resume.llink = nullptr;
    resume.rlink = nullptr;

    cout << root.name << endl;
    cout << root.llink->name << endl;
    cout << root.llink->rlink->name << endl;
    cout << root.llink->llink->name << endl;

    return 0;
}
