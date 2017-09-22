from sympy import isprime

def equal(x, y):
	x = ''.join(sorted(str(x)))
	y = ''.join(sorted(str(y)))
	return x == y

for a in range(1000, 10000):
	if not isprime(a):
		continue
	for d in range(1, 10000):
		b = a + d
		if b > 9999:
			break
		if not isprime(b):
			continue
		if not equal(a, b):
			continue
		c = b + d
		if c > 9999:
			break
		if not isprime(c):
			continue
		if not equal(b, c):
			continue
		print(a, b, c)



