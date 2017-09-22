fac = [1] * 10
for i in range(1, 10):
	fac[i] = i * fac[i-1]

def is_digit_fac(n):
	global fac
	return sum(map(lambda x: fac[int(x)], str(n))) == n

ans = 0
for n in range(3, 2333333):
	if is_digit_fac(n):
		ans += n

print(ans)



