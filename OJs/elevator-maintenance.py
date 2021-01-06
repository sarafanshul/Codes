# foobar

def solution(l):
	l.sort(key = lambda s : list(map(int, s.split('.'))) )
	return l

if __name__ == '__main__':
	x = ["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"]
	print(solution( x ))