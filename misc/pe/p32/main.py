def pandigital(a, b):
    c = a * b
    l = str(a) + str(b) + str(c)
    return ''.join(sorted(l)) == '123456789'



s = set()
for a in range(9999):
    for b in range(a):
        c = a * b
        if pandigital(a, b):
            s.add(c)

print(sum(s))


