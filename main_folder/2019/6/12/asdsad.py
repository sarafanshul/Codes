a = int(input())
list = []
for i in range(0,a):
    b = list(map(int,input().split()))
    list.append(b)

for i in range(0,a):
    sum = 0
    avg = 0
    avgcnt = 0
    for j in range(1,list[i][0] + 1):
        sum += list[i][j]
    avg = sum / float(list[i][0])
    for j in range(1,list[i][0] + 1):
        if float(list[i][j]) > avg :
            avgcnt += 1
    ans = avgcnt / float(list[i][0]) * 100
    print("%0.3f"%round(ans,3),end = "")
    print("%")
