# foobar level 1
def solution(x : str ) -> str:
	a = list(x) 
	rev = [chr(i) for i in range(122 , 96 , -1)]
	for i in range(len(a)):
		if(a[i].islower()):
			a[i] = rev[ord(a[i]) - 97]
	return "".join(a)

if __name__ == '__main__':
	print(solution( input() ))
