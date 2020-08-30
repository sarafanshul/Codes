# n = int(input())
# d = dict()
# met = [-1,-1]
# for i in range(n):
# 	*lap , = map(int , input().split())
# 	if met[0] < lap[0] :
# 		met[0] = lap[0]
# 	if met[1] < lap[1] :
# 		met[1] = lap[1]
# 	d[lap[0]] = lap[1]

# # print(met)
# maxlap = sorted(d.keys() , reverse = True)
# # print(maxlap)
# # if lst:
# # 	print('Happy Alex')
# if d[maxlap[0]] == met[1] :
# 	print('Poor Alex')
# else:
# 	print('Happy Alex')
br = 0
for _ in range(int(input())):
	a , b = map(int , input().split())
	if a != b:
		br = 1 
		print('Happy Alex') 
		break

if not br:print('Poor Alex')