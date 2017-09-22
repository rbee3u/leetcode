from sympy import isprime

def comp(x, m, k):
	y = 0
	e = 1
	while m > 0 or x > 0:
		if m % 2 == 1:
			y += k * e
		else:
			y += (x % 10) * e
			x = x // 10
		m //= 2
		e *= 10
	return y

def sati(x, m):
	out = 0
	for k in range(0, 10):
		if not isprime(comp(x, m, k)):
			out = out + 1
			if out > 2:
				return False
	return True

for x in range(1, 1000):
	for m in range(1, 256):
		if sati(x, m):
			for k in range(0, 10):
				if isprime(comp(x, m, k)):
					print(comp(x, m, k))
