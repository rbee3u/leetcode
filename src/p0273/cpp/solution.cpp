class Solution {
private:
    string num2str(int num) {
        string unit[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"
        ,"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string decade[10] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string ret;
        int i, i0, i00, tmp=num%1000;
        i00 = tmp / 100; tmp %= 100;
        i0 = tmp / 10; i = tmp % 10;
        if (tmp < 20) {
            ret = unit[tmp];
        } else {
            ret = unit[i];
            if (ret != "") {
                ret = " " + ret;
            }
            ret = decade[i0] + ret;
        }
        if (i00 > 0) {
            if (ret != "") {
                ret = " " + ret;
            }
            ret = unit[i00] + " Hundred" + ret;
        }
        return ret;
    }
public:
    string numberToWords(int num) {
        string ret, tmp;
        ret = num2str(num % 1000); num /= 1000;
        tmp = num2str(num % 1000); num /= 1000;
        if (tmp != "") {
            if (ret != "") ret = " " + ret;
            ret = tmp + " Thousand" + ret;
        }
        tmp = num2str(num % 1000); num /= 1000;
        if (tmp != "") {
            if (ret != "") ret = " " + ret;
            ret = tmp + " Million" + ret;
        }
        tmp = num2str(num % 1000); num /= 1000;
        if (tmp != "") {
            if (ret != "") ret = " " + ret;
            ret = tmp + " Billion" + ret;
        }
        if (ret == "") {
            ret += "Zero";
        }
        return ret;
    }
};
