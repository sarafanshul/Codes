z = int(input())
for _ in range(z):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    x=a[0]
    y=b[0]
    z=0
    for i in range(1, n):
        x= max(y, z) + a[i]
        y= max(x, z) + b[i]
        z=max(x, y)
    print(max(x, y, z))
