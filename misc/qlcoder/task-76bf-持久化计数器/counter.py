mp = {}
# user_code
def get(key):
    return mp.get(key, 0)

def format(kv):
    return '%s:%d' % kv

def put(key):
    mp[key] = mp.get(key, 0) + 1
    s = '\n'.join(map(format, mp.items()))
    write_file(0, bytearray(s))

def unpack(kv):
    tp = kv.split(':')
    return (tp[0], int(tp[1]))

def init():
    s = ''.join(map(chr, filter(lambda x
        : 0 == x, read_file(0, 102400))))
    mp = dict([unpack(kv) for kv in s.split('\n') if ':' in kv])





mp = {}
# user_code
def get(key):
    return mp.get(key, 0)

def put(key):
    mp[key] = mp.get(key, 0) + 1
    s = ''
    for kv in mp.items():
        s = '%s:%d\n' % kv + s
    b_s = bytearray(s)
    write_file(0, b_s)


def init():
    s = ''.join(map(chr, filter(lambda x
        : 0 == x, read_file(0, 102400))))
    for li in s.split('\n'):
        l2 = li.split(':')
        # if len(l2)<2:
        #     continue
        mp[l2[0]] = int(l2[1])


mp = {}
# user_code
def get(key):
    return mp.get(key, 0)

def put(key):
    mp[key] = mp.get(key, 0) + 1
    s = ''.join(map(lambda x: '%s:%d\n' % x
                            , mp.items()))
    write_file(0, bytearray(s))

def init():
    s = ''.join(map(chr, read_file(0, 102400)))
    for x in s.split('\n')[:-1]:
        y = x.split(':'); mp[y[0]] = int(y[1])

