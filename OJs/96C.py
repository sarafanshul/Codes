def main():	
	n = int(input())
	forbidden = [input() for _ in range(n)]

	res = input()
	f = [0 for i in range(len(res))]
	letter = input()

	for i in range(n):
		for j in range(len(res)):
			if len(res[j:]) < len(forbidden[i]): break
			if res[j: j + len(forbidden[i])].upper() == forbidden[i].upper():
				for k in range(j, j + len(forbidden[i])):
					f[k] = 1
	 
	ans = ""
	for i in range(len(res)):
		if (f[i] == 1):
			if (res[i].upper() == letter.upper()):
				if letter.upper() == 'A':
					if res[i].isupper(): ans = ans + 'B'
					else: ans = ans + 'b'
				else:
					if res[i].isupper(): ans = ans + 'A'
					else: ans = ans + 'a'
			else:
				if res[i].isupper(): ans = ans + letter.upper()
				else: ans = ans + letter
		else: ans = ans + res[i]
	print( ans)

if __name__ == '__main__':
	main()