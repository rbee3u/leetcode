def sigma(n, d):
    q = n // d
    return q * (q + 1) // 2 * d

n = 1000 - 1
a = sigma(n, 3)
b = sigma(n, 5)
c = sigma(n, 15)
print(a + b - c)

