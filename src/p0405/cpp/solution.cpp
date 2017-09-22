#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string toHex(uint32_t num) {
        string hex;
        bool flag = false;
        Byte *bs = (Byte*)&num;
        for (int i = 3; i >= 0; i--) {
            if (bs[i].y || flag) {
                hex.push_back(map[bs[i].y]);
                flag = true;
            }
            if (bs[i].x || flag || i == 0) {
                hex.push_back(map[bs[i].x]);
                flag = true;
            }
        }
        return hex;
    }

private:
    struct Byte { unsigned char x: 4; unsigned char y: 4; };
    static constexpr char map[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                                   '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
};
