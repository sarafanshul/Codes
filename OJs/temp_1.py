m = int(input())
p = int(input())
mat1 = []
for i in range( m ):
	mat1.append( list(map(int , input().split())) )

mat2 = []
for i in range( p ):
	mat2.append( list(map(int , input().split())) )

row = [ [] for _ in range(m) ]
col = [ [] for _ in range( len( mat1[0] ) ) ]

def can( i , j ):
	return (i < p and j < len(mat2[0]))

out = [ [-1 for _ in range( len(mat1[0]) ) ] for _ in range(m) ]

def most_frequent(List):
	dict = {}
	count, itm = 0, ''
	for item in reversed(List):
		dict[item] = dict.get(item, 0) + 1
		if dict[item] >= count :
			count, itm = dict[item], item
	ans = []
	for k in dict.keys():
		if( dict[k] == count ) : ans.append(k)
	return(min(ans))

for i in range( m ):
	for j in range( len( mat1[0] ) ):
		r , c = i , j
		prod = []
		if( can(r , c) ):
			prod.append(mat1[i][j] * mat2[r][c])		
		r , c = i , i
		if( can(r , c) ):
			prod.append(mat1[i][j] * mat2[r][c])		
		r , c = j , j
		if( can(r , c) ):
			prod.append(mat1[i][j] * mat2[r][c])		
		r , c = j , i
		if( can(r , c) ):
			prod.append(mat1[i][j] * mat2[r][c])		
		if( len(prod) ):
			mx = most_frequent( prod )
			out[i][j] = mx		

for i in range( m ):
	print( *out[i] )