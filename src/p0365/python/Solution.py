class Solution(object):
    def gcd(self, n, m):
        if m == 0:
            return n
        else:
            return self.gcd(m, n%m)

    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if x < 0 or y < 0 or z < 0:
            return False
        
        if x < y:
            x, y = y, x
        
        if x == 0:
            return z == 0
        
        return (z%self.gcd(x, y) == 0) and (z <= x+y)

