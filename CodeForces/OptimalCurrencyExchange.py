n = int(input())
d = int(input())
e = int(input())

m = n

if n >= d:
	n = n%(d)
if n >= e*5:
	n = n%(e*5)

if m >= e*5:
	m = m%(e*5)
if m >= d:
	m = m%(d)
	
print(min(n , m))

# ans = 1e11+11
# e *= 5
# i=0
# while (i*d) <= n:
# 	ans = min(ans , n-i*d-(n-i*d)//e*e)
# 	i += 1

# print(ans)