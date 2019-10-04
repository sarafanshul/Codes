from math import *
N,K = map(int,input().split())
print((factorial(N+K-1)//(factorial(N)*factorial(K-1)))%1000000000)
