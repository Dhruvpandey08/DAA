#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    int crossProduct(const Point &other) const
    {
        return (x * other.y) - (y * other.x);
    }
};

int main()
{
    Point p0(0, 0); 
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    Point p1(x1, y1);
    Point p2(x2, y2);
    int crossProduct = p1.crossProduct(p2);

    if (crossProduct > 0)
    {
        cout << "CounterClockWise" << endl;
    }
    else if (crossProduct < 0)
    {
        cout << "ClockWise" << endl;
    }
    else
    {
        cout << "Collinear" << endl;
    }
    return 0;
}