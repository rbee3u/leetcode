from sympy import sieve
from sympy import isprime

M = 1000000
ans_k, ans_s = 0, 0
i = 1
while True:
    k, s = 1, sieve[i]
    if s >= M: break
    while s < M:
        if isprime(s) and k > ans_k:
            ans_k, ans_s = k, s
            print('%d = ' % s, end='')
            expr = [str(sieve[i+x]) for x in range(k)]
            print(' + '.join(expr))
        s = s + sieve[i + k]
        k = k + 1
    i = i + 1

print('ans_k: %d, ans_s:%d' % (ans_k, ans_s))

