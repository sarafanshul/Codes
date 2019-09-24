from sys import stdin

fact = [1]
for x in range(1, 31):
    fact.append(x * fact[-1])

def perm_multiset(d):
    n = fact[sum(d.values())]
    for key, val in d.items():
        n /= fact[val]
    return n;    

for l in (x.rstrip() for x in stdin if x != "#\n"):
    freq = {}
    for c in l:
        if not c in freq:
            freq[c] = 1
        else:
            freq[c] += 1

    res = 0
    for c in l:        
        for key, val in freq.items():
            if key < c and val > 0:
                e = dict(freq)
                e[key] -= 1
                res += perm_multiset(e)
        freq[c] -= 1

    print("%10d" % (int(res) + 1))
