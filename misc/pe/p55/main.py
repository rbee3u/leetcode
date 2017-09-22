def lychrel(x):
	for i in range(60):
		y = int(str(x)[::-1])
		if x == y and i > 0:
			return False
		x = x + y
	return True

ans = 0
for x in range(0, 10000):
	if lychrel(x):
		ans += 1

print(ans)

