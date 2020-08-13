n=int(input())
div = 2
while div*div<=n:
    while n%div==0:
        print (div)
        n //= div
    div += 1
if n != 1:
    print(n)
