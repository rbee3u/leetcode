from itertools import permutations
from sympy import isprime

ans = 0
for x in permutations('1234567'):
	y = int(''.join(list(x)))
	if isprime(y) and y > ans:
		ans = y

print(ans)

