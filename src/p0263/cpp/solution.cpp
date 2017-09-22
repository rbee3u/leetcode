class Solution {
public:
    bool isUgly(int num) {
        if (num > 0) for (int d=2; d<=5; ++d) {
            for (; 0==num%d; num/=d);
        }
        return num == 1;
    }
};
