#include <iostream>
#include <cstdint>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00U) >> 8) | ((n & 0x00ff00ffU) << 8);
        n = ((n & 0xf0f0f0f0U) >> 4) | ((n & 0x0f0f0f0fU) << 4);
        n = ((n & 0xccccccccU) >> 2) | ((n & 0x33333333U) << 2);
        n = ((n & 0xaaaaaaaaU) >> 1) | ((n & 0x55555555U) << 1);
        return n;
    }
};
