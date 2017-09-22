from math import factorial

def next_num(x):
	y = 0
	while x > 0:
		y += factorial(x % 10)
		x = x // 10
	return y

def length(x):
	s = set()
	while not x in s:
		s.add(x)
		x = next_num(x)
		if len(s) > 60:
			break
	return len(s)

ans = 0
for x in range(1, 1000000):
	if length(x) == 60:
		ans = ans + 1

print(ans)

