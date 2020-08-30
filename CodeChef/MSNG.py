MAX = 1e12

for _ in range(int(input())):
    N = int(input())

    valB = -1
    ansr = []
    flag = 0

    if N == 1:
        B , Y = input().split()
        if B != '-1':
            r = int(Y , int(B))
            if r <= MAX: 
                print(r)
            else: 
                print(-1)
        else:
            ass = []
            for i in range(2, 37):
                try: 
                    ass.append(int(Y , i))
                except ValueError: pass
            if min(ass) <= MAX: 
                print(min(ass))
            else: 
                print(-1)
    else:# N>1
        for x in range(N):
            B, Y = input().split()

            if B != '-1':
                temp = int(Y, int(B))
                if temp == valB or valB == -1: valB = temp
                else: valB = -MAX
            else: ansr.append(Y)

        out = [[] for i in range(len(ansr))]
        for idx in range(len(ansr)):
            for i in range(2, 37):
                try: 
                    out[idx].append(int(ansr[idx], i))
                except ValueError: pass

        te = [el for el in out if len(el)]
        out = te

        if len(out):# never empty
            ck = set(out[0])
            for el in out:
                ck = ck.intersection(el)
        else:
            ck = set()

        if valB >= 0:
            if valB in ck:
                if valB <= MAX:
                    flag = 1
                    an = valB
            if not len(ansr): #check here
                if valB <= MAX:
                    an = valB
                    flag = 1

        elif len(ck):
            an = min(ck)
            if an <= MAX:
                flag = 1

        if valB == -MAX: flag = 0  # later testcase added

        if flag: 
            print(an)
        else: 
            print(-1)
