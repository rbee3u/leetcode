class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // 4 * x + 2 * y = tomatoSlices
        // 1 * x + 1 * y = cheeseSlices
        int x2 = tomatoSlices - 2 * cheeseSlices;
        if (x2 % 2 == 0) {
            int x = x2 / 2, y = cheeseSlices - x;
            if (x >= 0 && y >= 0) return {x, y};
        }
        return {};
    }
};
