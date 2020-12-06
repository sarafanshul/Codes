for t in range(int(input())):
	S ,*W = map(int , input().split())
	sm = sum(W)
	if S >= sm: print(1)
	else: print(-(-sm//S) + S%W[-2]) # ceil division