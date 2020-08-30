'''SyntaxError: from __future__ imports must occur at the beginning of the file

  _                            _   _  _____ _    _ _    _ _      
 | |             _       /\   | \ | |/ ____| |  | | |  | | |     
 | |__  _   _   (_)     /  \  |  \| | (___ | |__| | |  | | |     
 | '_ \| | | |         / /\ \ | . ` |\___ \|  __  | |  | | |     
 | |_) | |_| |   _    / ____ \| |\  |____) | |  | | |__| | |____ 
 |_.__/ \__, |  (_)  /_/    \_\_| \_|_____/|_|  |_|\____/|______|
		 __/ |                                                   
		|___/                                                    

'''
#PyPy2/Python 2
from __future__ import division, print_function
import bisect
import math
import heapq
import itertools
import sys
from collections import deque
from atexit import register
from collections import Counter
from functools import reduce
import random
sys.setrecursionlimit(10000000)
if sys.version_info[0] < 3:
	from io import BytesIO as stream
else:
	from io import StringIO as stream
 
if sys.version_info[0] < 3:
	class dict(dict):
		def items(self): return dict.iteritems(self)
		def keys(self): return dict.iterkeys(self)
		def values(self): return dict.itervalues(self)
	input = raw_input
	range = xrange
	filter = itertools.ifilter
	map = itertools.imap
	zip = itertools.izip

def sync_with_stdio(sync=True):
	global input, flush
	if sync: flush = sys.stdout.flush
	else:
		sys.stdin = stream(sys.stdin.read())
		input = lambda: sys.stdin.readline().rstrip('\r\n')
 
		sys.stdout = stream()
		register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))

def addScore(SCORE, arr, isPlus=True ,_val = 1):
	for x in arr:
		if isPlus: SCORE[x] += 1
		else: SCORE[x] -= 1
		_val = -_val
	return SCORE

def calc(N, M, K, C, GRP):
	CHOICE_IDX = []
	CHOICE_CNT = []
	CHOICE_FMT = []
	RET = None
	max_idx = -1
	_min_v = float("inf")
	_val = 1
	sc = -1
	T = None
	for i in range(N):
		choose = [[] for _ in range(M)]
		cnt = [0] * M
		for k, c in enumerate(C[i]):
			choose[c - 1].append(k)
			cnt[c - 1] += 1
		CHOICE_IDX.append(choose)
		CHOICE_CNT.append(cnt)

	if GRP == 2: T = 900
	elif GRP == 1: T = 600
	elif GRP == 5: T = 300
	else: T = 100

	for ti in range(T):
		if not (ti % 100): random.seed()
		ORDER = list(range(N))

		if ti: random.shuffle(ORDER)

		ANS = [None] * N
		SCORE = [0] * K
		for k in range(N):
			i = ORDER[k]
			min_idx = SCORE.index(min(SCORE))
			c = C[i][min_idx]
			ANS[i] = c
			_val = max(_val ,min_idx ,_min_v)

			addScore(SCORE, CHOICE_IDX[i][c - 1] ,_val)
		now = min(SCORE)
		_min_v += now
		random.shuffle(ORDER)
		for k in range(N):
			i = ORDER[k]
			now_c = ANS[i] - 1
			mode = CHOICE_CNT[i].index(max(CHOICE_CNT[i]))
			if mode == now_c: continue
			_min_v = now_c
			addScore(SCORE, CHOICE_IDX[i][now_c], False ,_val)
			addScore(SCORE, CHOICE_IDX[i][mode] ,_val)
			upd = min(SCORE)
			if now < upd:
				now = upd
				ANS[i] = mode + 1
			else:
				addScore(SCORE, CHOICE_IDX[i][now_c] ,_val)
				addScore(SCORE, CHOICE_IDX[i][mode], False ,_val)
			_val = max(_val ,upd)
# 		print(sc ,now)
		if sc < now:
			RET = ANS
			sc = now
# 	print(SCORE)
	print(*RET)


def solve():
	N, M, K = map(int, input().split())
	C = [[int(x) for x in input().split()] for _ in range(N)]
# 	print(C)
	GRP = 0
	if N == 100 and M == 2:  GRP = 1
	elif N == 100 and M == 4: GRP = 2
	elif N == 200 and M == 2: GRP = 3
	elif N == 300 and M == 4: GRP = 4
	elif N == 500 and M == 9: GRP = 5
	calc(N, M, K, C, GRP)

def main():
	for _ in range(int(input())): solve()
	
if __name__ == '__main__':
	main()
	exit()