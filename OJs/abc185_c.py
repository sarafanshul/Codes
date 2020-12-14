import math
def nCr(n,r):
    f = math.factorial
    return f(n) // f(r) // f(n-r)
a = int(input())
print(nCr(a-1,11))