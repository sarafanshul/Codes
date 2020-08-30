from __future__ import division, print_function
import bisect
import math
import heapq
import itertools
import sys
from collections import deque
from collections import defaultdict
from atexit import register
from collections import Counter
from functools import reduce
sys.setrecursionlimit(10000000)
if sys.version_info[0] < 3:
    from io import BytesIO as stream
else:
    from io import StringIO as stream
 
 
if sys.version_info[0] < 3:
    class dict(dict):
        """dict() -> new empty dictionary"""
        def items(self):
            """D.items() -> a set-like object providing a view on D's items"""
            return dict.iteritems(self)
 
        def keys(self):
            """D.keys() -> a set-like object providing a view on D's keys"""
            return dict.iterkeys(self)
 
        def values(self):
            """D.values() -> an object providing a view on D's values"""
            return dict.itervalues(self)
 
    input = raw_input
    range = xrange
 
    filter = itertools.ifilter
    map = itertools.imap
    zip = itertools.izip
 
 
def sync_with_stdio(sync=True):
    """Set whether the standard Python streams are allowed to buffer their I/O.
 
    Args:
        sync (bool, optional): The new synchronization setting.
 
    """
    global input, flush
 
    if sync:
        flush = sys.stdout.flush
    else:
        sys.stdin = stream(sys.stdin.read())
        input = lambda: sys.stdin.readline().rstrip('\r\n')
 
        sys.stdout = stream()
        register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))

# use same as python3 no change all have been considered
MOD = 1000000007


def factorial(fact):
	for i in range(2 ,100002):
		fact.append(fact[i-1]*i%MOD)
	return

def powers_Two(pow_2):
	for i in range(1 ,100002):
		pow_2.append(pow_2[i-1]*2%MOD)
	return



def main():

	fact = [1 ,1]
	factorial(fact)
	pow_2 = [1]
	powers_Two(pow_2)

	
	for _ in range(int(input())):
		
		N = int(input())
		arr=list(sorted(map(int , input().split())))
		S = min(arr[0] ,0) + max(arr[2 * N-1] ,0) # |min| +|max|
		flag = True
		dict_pair = defaultdict(lambda : False)
		i = 0
		j = 2*N - 1
		zeros_out = 0
		z = 0

		while i <= j and z < N+1 :

			if arr[i] == S and zeros_out < 2:
				zeros_out += 1
				_key = min(arr[i] ,S-arr[i])
				dict_pair[_key] += 1
				i += 1
			elif arr[j] == S and zeros_out < 2:
				zeros_out += 1
				_key = min(arr[j] , S - arr[j])
				dict_pair[_key] += 1
				j -= 1
			elif arr[i] + arr[j] == S :
				_key = min(arr[i] ,arr[j])
				dict_pair[_key] += 1
				i  ,j = i+1 ,j-1
			else:
				flag = False
				break
			z += 1

		if z != N + 1 or not flag or zeros_out != 2:
			print(0)
			continue

		pairs = N - 1
		zer_pair = min(0 ,S)

		if dict_pair[zer_pair] == 2 :
			dict_pair[zer_pair] = 0
		else:
			dict_pair[zer_pair] -= 2

		minTwo = MOD - 2
		out = fact[pairs]

		memoization = defaultdict(lambda : -1)

		for p in dict_pair.keys():
			cnt = dict_pair[p]
		
			if cnt > 1 :
				factor = memoization[cnt]
				if factor == -1:
					factor = pow(fact[cnt] ,minTwo ,MOD) # modInverse
					memoization[cnt] = factor
				out = out*factor%MOD
		
			if p != S - p:
				out = out * pow_2[cnt] % MOD

		print(out)


if __name__ == '__main__':
	main()
