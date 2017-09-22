def is_palindromic(n):
    s = str(n)
    return s == s[::-1]

ans = 0
for x in range(100, 1000):
    for y in range(100, 1000):
        z = x * y
        if is_palindromic(z):
            ans = max(ans, z)

print(ans)

