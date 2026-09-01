#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("sample_text.txt");
    stringstream buffer;
    buffer << file.rdbuf();

    string content = buffer.str();

    if (content.find("href") != std::string::npos)
    {
        std::cout << "SUCCESS: 'href' was found in the file!" << std::endl;
    }
    else
    {
        std::cout << "NOT FOUND: 'href' is not in the file." << std::endl;
    }
    return 0;
}