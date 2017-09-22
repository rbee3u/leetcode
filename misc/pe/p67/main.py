a = [None] * 100
f = open('p067_triangle.txt').readlines()
for i in range(100):
	a[i] = list(map(int, f[i].split()))

n = len(a)

b = [None] * n
for i in range(n):
	b[i] = [-1] * (i+1)

def dfs(i, j):
	global a, n, b
	if i >= n or j > i:
		return 0
	if b[i][j] >= 0:
		return b[i][j]
	b[i][j] = a[i][j] + max(dfs(i+1, j), dfs(i+1, j+1))
	return b[i][j]


print(dfs(0, 0))

