from sympy.ntheory import primefactors

a = 2
while True:
    if len(primefactors(a)) != 4:
        a = a + 1
        continue
    if len(primefactors(a+1)) != 4:
        a = a + 2
        continue
    if len(primefactors(a+2)) != 4:
        a = a + 3
        continue
    if len(primefactors(a+3)) != 4:
        a = a + 4
        continue
    print(a)
    break


