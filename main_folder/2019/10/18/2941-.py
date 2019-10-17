a=input()
count=0
for i in range(len(a)):
    if a[i]=='c':
        if i+1<len(a):
            if a[i+1]=='=' or a[+1]=='-':
                i=i+2
                count+=1

    if a[i]=='l':
        if i+1<len(a):
            if a[i+1]=='j':
                i=i+2
                count+=1

    if a[i]=='n':
        if i+1<len(a):
            if a[i+1]=='j':
                i=i+2
                count+=1


    if a[i]=='s':
        if i+1<len(a):
            if a[i+1]=='=':
                i=i+2
                count+=1

    if a[i]=='z':
        if i+1<len(a):
            if a[i+1]=='=':
                count+=1

    else:
        count+=1

'미해결'

print(count)

