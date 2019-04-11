a=[]
for i in range(int(input())):
    if i==0:
        a.append(int(input()))
    elif i==1:
        aa,bb=list(map(int,input().split()))
        a.append([aa+a[i-1],bb+a[i-1]])
    else:
        temp=list(map(int,input().split()))
        a.append([])
        c = 0
        for j in temp:
            if c==0:
                a[i].append( a[i-1][0]+j )
            elif c==len(temp)-1:
                a[i].append( a[i-1][-1]+j )
            else:
                if a[i-1][c-1]+j>a[i-1][c]+j:a[i].append(a[i-1][c-1]+j)
                else:a[i].append(a[i-1][c]+j)
            c+=1
print(max(a[-1]))
