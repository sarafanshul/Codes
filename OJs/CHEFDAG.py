# Maximum Bipartite Matching

def _bpm(n:int ,bpGraph:list ,u:int ,seen:list ,matchR:list) -> bool:
	for v in range(n):
		if bpGraph[u][v] and not seen[v]:
			seen[v] = True
			if matchR[v] < 0 or _bpm(n ,bpGraph ,matchR[v] ,seen ,matchR):
				matchR[v] = u
				return True
	return False

def maxBPM(n:int ,bpGraph:list) -> None:
	matchR = [-1 for i in range(n)]
	_res = 0
	for u in range(n):
		seen = [0 for i in range(n)]
		if _bpm(n ,bpGraph ,u ,seen ,matchR): _res += 1
	print(n - _res)
	for i in range(n): print(f'{matchR[i]+1} ',end = " \n"*(i==n-1))

def calc() -> None:
	n ,k = map(int , input().split())
	a = [[*map(int , input().split())] for i in range(k)]
	num = [[0 for i in range(k)] for _ in range(n+1)]
	_res = n
	bpGraph = [[False for i in range(n+1)] for j in range(n+1)]
	for i in range(k):
		for j in range(n):
			num[a[i][j]][i] = j

	for i in range(1 ,n+1):
		for j in range(1 ,n+1):
			ck = 1
			for l in range(k):
				if num[i][l] <= num[j][l]: ck = 0
			if ck : bpGraph[i-1][j-1] = True

	maxBPM(n ,bpGraph)

def main() -> None:
	for i in range(int(input())):
		calc()

if __name__ == '__main__':
	main()

