
# odd -> False
# even -> True
def print_out(ans:bool = False ,arr:list = [[1]]) -> None: #zen Python
	if ans :
		print("Hooray")
		for line in arr: print(*line)
	else: print("Boo")

def main() -> None:
	for _ in range(int(input())):

		N = int(input())
		
		if N == 1: 
			print_out(ans = True)
		elif N&1: 
			print_out(ans = False)
		else:
			# impl_f *2 , *3#4
			arr = [[ 1 if i == j else None for i in range(N)] \
				for j in range(N)]
			decl_arr = [[None for _ in range(N//2)] \
				for _ in range(N-1)]

			for i in range(N-1): #(Not met_2)
				decl_arr[i][0] = [N-1 ,i] # base
				for k in range(1 ,N//2):
					decl_arr[i][k] = [(i+k)%(N-1) ,(i-k+N-1)%(N-1)]
			
			for i in range(N-1): # *2 !=
				for sub_arr in decl_arr[i]:
					arr[sub_arr[0]%N][sub_arr[-1]%N] = 2 + i
					arr[sub_arr[-1]%N][sub_arr[0]%N] = N + 1 + i

			print_out(ans = True , arr = arr)


if __name__ == '__main__':
	main()

