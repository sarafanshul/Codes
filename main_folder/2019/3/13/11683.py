while True:
  dimIn = input().split()
  dim = [int(elem) for elem in dimIn]
  if dim[0] == 0:
    break
  
  L = input().split()
  L = [int(elem) for elem in L]
  
  laser = dim[0] - L[0]
  
  for jj in range(1, dim[1]):
    diff = L[jj - 1] - L[jj]
    if diff > 0:
        laser += diff
  
  print(laser)
