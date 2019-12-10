N,M=map(int,input().split())
list1=[i for i in range(1,N+1)]
list2=list(map(int,input().split()))
count=0
for i in range(M):
    if list1[0] == list2[i]:
        del list1[0]
        continue

    else:
        while 1:
            if list1.index(list2[i]) <= len(list1)//2:
                list1.append(list1[0])
                del list1[0]
                count+=1
                if list1[0] == list2[i]:
                    del list1[0]
                    break
            else:
                list1.insert(0,list1[len(list1)-1])
                del list1[len(list1)-1]
                count+=1
                if list1[0] == list2[i]:
                    del list1[0]
                    break
print(count)
