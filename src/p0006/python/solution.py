class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows <= 1:
            return s
        result = []
        for k in range(num_rows):
            x = k
            while x < len(s):
                result.append(s[x])
                x += 2 * (num_rows - 1)
                if 0 < k < (num_rows - 1):
                    y = x - k - k
                    if y < len(s):
                        result.append(s[y])
        return ''.join(result)
