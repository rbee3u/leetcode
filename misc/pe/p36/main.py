def is_palindrome(x):
	d = str(x)
	b = bin(x)[2:]
	return d == d[::-1] and b == b[::-1]

ans = 0
for x in range(1000000):
	if is_palindrome(x):
		ans += x
		print(x)

print(ans)
