from math import gcd
 
n, m, z = map(int, input().split())
g = gcd(n, m)
lcm = n * m // g
print(z // lcm)