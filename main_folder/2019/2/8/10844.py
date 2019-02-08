n = int(input())
d = [[0,1,1,1,1,1,1,1,1,1]]
for x in range(n-1):
  d += [[0 for x in range(0,10)]]
for x in range(1,n):
  for y in range(10):
    if y == 0:
      d[x][y] = d[x-1][y+1]
    elif y == 9:
      d[x][y] = d[x-1][y-1]
    else:
      d[x][y] = d[x-1][y+1] + d[x-1][y-1]
print(sum(d[n-1])%1000000000)
