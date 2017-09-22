line = open('p042_words.txt').readlines()[0]
words = list(map(lambda x: x.strip('"'), line.split(',')))


def value(w):
	return sum([ord(x)-ord('A')+1 for x in w])

def is_triangle(n):
	i = 1
	while True:
		x = i * (i + 1) // 2
		if x == n:
			return True
		if x > n:
			break
		i = i + 1
	return False

ans = 0
for w in words:
	if is_triangle(value(w)):
		ans = ans + 1

print(ans)

