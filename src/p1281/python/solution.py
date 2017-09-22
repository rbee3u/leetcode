class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product, total = 1, 0
        while n > 0:
            product *= n % 10
            total += n % 10
            n //= 10
        return product - total
