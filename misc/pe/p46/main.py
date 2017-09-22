from sympy import isprime

def satisfied(z):
    r = 1
    while True:
        x = z - 2*r*r
        if x < 2:
            break
        if isprime(x):
            return True
        r = r + 1
    return False


z = 7
while True:
    z = z + 2
    if isprime(z):
        continue
    if not satisfied(z):
        print(z)
        break

