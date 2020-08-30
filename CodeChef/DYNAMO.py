
def main() -> None:
	
	for i in range(int(input())):

		N , a = int(input()) ,int(input())
		s = pow(10,N)
		print(a + 2*s)
		print(s - int(input()))
		print(s - int(input()))
		if int(input()) == -1 : exit()


if __name__ == '__main__':
	main()