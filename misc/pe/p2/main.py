a = 1
b = 1
c = 0
while a <= 4000000:
	if a % 2 == 0:
		c += a
	a, b = a + b, a

print(c)

