class Solution:
    def intToRoman(self, i: int) -> str:
        sd = ["", "M", "MM", "MMM"]
        sc = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        sx = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        si = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        return sd[i // 1000] + sc[i % 1000 // 100] + sx[i % 100 // 10] + si[i % 10]
