a=input()
a=a.upper()
b={0:'A',1:'B',2:'C', 3:'D',4:'E',5:'F',6:'G',7:'H',8:'I',9:'J',10:'K',11:'L',12:'M',13:'N',14:'O',15:'P',16:'Q',17:'R',18:'S',19:'T',20:'U',21:'V',22:'W',23:'X',24:'Y',25:'Z'}
c=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
count=0
for i in range(len(a)):
    for j in range(len(b)):
        if a[i]==b[j]:
            c[j]+=1
d=max(c)
for k in range(len(c)):
    if c[k]==d:
        count+=1
if count>=2:
    print('?')
else:
    print(b[c.index(d)])
