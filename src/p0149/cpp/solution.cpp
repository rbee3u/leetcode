#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;


struct Point {
    int x, y;
};

template <class T> void hash_combine(std::size_t &seed, const T &v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

bool operator==(const Point &lhs, const Point &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

namespace std {
    template <> struct hash<Point> {
        size_t operator()(const Point &p) const {
            size_t seed = 0;
            hash_combine(seed, p.x);
            hash_combine(seed, p.y);
            return seed;
        }
    };
}

int64_t gcd_euclid(int64_t n, int64_t m) {
    if (n < 0) n = -n;
    if (m < 0) m = -m;
    if (n < m) swap(n, m);
    while (m > 0) {
        auto t = n % m; n = m; m = t;
    }
    return n;
}

struct Line {
    int64_t a, b, c; // a*x - b*y = c
    Line(Point &p1, Point &p2) : a(p2.y - p1.y), b(p2.x - p1.x) {
        c = int64_t(p1.x) * int64_t(p2.y) - int64_t(p2.x) * int64_t(p1.y);
        if (a < 0) { a = -a; b = -b; c = -c; }
        if (a == 0 && b < 0) { b = -b; c = -c; }
        int64_t g = gcd_euclid(gcd_euclid(a, b), c);
        a /= g; b /= g; c /= g;
    }
};

bool operator==(const Line &lhs, const Line &rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
}

namespace std {
    template <> struct hash<Line> {
        size_t operator()(const Line &l) const {
            size_t seed = 0;
            hash_combine(seed, l.a);
            hash_combine(seed, l.b);
            hash_combine(seed, l.c);
            return seed;
        }
    };
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<Point, int> counts;
        vector<Point> unique;
        for (auto &point : points) {
            if (counts.count(point) == 0) {
                unique.push_back(point);
            }
            counts[point]++;
        }
        unordered_map<Line, unordered_set<Point>> groups;
        for (auto i = 0; i < unique.size(); i++) {
            for (auto j = 0; j < i; j++) {
                Line line(unique[i], unique[j]);
                groups[line].insert(unique[i]);
                groups[line].insert(unique[j]);
            }
        }
        int result = 0;
        for (auto &count : counts) {
            result = max(result, count.second);
        }
        for (auto &group : groups) {
            int total = 0;
            for (auto &point : group.second) {
                total += counts[point];
            }
            result = max(result, total);
        }
        return result;
    }
};
