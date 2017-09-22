matrix, dp, n = [], [], 80
for line in open('p081_matrix.txt').readlines():
	matrix.append(list(map(int, line.split(','))))
	dp.append([0] * n)

for i in range(n):
	for j in range(n):
		if i == 0 and j == 0:
			dp[i][j] = matrix[i][j]
		elif i == 0:
			dp[i][j] = dp[i][j-1] + matrix[i][j]
		elif j == 0:
			dp[i][j] = dp[i-1][j] + matrix[i][j]
		else:
			dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + matrix[i][j]

print(dp[n-1][n-1])


