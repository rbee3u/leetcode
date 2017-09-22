# -*- coding: utf-8 -*-
from PIL import Image
from collections import deque


def classify(R, G, B):
    D1 = abs(R - G)
    D2 = abs(G - B)
    D3 = abs(B - R)
    D = max(D1, D2, D3)
    S = R + G + B
    if D > 60:
        return 'green'
    elif S < 512:
        return 'black'
    else:
        return 'white'


dx = [1,-1,0,0]
dy = [0,0,-1,1]
def get_nextpos(im, currpos):
    counter = 0
    vst = set([currpos])
    q = deque([currpos])
    while len(q) > 0:
        counter += 1
        if counter > 9999:
            return None
        (currx, curry) = currpos = q.popleft()
        (R, G, B) = im.getpixel(currpos)
        if (R, G, B) != (0, 0, 0):
            return currpos
        for k in range(4):
            nextx = currx + dx[k]
            nexty = curry + dy[k]
            nextpos = (nextx, nexty)
            if (nextx < 0) or (4096 <= nextx):
                continue
            if (nexty < 0) or (4096 <= nexty):
                continue
            if nextpos in vst:
                continue
            vst.add(nextpos)
            q.append(nextpos)
    return None


def floodfill(im, currpos):
    cnt, sx, sy = 0, 0, 0
    blockrbg = None
    vst = set([currpos])
    q = deque([currpos])
    t = deque([currpos])
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
            if (nextx < 0) or (4096 <= nextx):
                continue
            if (nexty < 0) or (4096 <= nexty):
                continue
            if nextpos in vst:
                continue
            nextrbg = im.getpixel(nextpos)
            if nextrbg != blockrbg:
                continue
            vst.add(nextpos)
            q.append(nextpos)
            t.append(nextpos)
            if len(t) > 40:
                t.popleft()
    lll = len(t)
    sx = sum([e[0] for e in t])
    sy = sum([e[1] for e in t])
    return (cnt, sx, sy, blockrbg, lll)


# im = Image.open('bigspiral.png')
# (width, height) = im.size
# for x in range(width):
#     for y in range(height):
#         (R,G,B) = im.getpixel((x, y))
#         Class = classify(R, G, B)
#         if Class == 'black':
#             im.putpixel((x, y), (0, 0, 0))
#         elif Class == 'white':
#             im.putpixel((x, y), (255, 255, 255))
#         else:
#             im.putpixel((x, y), (149, 114, 220))


# im.save('tmp1.png')
im = Image.open('tmp1.png')
(width, height) = im.size


ffoo = open('foo.png', 'wb')

currpos = (2053, 2043)


idx, num = 0, 0
lst = []
while True:
    nextpos = get_nextpos(im, currpos)
    if nextpos == None:
        break
    (cnt, sx, sy, blockrbg, lll) = floodfill(im, nextpos)
    if cnt < 20:
        continue
    if blockrbg == (255, 255, 255):
        color = 1
    else:
        color = 0
    currpos = (sx // lll, sy // lll)
    many = round(cnt / 41)
    # if abs(cnt / 41 - many) > 0.4:
    if cnt >= 800:
        print('(%d, %d): ' % currpos, end='')
        print('%d -> %d' % (cnt, many))
    # if currpos == ():
    #     many = 
    for i in range(many):
        idx = idx + 1
        num = num * 2 + color
        if idx % 8 == 0:
            lst.append(num)
            num = 0

ffoo.write(bytes(lst))

im.save('tmp2.png')

