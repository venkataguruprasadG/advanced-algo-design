#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct City
{
    string name;
    int x;
    int y;
};

double calculateDistance(const City &city1, const City &city2)
{
    int distanceX = city2.x - city1.x;
    int distanceY = city2.y - city1.y;
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}

int main()
{
    vector<City> cities = {
        {"Coimbatore", 11, 77},
        {"Chennai", 13, 80},
        {"Bangalore", 12, 77},
        {"hyderabad", 17, 78},
        {"Mumbai", 19, 72},
        {"Delhi", 28, 77},
        {"Kolkata", 22, 88},
        {"Pune", 18, 73},
        {"Jaipur", 26, 75},
        {"Lucknow", 26, 80}};
}
