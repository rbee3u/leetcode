#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;


class Solution {
public:
    Solution(int n_rows, int n_cols) {
        this->n_rows = n_rows;
        this->n_cols = n_cols;
        total = n_rows * n_cols;
        mt = mt19937(rd());
        dist = uniform_int_distribution<int>();
    }

    vector<int> flip() {
        int r = dist(mt) % (total--);
        int x = r;
        if (matrix.count(x)) {
            x = matrix[r];
        }
        int y = total;
        if (matrix.count(total)) {
            y = matrix[total];
        }
        matrix[r] = y;
        return {x / n_cols, x % n_cols};
    }

    void reset() {
        matrix.clear();
        total = n_rows * n_cols;
    }

private:
    int n_rows, n_cols, total;
    unordered_map<int, int> matrix;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<int> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
