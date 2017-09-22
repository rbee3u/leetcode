d = [0]
for x in range(1, 200000):
    d.extend(list(str(x)))

ans = 1
i = 1
while i <= 1000000:
    ans *= int(d[i])
    i = i * 10

print(ans)
