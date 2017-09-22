from sympy.ntheory import totient

ans, div = 0, 0
for n in range(2, 1000001):
	tmp = n / totient(n)
	if div < tmp:
		ans, div = n, tmp

print(ans)

