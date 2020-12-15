from itertools import permutations as _per

num = {'Anka':0, 'Chapay':1, 'Cleo':2, 'Troll':3, 'Dracul':4, 'Snowy':5, 'Hexadecimal':6}
h = {'Anka', 'Chapay', 'Cleo', 'Troll', 'Dracul', 'Snowy', 'Hexadecimal'}
l = []

for i in range(1 ,7):
	*tmp ,= _per(num.values() ,i)
	for x in tmp:
		st = sorted(x);	
		if(st in l) : pass
		else: l.append(st)

print(len(l))
pairs = []

n = int(input()):
likes = [[0]*8 for _ in range(8)]
for i in range(n):
	a ,b ,c = input().split()
	likes[num[a]][num[b]] = 1;