from itertools import permutations

ans = 0
for x in permutations((0,1,2,3,4,5,6,7,8,9)):
    (d1,d2,d3,d4,d5,d6,d7,d8,d9,d10) = x
    if (d2*100+d3*10+d4) % 2 == 0 and \
       (d3*100+d4*10+d5) % 3 == 0 and \
       (d4*100+d5*10+d6) % 5 == 0 and \
       (d5*100+d6*10+d7) % 7 == 0 and \
       (d6*100+d7*10+d8) % 11 == 0 and \
       (d7*100+d8*10+d9) % 13 == 0 and \
       (d8*100+d9*10+d10) % 17 == 0:
       y = int(''.join(map(str, list(x))))
       print(y)
       ans += y

print(ans)

