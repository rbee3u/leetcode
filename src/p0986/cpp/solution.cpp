#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval> &A, vector<Interval> &B) {
        vector<Interval> result;
        auto a = A.begin(), b = B.begin();
        while (a != A.end() && b != B.end()) {
            if (a->start <= b->start) {
                if (a->end < b->start) {
                    a++;
                } else if (b->end <= a->end) {
                    result.emplace_back(b->start, b->end);
                    b++;
                } else {
                    result.emplace_back(b->start, a->end);
                    a++;
                }
            } else {
                if (b->end < a->start) {
                    b++;
                } else if (a->end <= b->end) {
                    result.emplace_back(a->start, a->end);
                    a++;
                } else {
                    result.emplace_back(a->start, b->end);
                    b++;
                }
            }
        }
        return result;
    }
};
