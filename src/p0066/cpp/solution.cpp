class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer;
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (auto x : digits) {
            answer.push_back((x+carry)%10);
            carry = (x + carry) / 10;
        }
        if (carry) answer.push_back(carry);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
