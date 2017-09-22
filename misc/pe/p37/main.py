from sympy import isprime

def is_truncatable(x):
    y = x
    while y > 0:
        if not isprime(y):
            return False
        y = y // 10
    m = 10
    while m <= x:
        m *= 10
    m = m // 10
    z = x
    while z > 0:
        if not isprime(z):
            return False
        z = z % m
        m = m // 10
    return True

ans = 0
for x in range(11, 1000000):
    if is_truncatable(x):
        print(x)
        ans += x

print(ans)
