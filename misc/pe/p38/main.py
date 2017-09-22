def pandigital(x, n):
    chars = []
    for i in range(1, n + 1):
        chars.extend(list(str(x * i)))
    return chars

ans = 0
for n in range(2, 10):
    for x in range(1, 100000):
        p = pandigital(x, n)
        if ''.join(sorted(p)) == '123456789':
            q = int(''.join(p))
            if q > ans:
                ans = q
print(ans)

