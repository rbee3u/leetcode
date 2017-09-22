from math import sqrt

def tri(n):
    return n * (n + 1) // 2

def penta(n):
    return n * (3 * n - 1) // 2

def is_penta(x):
    n = round((1 + sqrt(1 + 24 *x)) / 6)
    return penta(n) == x

def hexa(n):
    return n * (2 * n - 1)

def is_hexa(x):
    n = round((1 + sqrt(1 + 8 * x)) / 4)
    return hexa(n) == x

i = 1
c = 0
while True:
    x = tri(i)
    if is_penta(x) and is_hexa(x):
        c += 1
        print(x)
        if c >= 3:
            break
    i = i + 1

