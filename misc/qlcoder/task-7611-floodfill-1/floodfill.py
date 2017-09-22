# -*- coding: utf-8 -*-
from PIL import Image
from collections import deque


def classify(R, G, B):
    D1 = abs(R - G)
    D2 = abs(G - B)
    D3 = abs(B - R)
    D = max(D1, D2, D3)
    S = R + G + B
    if D > 100:
        return 'green'
    elif S < 512:
        return 'black'
    else:
        return 'white'


dx = [1,-1,0,0]
dy = [0,0,-1,1]
def get_nextpos(im, currpos):
    vst = set([currpos])
    q = deque([currpos])
    while len(q) > 0:
        (currx, curry) = currpos = q.popleft()
        (R, G, B) = im.getpixel(currpos)
        if (R, G, B) != (0, 0, 0):
            return currpos
        for k in range(4):
            nextx = currx + dx[k]
            nexty = curry + dy[k]
            nextpos = (nextx, nexty)
            if (nextx < 0) or (1024 <= nextx):
                continue
            if (nexty < 0) or (1024 <= nexty):
                continue
            if nextpos in vst:
                continue
            vst.add(nextpos)
            q.append(nextpos)


def floodfill(im, currpos):
    cnt, sx, sy = 0, 0, 0
    blockrbg = None
    vst = set([currpos])
    q = deque([currpos])
    while len(q) > 0:
        (currx, curry) = currpos = q.popleft()
        cnt, sx, sy = cnt+1, sx+currx, sy+curry
        currrbg = im.getpixel(currpos)
        if blockrbg == None:
            blockrbg = currrbg
        im.putpixel(currpos, (0, 0, 0))
        for k in range(4):
            nextx = currx + dx[k]
            nexty = curry + dy[k]
            nextpos = (nextx, nexty)
            if (nextx < 0) or (1024 <= nextx):
                continue
            if (nexty < 0) or (1024 <= nexty):
                continue
            if nextpos in vst:
                continue
            nextrbg = im.getpixel(nextpos)
            if nextrbg != blockrbg:
                continue
            vst.add(nextpos)
            q.append(nextpos)
    return (cnt, sx, sy, blockrbg)


im = Image.open('145284816889895.png')
(width, height) = im.size
for x in range(width):
    for y in range(height):
        (R,G,B) = im.getpixel((x, y))
        Class = classify(R, G, B)
        if Class == 'black':
            im.putpixel((x, y), (0, 0, 0))
        elif Class == 'white':
            im.putpixel((x, y), (255, 255, 255))
        else:
            im.putpixel((x, y), (35, 182, 153))


im.save('tmp1.png')


fout = open('out.txt', 'w')
ffoo = open('foo', 'wb')

currpos = (508, 508)


idx, num = 0, 0
lst = []
while True:
    nextpos = get_nextpos(im, currpos)
    (cnt, sx, sy, blockrbg) = floodfill(im, nextpos)
    if cnt < 5:
        continue
    if blockrbg == (255, 255, 255):
        color = 1
    else:
        color = 0
    idx = idx + 1
    num = num * 2 + color
    currpos = (sx // cnt, sy // cnt)
    if idx % 8 == 0:
        fout.write('%4d %d' % (idx // 8, num))
        fout.write('\n')
        lst.append(num)
        num = 0
    if cnt > 50:
        break

ffoo.write(bytes(lst))

im.save('tmp2.png')

