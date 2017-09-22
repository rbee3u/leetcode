class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        int winner = arr[0], score = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (winner < arr[i]) {
                winner = arr[i];
                score = 0;
            }
            if (++score == k) break;
        }
        return winner;
    }
};
