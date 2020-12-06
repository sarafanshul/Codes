for ces in range(int(input())):
    N, M = map(int, input().split())

    edg = [[] for i in range(N)]
    ans = [0 for i in range(N)]
    ansrt = 1
    
    for i in range(M):
        a, b = map(int, input().split())
        edg[a-1].append(b-1)
        edg[b-1].append(a-1)

    while True:
        if not M % 2:
            for i in range(N):
                if ans[i] == 0: ans[i] = ansrt

        else:
            oddan = -1
            for i in range(N):
                if len(edg[i]) % 2:
                    oddan = i
                    break

            if oddan != -1:
                for i in range(N):
                    if ans[i] == 0:
                        if oddan == i:
                            ans[i] = ansrt + 1
                        else:
                            ans[i] = ansrt
            else:
                mx = 0
                idx = 0
                for i in range(N):
                    if len(edg[i]) > mx:
                        idx = i
                        mx = len(edg[i])

                ans[idx] = ansrt
                ansrt += 1
                M -= len(edg[idx])

                for i in range(len(edg[idx])):
                    try: edg[edg[idx][i]].remove(idx)
                    except: pass

                edg[idx].clear()

        flag = 1
        for i in range(N):
            if ans[i] == 0:
                flag = 0
                break

        if flag:break
        else:pass

    print(max(ans))
    print(*ans)
