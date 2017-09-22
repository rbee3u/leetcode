def howmany(p):
    ans = 0
    for a in range(1, p // 3):
        for b in range(a + 1, p // 2):
            c = p - a - b
            if c <= b:
                break
            if a*a + b*b == c*c:
                ans = ans + 1
            if a*a + b*b > c*c:
                break
    return ans

max_n = 0; max_p = 0
for p in range(2, 1001):
    n = howmany(p)
    if n > max_n:
        max_n = n
        max_p = p

print(max_p)
