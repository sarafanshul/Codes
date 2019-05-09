from sys import stdin

for line in stdin:
    l = line[:-1]
    res = ""
    if not len(l):
        res = ""
    elif l[0].isdigit():
        iter = 0
        while iter < len(l):
            if int(l[iter : iter + 2][::-1]) > 22:
                c = l[iter : iter + 2][::-1]
                iter += 2
            else:
                c = l[iter : iter + 3][::-1]
                iter += 3
            
            res += chr(int(c))
    else:
        for c in l:
            res += str(ord(c))
    print(res[::-1])
