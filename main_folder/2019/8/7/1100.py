list1=[input() for i in range(8)]
count=0
for i in range(8):
    if i%2==0:
        for j in range(0,8,2):
            if list1[i][j]=="F":
                count+=1
    else:
        for z in range(1,8,2):
            if list1[i][z]=="F":
                count+=1
print(count)
