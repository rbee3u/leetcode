#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef tuple<int, int> Position;
typedef tuple<int, int> Fraction;

class Matrix {
public:
    Matrix(const vector<int> &a) : v(a), step(1) {
        rowsnum = colsnum = static_cast<int>(v.size() - 1);
        auto p = 1;
        while (p < rowsnum) {
            p = p * 2;
        }
        rows = cols = p;
    }

    int Rows() const { return (rows + step - 1) / step; }

    int Cols() const { return (cols + step - 1) / step; }

    Fraction Elem(const Position &pos) const {
        auto i = get<0>(pos) * step;
        auto j = get<1>(pos) * step;
        if (i >= rowsnum || j >= colsnum) {
            return {1, 0};
        }
        return {v[i], v[colsnum - j]};
    }

    bool Less(const Position &pa, const Position &pb) const {
        auto fa = Elem(pa), fb = Elem(pb);
        auto diff = get<0>(fa) * get<1>(fb) - get<0>(fb) * get<1>(fa);
        return (diff != 0) ? (diff < 0) : (pa < pb);
    }

    int FindRankOfPosition(const Position &pos) const {
        auto rank = 1;
        for (auto i = 0, j = Cols() - 1; i < Rows(); i++) {
            for (; j >= 0 && !Less({i, j}, pos); j--);
            rank += (j + 1);
        }
        return rank;
    }

    vector<Position> FindPositionsOfRange(const Position &lower, const Position &upper) {
        vector<Position> positions;
        for (auto i = 0, l = Cols() - 1, r = l; i < Rows(); i++) {
            for (; l >= 0 && !Less({i, l}, lower); l--);
            for (; r >= 0 && Less(upper, {i, r}); r--);
            for (auto j = l + 1; j <= r; j++) {
                positions.emplace_back(i, j);
            }
        }
        return positions;
    }

    static int CalcLowerRank(int k) {
        return (k + 3) / 4;
    }

    static int CalcUpperRank(int k, int n, int m) {
        auto tmp = (k + n + m + 2) / 4;
        if (tmp > m * n / 4) {
            tmp = m * n / 4;
        }
        return tmp;
    }

    tuple<Position, Position> Biselect(int r1, int r2) {
        auto n = Rows(), m = Cols();
        if (n == 1) {
            return {{0, r1 - 1}, {0, r2 - 1}};
        }
        if (m == 1) {
            return {{r1 - 1, 0}, {r2 - 1, 0}};
        }

        auto cmp = [this](const Position &pa, const Position &pb) {
            return Less(pa, pb);
        };

        step = step * 2;
        auto[p1l, p1u] = Biselect(CalcLowerRank(r1), CalcUpperRank(r1, n, m));
        step = step / 2;
        p1l = {get<0>(p1l) * 2, get<1>(p1l) * 2};
        p1u = {get<0>(p1u) * 2 + 1, get<1>(p1u) * 2 + 1};
        auto p1s = FindPositionsOfRange(p1l, p1u);
        auto r1l = FindRankOfPosition(p1l);
//        auto r1u = FindRankOfPosition(p1u);
        auto p1 = p1s.begin() + (r1 - r1l);

        nth_element(p1s.begin(), p1, p1s.end(), cmp);

        step = step * 2;
        auto[p2l, p2u] = Biselect(CalcLowerRank(r2), CalcUpperRank(r2, n, m));
        step = step / 2;
        p2l = {get<0>(p2l) * 2, get<1>(p2l) * 2};
        p2u = {get<0>(p2u) * 2 + 1, get<1>(p2u) * 2 + 1};
        auto p2s = FindPositionsOfRange(p2l, p2u);
        auto r2l = FindRankOfPosition(p2l);
//        auto r2u = FindRankOfPosition(p2u);
        auto p2 = p2s.begin() + (r2 - r2l);

        nth_element(p2s.begin(), p2, p2s.end(), cmp);

        return {*p1, *p2};
    }

private:
    const vector<int> &v;
    int rows, cols, step;
    int rowsnum, colsnum;
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(const vector<int> &A, int K) {
        Matrix mat(A);
        auto[lowerPos, upperPos] = mat.Biselect(K, K);
        auto[numerator, denominator] = mat.Elem(lowerPos);
        return {numerator, denominator};
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 37, 113, 461, 809, 947, 983, 2441, 2477, 2543, 2953, 2963, 3163, 3167, 3389, 4051, 4079, 4127,
                     4219, 4423, 4451, 5507, 5743, 6151, 6311, 6397, 6997, 7253, 7297, 7927, 8663, 8863, 8893, 9377,
                     9551, 10061, 10301, 10303, 10321, 10357, 10607, 10903, 11717, 11897, 12497, 12619, 12829, 13003,
                     13241, 14537, 14591, 15149, 15241, 15991, 16001, 16103, 16249, 16319, 16603, 16921, 17029, 17209,
                     17231, 17491, 17497, 17749, 18233, 19433, 19469, 19471, 19993, 20347, 20639, 20707, 20903, 21391,
                     21523, 21613, 21661, 21757, 22153, 22283, 22307, 23143, 23291, 23593, 23789, 23909, 24151, 25127,
                     25919, 26041, 26513, 26777, 26951, 26987, 28097, 28571, 28723, 29587};
//    vector<int> A = {1,2,3,5,7,9};
//    auto result = sol.kthSmallestPrimeFraction(A, 3000);
    auto result = sol.kthSmallestPrimeFraction(A, 4294);
//    auto result = sol.kthSmallestPrimeFraction(A, 25);
    cout << result[0] << "/" << result[1] << endl;
    return 0;
}