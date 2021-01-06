# foobar
def solution(H , Q):
	def _get( x ):
		l , r = 1 , (1<<H) - 1
		if( r == x ): 
			return -1
		while( x >= 1 ):
			r -= 1
			m = (l + r) // 2
			if(m == x or r == x) :
				return (r + 1)
			elif( x < m ):
				r = m
			else :
				l = m
	ret = [ _get(i) for i in Q ]
	return ret 

if __name__ == '__main__':
	print(solution(5, [19, 14, 28]))