
''' if x is odd -> 0
	if x is even -> x//4
	if x%4 == 0 -> x//4-1'''
n = int(input())	
if n%2 != 0: print(0)
else:
	if n%4 == 0: print(n//4 -1)
	else: print(n//4) 

#------ Brute Forcedd--------

# count = 0
# #  extreme case = (L , R)
# L = 0
# R = n//2
# if n%2 != 0: print(0)
# else:
# 	while True:
# 		L += 1
# 		R -= 1
# 		if L == R or L>R:
# 			break
# 		count += 1 
# 	print(count)
