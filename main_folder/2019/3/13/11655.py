a=list(input())
for i in range(len(a)):
    if ord(a[i]) >=65 and ord(a[i])<=90:
        if ord(a[i])+13 >90:
            a[i]=chr(ord(a[i])-13)
        else:
            a[i]=chr(ord(a[i])+13)

    elif ord(a[i]) >=97 and ord(a[i])<=122:
        if ord(a[i])+13 >122:
            a[i]=chr(ord(a[i])-13)
        else:
            a[i]=chr(ord(a[i])+13)
for i in range(len(a)):
    print(a[i],end="")
