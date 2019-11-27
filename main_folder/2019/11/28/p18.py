a=[0]*26
n=input()
n=n.upper()
for i in range(len(n)):
    a[ord(n[i])-65]+=1
max=max(a)
count=0
for i in range(len(a)):
    if a[i]==max:
        count+=1
if count>1:
    print("?")
else:
    print(chr(a.index(max)+65))
