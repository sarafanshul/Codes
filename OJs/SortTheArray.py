'''
	Note that if from a given sorted array,
	if reverse a segment, then the remaining array 
	will be arranged in following way. 
	First increasing sequence, then decreasing, 
	then again increasing.

	You can find the first position where the 
	sequences start decreasing from the beginning. 
	Call it L.

	You can find the first position where the 
	sequences start increasing from the end. Call it R.

	Now we just need to reverse the 
	segment between a[L] to a[R].

	Here is outline of my solution 
	which is easy to implement. First I map 
	larger numbers to numbers strictly 
	in the range 1, n.
	As all the numbers are distinct, 
	no two numbers in the mapping will be equal too.

	Let us define L to be smallest 
	index such that A[i]! = i.
	Let us also define R to be largest 
	index such that A[i]! = i.

	Note that if there is no such L 
	and R, it means that array is 
	sorted already. So answer will 
	be "yes", we can simply reverse 
	any of the 1 length consecutive segment.

	Otherwise we will simply 
	reverse the array from [L, R]. 
	After the reversal, we will check 
	whether the array is sorted or not.

	Complexity: O(nlogn)
'''

n = int(input())
*a , = map(int , input().split())
b = sorted(a)
mp = dict()

for i in range(n):
	mp[b[i]] = i

for i in range(n):
	a[i] = mp[a[i]]

L = -1
for i in range(n):
	if a[i] != i:
		L = i
		break

R = -1
for i in range(n-1 , -1 , -1):
	if a[i] != i:
		R = i
		break

if L == -1 and R == -1:
	print('yes')
	print('1 1')

else:
	rev = a[L:R+1]
	rev = rev[::-1]
	a = a[:L] + rev + a[R+1:]
	ok = True
	for i in range(n):
		if a[i] != i:
			ok = False
	if ok:
		print('yes')
		print(L+1 , R+1)
	else:
		print('no')
