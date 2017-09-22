#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef vector<int> Point;

    class comp {
    public:
        bool operator() (const Point &a, const Point &b) const {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };

    vector<Point> kClosest(vector<Point> &points, int K) {
        priority_queue<Point, vector<Point>, comp> q;
        for (auto &point : points) {
            for (q.push(point); q.size() > K; q.pop());
        }
        vector<Point> result;
        for (; !q.empty(); q.pop()) {
            result.push_back(q.top());
        }
        return result;
    }
};