def calculate(N:int ,M:int ,arr:list ,out:int) -> int:

	for i in range(N):
		for j in range(M):

			_len = 1 
			while i - _len >= 0 and \
			i + _len < N and j - _len >= 0 \
			and j + _len < M: # boundary conditions

				if arr[i][j-_len] == arr[i][j+_len] \
				and arr[i-_len][j] == arr[i+_len][j]: # basic opt approach
					# out  ,_len = out + 1 , _len + 1
					out += 1
				else: break
				_len += 1

	return out


def main() -> None:

	for _ in range(int(input())):
		N ,M = map(int , input().split())
		arr_mat = [[] for _ in range(N)]
		for i in range(N) : arr_mat[i].extend(map(int , input().split()))
		print(calculate(N ,M ,arr_mat ,N*M)) 


if __name__ == '__main__':
	main() # lemme call