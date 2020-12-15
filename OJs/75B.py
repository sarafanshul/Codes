from collections import defaultdict
import functools

def customsort(a ,b):
    if(a[0] == b[0]): return a[1] > b[1]
    else: return a[0] > b[0]

a = input()
n = int(input())
names = defaultdict(lambda : 0)

for i in range(n):
    *l ,= map(str ,input().split())
    pt = 0
    if(l[1] == "posted"):pt = 15
    elif(l[1] == "commented"): pt = 10
    else: pt = 5
    if not (l[0] == a or l[-2][:-2] == a) :pt = 0
    names[l[0]] += pt
    names[l[-2][:-2]] += pt
    # print(pt)

lst = [[100000-names[k] ,k] for k in names.keys() if(k != a)]
# for i ,j in lst:
#     print(j ,(i+1)*1000000 - sum(ord(b) for b in j))


lst.sort()
# # lst.reverse()
# print(lst)
for i ,j in lst:
    print(j)

