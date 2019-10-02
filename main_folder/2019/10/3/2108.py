from sys import stdin
N = int(stdin.readline())
seq = [int(stdin.readline()) for i in range(N)]
lst=[0]*8001
max_list=[]
avg = sum(seq)/N

for n in seq:
    lst[n+4000]+=1
lst_max=max(lst)

for i in range(len(lst)):
    if lst[i]==lst_max:
        max_list.append(i-4000)

print(int(round(avg, 0)))
print(sorted(seq)[N//2])
if len(max_list)==1:
    print(max_list[0])
else:
    print(max_list[1])
print(max(seq) - min(seq))
