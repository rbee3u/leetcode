from sympy import isprime

x, num, den = 3, 3, 5
while num * 10 >= den:
	x += 2
	y = x * x
	if isprime(y):
		num += 1
	y = y - (x - 1)
	if isprime(y):
		num += 1
	y = y - (x - 1)
	if isprime(y):
		num += 1
	y = y - (x - 1)
	if isprime(y):
		num += 1
	den += 4

print(x)

