'''
use sets intersect method
1) set add all (string)(itretavely)'s
2) base cases :
=>	if n ==1 :
		retrurn 1

>>> a = {1,2,3}
>>> b = {1,2,3,4}
>>> a>b
False
>>> b>a
True
>>>
'''


if __name__ == '__main__':
	ss = set()
	ans = 0
	n = int(input())
	if n == 1:
		print(1)
	else:
		for _ in range(n):
			if ans >= 26:
				break
			s = set(input())
			if not len(ss):
				ss|=s
				ans += 1
			elif ss> s:
				pass
			elif s >= ss:
				ans = 1
			else:
				ss|=s
				ans += 1
		print(ss ,ans)

