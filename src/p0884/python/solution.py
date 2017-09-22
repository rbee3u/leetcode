from typing import List


class Solution:
    def uncommonFromSentences(self, la: str, lb: str) -> List[str]:
        da, db = {}, {}
        for k in la.split():
            da[k] = da.get(k, 0) + 1
        for k in lb.split():
            db[k] = db.get(k, 0) + 1
        result = []
        for k, v in da.items():
            if v + db.get(k, 0) < 2:
                result.append(k)
        for k, v in db.items():
            if v + da.get(k, 0) < 2:
                result.append(k)
        return result
