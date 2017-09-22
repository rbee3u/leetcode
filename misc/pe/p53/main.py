ans = 0
for n in range(1, 101):
	c = 1
	for r in range(1, n):
		c = c * (n+1-r) // r
		if c > 1000000:
			ans = ans + 1

print(ans)

