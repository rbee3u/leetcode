d = {}
m = {}
for n in range(1000000):
	x = n ** 3
	k = ''.join(sorted(str(x)))
	d[k] = d.get(k, 0) + 1
	if d[k] == 1:
		m[k] = x
	if d[k] >= 5:
		print(m[k])
		break

