from typing import List


class Solution:
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        result, sources, row, col, add, sub = [], {}, {}, {}, {}, {}
        for lamp in lamps:
            x, y = lamp[0], lamp[1]
            if x not in sources:
                sources[x] = set()
            sources[x].add(y)
            row[x] = row.get(x, 0) + 1
            col[y] = col.get(y, 0) + 1
            add[x + y] = add.get(x + y, 0) + 1
            sub[x - y] = sub.get(x - y, 0) + 1
        for query in queries:
            i, j = query[0], query[1]
            if row.get(i, 0) > 0 or col.get(j, 0) > 0 or add.get(i + j, 0) > 0 or sub.get(i - j, 0) > 0:
                result.append(1)
            else:
                result.append(0)
            for x in range(i - 1, i + 2):
                for y in range(j - 1, j + 2):
                    if x in sources and y in sources[x]:
                        sources[x].remove(y)
                        row[x] = row[x] - 1
                        col[y] = col[y] - 1
                        add[x + y] = add[x + y] - 1
                        sub[x - y] = sub[x - y] - 1
        return result

