ans_delta, ans_num = 1, 0

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

for d in range(8, 1000001):
	n = d * 3 // 7
	if gcd(d, n) > 1:
		continue
	delta = 3 / 7 - n / d
	if delta < ans_delta:
		ans_delta = delta
		ans_num = n

print(ans_num)

