#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    vector<Point> outerTrees(vector<Point> &points) {
        auto cmp = [](const Point &p, const Point &q) {
            return p.x == q.x ? p.y < q.y : p.x < q.x;
        };
        sort(points.begin(), points.end(), cmp);
        vector<int> hull; int top = 0, i = 0;
        for (int base = 0; i < points.size(); i++) {
            while (top - base >= 2 && !isCCW(points[hull[top - 2]], points[hull[top - 1]], points[i])) {
                hull.pop_back(); top--;
            }
            hull.push_back(i); top++;
        }
        for (int base = top; i-- > 0;) {
            while (top - base >= 2 && !isCCW(points[hull[top - 2]], points[hull[top - 1]], points[i])) {
                hull.pop_back(); top--;
            }
            hull.push_back(i); top++;
        }
        unordered_set<int> visited;
        vector<Point> result;
        for (auto j : hull) {
            if (!visited.count(j)) {
                result.push_back(points[j]);
                visited.insert(j);
            }
        }
        return result;
    }

private:
    bool isCCW(const Point &a, const Point &b, const Point &c) {
        int x1 = b.x - a.x, y1 = b.y - a.y;
        int x2 = c.x - b.x, y2 = c.y - b.y;
        return ((x1 * y2 - x2 * y1) >= 0);
    }
};
