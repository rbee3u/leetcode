n = 1
for x in range(1, 101):
    n = n * x

print(sum(map(int, list(str(n)))))

