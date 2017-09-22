class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer({0});
        for (int i = 1; i <= n; ++i) {
            next(answer, i - 1);
        }
        return answer;
    }
private:
    void next(vector<int> &array, int h) {
        vector<int> temp; temp.swap(array);
        for (auto it=temp.begin();  it != temp.end();  ++it) {
            array.push_back(*it);
        }
        for (auto it=temp.rbegin(); it != temp.rend(); ++it) {
            array.push_back(*it | (1 << h));
        }
    }
};
