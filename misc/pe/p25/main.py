a = 1
b = 0
i = 1
while len(str(a)) < 1000:
	a, b = a + b, a
	i = i + 1

print(i)