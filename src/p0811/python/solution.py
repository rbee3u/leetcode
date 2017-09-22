from typing import List


class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counts = {}
        for cpdomain in cpdomains:
            tokens = cpdomain.split(' ')
            count = int(tokens[0])
            tokens = tokens[1].split('.')
            for i in range(len(tokens)):
                domain = '.'.join(tokens[i:])
                counts[domain] = counts.get(domain, 0) + count
        result = []
        for domain, count in counts.items():
            result.append('%d %s' % (count, domain))
        return result

