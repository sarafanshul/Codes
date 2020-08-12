n,m=map(int,input().split())
list1=[input() for _ in range(n)]
countlist=[]
list2=[]
listw="WBWBWBWB"
listb="BWBWBWBW"
for i in range(m-7):
    for j in range(n-7):
        for k in range(8):
            list2.append(list1[j+k][i:i+8])
        count1=0
        count2=0
        for q in range(0,8,2):
            for w in range(8):
                if list2[q][w] != listw[w]:
                    count1+=1
        for e in range(1,8,2):
            for r in range(8):
                if list2[e][r] != listb[r]:
                    count1+=1

        for t in range(0,8,2):
            for y in range(8):
                if list2[t][y] != listb[y]:
                    count2+=1
        for u in range(1,8,2):
            for l in range(8):
                if list2[u][l] != listw[l]:
                    count2+=1
        countlist.append(count1)
        countlist.append(count2)
        list2.clear()
print(min(countlist))
