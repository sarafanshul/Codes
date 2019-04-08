x=int(input())
ballcup=1
for i in range(x):
    a,b=map(int,input().split())
    if a==ballcup:
        ballcup=b
    elif b==ballcup:
        ballcup=a
print(ballcup)

