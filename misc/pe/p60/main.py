from sympy import sieve

s = set()
for i in range(10 ** 8):
	s.add(sieve[i])

def is_pair(x, y):
	global s
	p = int(str(x) + str(y))
	q = int(str(y) + str(x))
	return (p in s) and (q in s)

for a in range(1, 5000):
	pa = sieve[a]
	for b in range(a+1, 6000):
		pb = sieve[b]
		if not is_pair(pa, pb): continue
		for c in range(b+1, 7000):
			pc = sieve[c]
			if not is_pair(pa, pc): continue
			if not is_pair(pb, pc): continue
			for d in range(c+1, 8000):
				pd = sieve[d]
				if not is_pair(pa, pd): continue
				if not is_pair(pb, pd): continue
				if not is_pair(pc, pd): continue
				for e in range(d+1, 9000):
					pe = sieve[e]
					if not is_pair(pa, pe): continue
					if not is_pair(pb, pe): continue
					if not is_pair(pc, pe): continue
					if not is_pair(pd, pe): continue
					print(sum([pa, pb, pc, pd, pe]))

