'''
	Obviously, if a set contains a point (x', y'), 
	it can not contain any other point with x=x' 
	or y=y', because these two points would be 
	an integer distance apart. There are only n+1 
	distinct x-coordinates and m+1 distinct 
	y-coordinates. Therefore, the size of the 
	set sought can not exceed min(n, m) + 1.

	If the constraint x+y>0 was not present, 
	the set of points (i, i) (0 <= i <= min(n, m)) 
	would do nicely. The distance between two points 
	(i, i) and (j, j) is equal to |i-j|*sqrt(2) and 
	can only be integer when i=j. On the other hand, 
	there are min(n, m) + 1 points and we already know 
	that we can't take more than that.

	Since point (0, 0) is restricted, 
	we can take the other "diagonal", i.e. 
	use points (i, min(n, m) - i).
'''
n , m = map(int , input().split())

k = min(n , m)
print(k+1)

for i in range(k+1):
	print(i, k-i)
