# print("NO")
'''
5
as well as 5 as well as 3 elevation multiplicationum give to the bresult varum
Circumfarence

4
Coordinates
'''

def isInside( x, y): 
	rad = 63/2
	circle_y = 63/2
	circle_x = 63/2
	if ((x - circle_x) * (x - circle_x) + 
		(y - circle_y) * (y - circle_y) <= rad * rad): 
		print("IN")
	else: 
		print("OUT")

a1 ,a2 = map(int , input().split())
