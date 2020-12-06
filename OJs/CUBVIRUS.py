
def OUTPUT(array:list) -> None:
	for k_pr in array: 
		print(k_pr[0]+1 ,end = ' ')
	print(sep = '' ,end = '\n')

	
def GetCost(idx:int ,N:int ,arena:list ,
	newXIndices:list ,newYIndices:list ,
	newZindices:list ,isX:bool ,isY:bool) -> int:
	
	ans = 0 # no float
	# idx += 1
	for i in range(N):
		for j in range(N):
			# brute force every ,optimize//
			if isX and (not isY):
				if newYIndices != [] and newZindices != []:
					if arena[idx][newYIndices[i]][newZindices[j]] and (ans < (N-i)*(N-j)):
						ans = (N - i)*(N - j)
				else:
					if arena[idx][i][j] and (ans < (N - i)*(N-j)):
						ans = (N-i)*(N-j)
			elif isY:
				if newXIndices == []:
					if arena[i][idx][j] and (ans < (N-i)*(N-j)):
						ans = (N- i)*(N-j)
				else:
					if arena[newXIndices[i]][idx][j] and (ans <(N-i)*(N-j)):
						ans = (N-i)*(N-j)
			else:
				if (newXIndices != []) and (newYIndices != []):
					if arena[newXIndices[i]][newYIndices[j]][idx] and (ans <(N-i)*(N-j)):
						ans = (N-i)*(N-j)
				elif arena[i][j][idx] and (ans < (N-i)*(N-j)):
					ans = (N-i)*(N-j)
	return ans

def main() -> "__main__":
	'''
	-> calculate other values from one spacific axis
	-> create new values and use it further
	-> use these for optimization
	'''
	N = int(input())
	infected = [[[0 for i in range(N)] 
				for j in range(N)] for k in range(N)]
	
	for k in range(N):
		for j in range(N):
			inp = input()
			for i in range(N):
				temp = True if inp[i] == '1' else False
				infected[i][j][k] = temp # bool

	# axis seperated arr(s)
	xperm = [i for i in range(N)]
	yperm = [i for i in range(N)]
	zperm = [i for i in range(N)]

	xCost = []
	yCost = []
	zCost = []

	for i in range(N):
		xCost.append(GetCost(i ,N ,infected
		 ,[] ,[] ,[] ,True ,False))

	sortedX = list(enumerate(xCost)) # (index ,value)
	sortedX.sort(key = lambda x:x[1]) #(sorted *value -> key pair)
	newXIndices = [value[0] for value in sortedX] # accessing key

	# using these further
	for i in range(N):
		yCost.append(GetCost(i ,N ,infected
		 ,newXIndices ,[] ,[] ,False ,True))

	sortedY = list(enumerate(yCost))
	sortedY.sort(key = lambda x:x[1])
	newYIndices = [value[0] for value in sortedY]

	for i in range(N):
		zCost.append(GetCost(i ,N ,infected
		 ,newXIndices ,newYIndices ,[] ,False ,False))

	sortedZ = list(enumerate(zCost))
	sortedZ.sort(key = lambda x :x[1])
	newZindices = [value[0] for value in sortedZ]

	xCost = []
	# Optimized 
	for i in range(N):
		xCost.append(GetCost(i ,N ,infected
		 ,[] ,[] ,newZindices ,True ,False))

	sortedX = list(enumerate(xCost))
	sortedX.sort(key = lambda x:x[1])

	# easy out(0)
	OUTPUT(sortedX)
	OUTPUT(sortedY)
	OUTPUT(sortedZ)


if __name__ == '__main__':
	main()