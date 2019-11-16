from sys import stdin

L = []
for elem in tuple(stdin):
    L += elem.split()
    if L[-1] != '-999999':
        continue
    L = list(map(int, L))
    
    res = -999999
    curr = curr_wo_fst = 1
    flag = False

    for x in L[:-1]:
        if x == 0:
            flag = False
            curr = curr_wo_fst = 1
            res = max(res, 0)
            continue

        if flag:
            curr_wo_fst *= x
            res = max(res, curr_wo_fst)

        curr *= x
        res = max(res, curr)

        if not flag and x < 0:
            flag = True

    print(res)
    L = []   
