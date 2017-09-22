#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(double r, double x, double y): r(r), x(x), y(y) {
        mt = mt19937(rd());
        dist = uniform_real_distribution<double>();
    }

    vector<double> randPoint() {
        double theta = dist(mt) * 2 * M_PI;
        double realr = sqrt(dist(mt)) * r;
        return {x + realr * cos(theta), y + realr * sin(theta)};
    }

private:
    double r, x, y;
    random_device rd;
    mt19937 mt;
    uniform_real_distribution<double> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */