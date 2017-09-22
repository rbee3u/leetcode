n = 600851475143
d = 2
p = 1
while d * d <= n:
	if n % d == 0:
		p = d
		while n % d == 0:
			n = n // d
	d = d + 1

if n > 1:
	print(n)
else:
	print(p)

