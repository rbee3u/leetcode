MAXN = 10 ** 7
dp = [None] * MAXN
dp[0] = 0
dp[1] = 1
dp[89] = 89

def next_x(x):
	r = 0
	while x > 0:
		b = x % 10
		x = x // 10
		r += b * b
	return r

def arrive(n):
	x = n
	while x != 1 and x != 89:
		if x < MAXN and dp[x] != None:
			break
		x = next_x(x)
	y = n
	while y != x:
		dp[y] = dp[x]
		y = next_x(y)
	return dp[x]

ans = 0
for n in range(1, MAXN):
	if arrive(n) == 89:
		ans += 1

print(ans)
