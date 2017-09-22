# -*- coding: utf-8 -*-

class bitset:

    def __init__(self, size=0):
        self._size = size
        self._v = bytearray((size + 7) // 8)

    def __len__(self):
        return self._size

    def __getitem__(self, pos):
        return 1 & (self._v[pos//8] >> pos%8)

    def __setitem__(self, pos, val):
        if val == 0:
            self._v[pos//8] &= ~(1 << pos%8)
        else:
            self._v[pos//8] |=  (1 << pos%8)

    def append(self, val):
        if self._size == len(self._v)*8:
            self._v.append(0)
        self._size = self._size + 1
        self[self._size - 1] = val

    def extend(self, vals):
        for val in vals:
            self.append(val)

    def slice(self, begin, end):
        return [self[x] for x in range(begin, end)]

    def to_bytearray(self):
        return self._v

    def from_bytearray(self, ba):
        self._size = len(ba)*8
        self._v = ba


def i2b(i, n):
    b = [0] * n
    for x in range(n):
        b[x], i = i % 2, i // 2
    return b

def b2i(b):
    i, p = 0, 1
    for x in b:
        i, p = i + x * p, p * 2
    return i

def enc(x):
    return (x*2 if (x>=0) else (-1-x*2))

def dec(y):
    return ((-1-y)//2 if y%2 else y//2)


cutpoints = [14,14,14,14,32]


def write_to_buffer(nums):
    bs = bitset()
    for x in nums:
        i, prefix = enc(x), []
        begin, cut, end = 0, 0, 0
        for t in cutpoints:
            begin, cut, end = end, t, end+2**t
            if i < end: break
            prefix.append(1)
        if cut < 32:
            prefix.append(0)
        i = i - begin
        bs.extend(prefix+i2b(i, cut))

    return bs.to_bytearray()


def read_from_buffer(buf):
    bs = bitset()
    bs.from_bytearray(buf)
    nums, k, n = [], 0, len(bs)
    while k < n:
        begin, cut, end = 0, 0, 0
        for t in cutpoints:
            begin, cut, end = end, t, end+2**t
            if (bs[k]==0) or (cut>=32): break
            k = k + 1
        if cut < 32: k = k + 1
        if k + cut > n: break
        i = begin + b2i(bs.slice(k, k+cut))
        nums.append(dec(i))
        k = k + cut
    return nums
