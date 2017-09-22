from math import sqrt

def penta(n):
    return n * (3 * n - 1) // 2

def is_penta(x):
    n = round((1 + sqrt(1 + 24 *x)) / 6)
    return penta(n) == x

def find_d():
    for i in range(1, 3000):
        for j in range(1, 3000):
            d = penta(i)
            p = penta(j)
            if is_penta(d + p) and is_penta(d + p + p):
                return d
    return None

print(find_d())

