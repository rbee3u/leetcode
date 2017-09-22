line = open('p022_names.txt').readlines()[0]
array = sorted(map(lambda x: x.strip('"'), line.split(',')))
# print(array[937])
n = len(array)
ans = 0
for i in range(n):
    worth = sum(map(lambda x: ord(x)-ord('A')+1, list(array[i])))
    score = worth * (i + 1)
    ans = ans + score

print(ans)

