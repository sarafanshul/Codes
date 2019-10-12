a=int(input())
b=int(input())
c=int(input())
d=str(a*b*c)
count=[0,0,0,0,0,0,0,0,0,0]
for i in range(len(d)):
    if int(d[i])==0:
        count[0]+=1
    elif int(d[i])==1:
        count[1]+=1
    elif int(d[i])==2:
        count[2]+=1
    elif int(d[i])==3:
        count[3]+=1
    elif int(d[i])==4:
        count[4]+=1
    elif int(d[i])==5:
        count[5]+=1
    elif int(d[i])==6:
        count[6]+=1
    elif int(d[i])==7:
        count[7]+=1
    elif int(d[i])==8:
        count[8]+=1
    elif int(d[i])==9:
        count[9]+=1
for j in range(len(count)):
    print(count[j])
