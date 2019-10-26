def t(n):
    return n**3
for a in range(1,101):
    for b in range(2,98):
        if b<a:
            for c in range(b+1,99):
                if t(a)>t(b)+t(c):
                    for d in range(c+1,100):
                        if t(a)>=t(b)+t(c)+t(d):
                            if t(a)==t(b)+t(c)+t(d):
                                print("Cube = %d, Triple = (%d,%d,%d)"%(a,b,c,d))
                        else:
                            break
                else:
                    break
        else:
            break
