#include <iostream>
using namespace std;

class Line
{
public:
    bool on_segment(int xi, int xj, int xk, int yi, int yj, int yk)
    {
        if (min(xi, xj) <= xk && xk <= max(xi, xj) && min(yi, yj) <= yk && yk <= max(yi, yj))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int direction(int xi, int yi, int xj, int yj, int xk, int yk)
    {
        return (xk - xi) * (yj - yi) - (xj - xi) * (yk - yi);
    }

    bool intersect(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y, int& intersectX, int& intersectY)
    {
        int d1, d2, d3, d4;
        d1 = direction(p3x, p3y, p4x, p4y, p1x, p1y);
        d2 = direction(p3x, p3y, p4x, p4y, p2x, p2y);
        d3 = direction(p1x, p1y, p2x, p2y, p3x, p3y);
        d4 = direction(p1x, p1y, p2x, p2y, p4x, p4y);

        if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))
        {
            intersectX = ((p1x * d2 - p2x * d1) * (p4x - p3x) - (p3x * d4 - p4x * d3) * (p2x - p1x)) / ((d2 - d1) * (p4x - p3x) - (d4 - d3) * (p2x - p1x));
            intersectY = ((p1y * d2 - p2y * d1) * (p4y - p3y) - (p3y * d4 - p4y * d3) * (p2y - p1y)) / ((d2 - d1) * (p4y - p3y) - (d4 - d3) * (p2y - p1y));
            return true;
        }
        else if (d1 == 0 && on_segment(p3x, p3y, p4x, p4y, p1x, p1y))
        {
            intersectX = p1x;
            intersectY = p1y;
            return true;
        }
        else if (d2 == 0 && on_segment(p3x, p3y, p4x, p4y, p2x, p2y))
        {
            intersectX = p2x;
            intersectY = p2y;
            return true;
        }
        else if (d3 == 0 && on_segment(p1x, p1y, p2x, p2y, p3x, p3y))
        {
            intersectX = p3x;
            intersectY = p3y;
            return true;
        }
        else if (d4 == 0 && on_segment(p1x, p1y, p2x, p2y, p4x, p4y))
        {
            intersectX = p4x;
            intersectY = p4y;
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Line line1;
    int p1x, p1y;
    cin >> p1x >> p1y;
    int p2x, p2y;
    cin >> p2x >> p2y;
    int p3x, p3y;
    cin >> p3x >> p3y;
    int p4x, p4y;
    cin >> p4x >> p4y;
    int intersectX, intersectY;
    bool isIntersect = line1.intersect(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, intersectX, intersectY);
    if (isIntersect)
    {
        cout << "Lines intersect at (" << intersectX << ", " << intersectY << ")" << endl;
    }
    else
    {
        cout << "Lines do not intersect" << endl;
    }
    return 0;
}
