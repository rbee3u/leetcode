class NumArray {
private:
    vector<int> mnums, array;
    inline int calcsum(int i) {
        int ret = 0;
        for (; i > 0; i -= i&(-i)) {
            ret += array[i];
        }
        return ret;
    }
    inline void upgrade(int i, int incr) {
        int as = array.size();
        for (; i < as; i += i&(-i)) {
            array[i] += incr;
        }
    }
public:
    NumArray(vector<int> &nums) {
        int nums_size=nums.size(); mnums=nums;
        array.resize(nums_size+1, 0);
        for (int i = 0; i < nums_size; ++i) {
            upgrade(i+1, nums[i]);
        }
    }

    void update(int i, int val) {
        upgrade(i+1, val-mnums[i]);
        mnums[i] = val;
    }

    int sumRange(int i, int j) {
        return (calcsum(j+1) - calcsum(i));
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
