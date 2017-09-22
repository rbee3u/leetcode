m = 10 ** 10
ans = 0
for x in range(1, 1001):
    ans = (ans + pow(x, x, m)) % m

print(ans)


