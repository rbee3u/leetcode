def is_leap(y):
    return (y % 400 == 0) or (y % 4 == 0) and (y % 100 != 0)

def nextday(ymd):
    (y, m, d) = ymd
    if m == 2:
        if is_leap(y) and d == 29:
            return (y, 3, 1)
        if not is_leap(y) and d == 28:
            return (y, 3, 1)
    if m in [4, 6, 9, 11] and d == 30:
        return (y, m + 1, 1)
    if m == 12 and d == 31:
        return (y + 1, 1, 1)
    if d == 31:
        return (y, m + 1, 1)
    return (y, m, d + 1)

start = (1900, 1, 1)
total = 1
count = 0
while start < (2000, 12, 31):
    if total % 7 == 0 and start[2] == 1 and start[0] > 1900:
        count = count + 1
    start = nextday(start)
    total = total + 1

print(count)

