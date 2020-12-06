
def calc() -> None:
	n ,m ,k ,q = map(int , input().split())
	_query = [[*map(int , input().split())] for _ in range(q)]
	if k == 3:
		print(f'2 {m-1}'*q)
		if int(input()) == -1: exit()
		return
	for i in _query:
		print(f'1 {i[0]} {i[-1]} {m + 1 >> 1}')
		_x = int(input())
		if _x == -1: exit()
		i[0] = _x
	print(2 ,end = "")
	for i in _query: print(f' {i[0]}' ,end = "")
	print()
	if int(input()) == -1: exit()

def main() -> None:
	for _ in range(int(input())): calc()

if __name__ == '__main__':
	main()
	exit()
