L = open('p059_cipher.txt').readlines()
L = map(int, L[0].split(','))
ans = 0
for i, x in enumerate(L):
	y = x ^ ord('god'[i % 3])
	ans += y
print(ans)

