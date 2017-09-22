def equal(x, y):
    return abs(x-y) < 1e-6

def curious(a, b, c, d):
    if 0 in [a, b, c, d]:
        return False
    if a == b or c == d:
        return False
    e = 10 * a + b
    f = 10 * c + d
    if e >= f:
        return False
    v = e / f
    if b == c and equal(v, a / d):
        return True
    # if equal(v, b / c):
    #     return True
    return False

for a in range(1, 10):
    for b in range(1, 10):
        for c in range(1, 10):
            for d in range(1, 10):
                if curious(a, b, c, d):
                    print('%d%d/%d%d' % (a, b, c, d))
