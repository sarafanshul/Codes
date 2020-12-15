class MAP(dict):
    def __missing__(self, key):
        value = 0
        self[key] = value
        return value

def check():
	n ,m = map(int , input().split())
	_str = input()
	_m = map(int , input().split())
	# _map = MAP()

	_map = [[0 for _ in range(26)] for i in range(n)]

	_map[0][ord(_str[0]) - 97] = 1

	for i in range(1 ,n):
		v = ord(_str[i]) - 97
		for j in range(26):
			if j == v: _map[i][j] = _map[i - 1][j] + 1
			else :_map[i][j] = _map[i - 1][j]

	_ret = [0 for i in range(26)]

	for i in _m:
		for j in range(26):
			_ret[j] += _map[i-1][j]

	print(*_ret)


def main():
	for i in range(int(input())):
		check()

if __name__ == '__main__':
	main()