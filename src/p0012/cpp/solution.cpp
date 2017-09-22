class Solution {
public:
    static const char *const sd[], *const sc[], *const sx[], *const si[];

    string intToRoman(int i) {
        return string(sd[i / 1000]) + string(sc[i % 1000 / 100]) + string(sx[i % 100 / 10]) + string(si[i % 10]);
    }
};

const char *const Solution::sd[] = {"", "M", "MM", "MMM"};
const char *const Solution::sc[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char *const Solution::sx[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *const Solution::si[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
