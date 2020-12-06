from math import sqrt
mod = 998244353
maxn = 100001

nums = [0] # maxn
midn = 1001

belong = [0] #maxn
times = [0] #maxn
num = [0] #maxn
cnt = [0] #maxn 
ALL = 0 
vis = [0] #maxn

facts = [1] # maxn	
for i in range(1 ,maxn):facts.append((facts[i-1]*i)%mod)

comb = [[None]*midn for _ in range(midn)]
for i in range(midn):
	comb[0][i] ,comb[i][0] = 0 ,1
for i in range(1 ,midn):
	for j in range(1 ,i+1):
		comb[i][j] = (bool(comb[i-1][j])+bool(comb[i-1][j-1]))%mod


class CMD(object):
	def __init__(self ,l ,r ,_id):
		self.l = l
		self.r = r
		self.id = _id

	def __lt__(self, other):
		if belong[self.l] == belong[other.l]:
			return self.r < other.r
		return belong[self.l] < belong[other.l]

cmd = [None]
def gcd(a ,b):
	if not b : return a
	return gcd(b ,a%b)

def e_gcd(a ,b ,x ,y):
	if not b:
		x ,y = 1 ,0
		return (x ,y)
	x ,y = e_gcd(b ,a%b ,x ,y)
	l = x
	x = y
	y = l-a/b*y
	# x ,y = y ,x-a/b*y
	return (x ,y)

def choose(mod ,n ,m):
	if n<midn :return comb[n][m]
	if m == 1 or m == n-1 : return n
	if m>n : return 0
	if n ==m : return 1
	nn = facts[n]
	mm = (facts[m]*facts[n-m])%mod
	d = gcd(nn ,mm)
	nn /= d
	mm /= d
	x ,y = e_gcd(mm ,mod ,0 ,0) # here
	x = (x+mod)%mod
	return (x*nn)%mod

def _add(x):
	global ALL
	cnt[x] += 1
	num[cnt[x]] += 1
	ALL += 1
	times[ ALL] = cnt[x]
	num[cnt[x]-1] -= 1

def _del(x):
	global ALL
	cnt[x] -= 1
	num[cnt[x]] += 1
	ALL += 1
	times[ALL] = cnt[x]
	num[cnt[x] + 1] -= 1

def cal():
	global ALL
	k = 0
	vec = []
	for j in range(1 ,ALL +1):
		if not vis[times[j]] and num[times[j]]>0 :
			vec.append(times[j])
			k += 1
			times[k] = times[j]
			vis[times[j]] = True

	ALL = k
	for j in range(1 ,k+1): 
		vis[times[j]] = False
	_sum = 0
	for i in vec:
		if num[i]%2 :
			_sum ^= i
	if _sum == 0 :
		return 0
	_res = 0
	ans = 0
	tmp = 0
	for i in vec:
		if num[i] > 0:
			ans = _sum ^i
			if ans > i :
				continue
			tmp = choose(mod ,i ,i-ans)
			tmp = (tmp*num[i])%mod
			_res = (_res+tmp)%mod
	return _res

def solve(m):
	L = 1
	R = 0
	res = [0 for i in range(m+1)]
	for i in range(1 ,m+1):
		while R<cmd[i].r :
			_add(nums[R+1])
			R += 1
		while L>cmd[i].l :
			_add(nums[L-1])
			L -= 1
		while R>cmd[i].r :
			_del(nums[R])
			R -= 1
		while L<cmd[i].l:
			_del(nums[L])
			L += 1

		res[cmd[i].id] = cal()
	for i in range(1 ,m+1):
		print(res[i])

def calc():
	# global cmd
	n = int(input())
	sq = sqrt(n)
	nums[0] = 0
	belong[0] = 0
	nums.extend(list(map(int , input().split())))
	for i in range(1 ,n+1):
		# nums.append(*map(int , input().split()))
		belong.append((i-1)/sq+1)

	um = dict()

	for i in range(1 ,n+1):
		if not (nums[i] in um.keys()):
			um[nums[i]] = len(um)
		nums[i] = um[nums[i]]

	q = int(input())
	cmd[0] = CMD(0 ,0 ,0)
	for i in range(1 ,q+1):
		cmd.append(CMD(*map(int , input().split()) ,i))
		# cmd[i].id = i
	for i in range(maxn):
		times.append(0)
		num.append(0)
		cnt.append(0)
		vis.append(0)
	ALL = 0
	cmd.sort()
	# cmd = [-1] + cmd
	solve(q)


def main():
	# init()
	for i in range(int(input())):
		calc()

if __name__ == '__main__':
	main()