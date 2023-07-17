#include <iostream>
#include <vector>
using namespace std;

class Line {
public:
    struct Point {
        int x, y;
    };

    bool on_segment(const Point& p, const Point& q, const Point& r) {
        if (min(p.x, r.x) <= q.x && q.x <= max(p.x, r.x) && min(p.y, r.y) <= q.y && q.y <= max(p.y, r.y)) {
            return true;
        }
        return false;
    }

    int direction(const Point& p, const Point& q, const Point& r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }

    bool intersect(const Point& p1, const Point& q1, const Point& p2, const Point& q2, Point& intersectPoint) {
        int d1 = direction(p1, q1, p2);
        int d2 = direction(p1, q1, q2);
        int d3 = direction(p2, q2, p1);
        int d4 = direction(p2, q2, q1);

        if ((d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0)) {
            double ua = static_cast<double>(direction(p1, p2, q1)) / direction(p1, q1, q2);
            intersectPoint.x = p2.x + ua * (q2.x - p2.x);
            intersectPoint.y = p2.y + ua * (q2.y - p2.y);
            return true;
        }

        if (d1 == 0 && on_segment(p1, p2, q1)) {
            intersectPoint = p2;
            return true;
        }
        if (d2 == 0 && on_segment(p1, q2, q1)) {
            intersectPoint = q2;
            return true;
        }
        if (d3 == 0 && on_segment(p2, p1, q2)) {
            intersectPoint = p1;
            return true;
        }
        if (d4 == 0 && on_segment(p2, q1, q2)) {
            intersectPoint = q1;
            return true;
        }

        return false;
    }

    void printIntersectingPairs(const vector<Point>& points) {
        int n = points.size();
        for (int i = 0; i < n - 3; i += 2) {
            for (int j = i + 2; j < n - 1; j += 2) {
                Point intersectPoint;
                if (intersect(points[i], points[i + 1], points[j], points[j + 1], intersectPoint)) {
                    cout << "Intersecting Points: (" << intersectPoint.x << ", " << intersectPoint.y << ") and (" << points[i].x << ", " << points[i].y << ")" << endl;
                }
            }
        }
    }
};

int main() {
    Line line1;

    int n;
    cin >> n;

    vector<Line::Point> points;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        points.push_back({ x1, y1 });
        points.push_back({ x2, y2 });
    }

    line1.printIntersectingPairs(points);

    return 0;
}
