ans = 0
for n in range(1, 50):
	for x in range(1, 10):
		l = len(str(x ** n))
		if l == n:
			ans += 1
			print('%d = %d ^ %d' % (x ** n, x, n))

print(ans)

