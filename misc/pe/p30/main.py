def is_daffodil(n):
	return sum(map(lambda x: int(x)**5, list(str(n)))) == n

ans = 0
for x in range(2, 999999):
	if is_daffodil(x):
		ans += x
print(ans)
