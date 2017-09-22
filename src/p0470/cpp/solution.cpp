#include <iostream>
#include <random>

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int count7 = 0;
int count10 = 100000000;

int rand7() {
    count7++;
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 7);
    return dis(gen);
}

class Solution {
public:
    Solution() : state(0), range(1) {}

    int rand10() {
        for (;;) {
            if (range <= INT_MAX / 7) {
                state *= 7; range *= 7;
                state += rand7() - 1;
                continue;
            }
            if (state >= range/10*10) {
                state %= 10; range %= 10;
                continue;
            }
            int r = state % 10;
            state /= 10; range /= 10;
            return r + 1;
        }
    }

private:
    int state, range;
};

int main() {
    Solution sol;
    for (int i = 0; i < count10; i++) {
        sol.rand10();
    }
    std::cout << double(count7) / double(count10) << std::endl;
    return 0;
}
