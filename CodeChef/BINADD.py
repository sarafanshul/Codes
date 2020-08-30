# use PyPy3 for faster JIT
# for python 2 LOOOSERS :( 
if 2/3 == 2//3:
	input = raw_input
else: pass

def copy_add(orginal ,location ,length ,max_length) -> 'No Explicit Return':
	a = length - 1
	b = max_length - 1
	for a in range(a ,-1 ,-1):
		location[b] = orginal[a] 
		b -= 1 

# binADD.__main__ called 
def binAdd(a ,b) -> int:
	# base
	if b == '0': return 0
	# init
	len_a = len(a)
	len_b = len(b)
	max_length = len_a if len_a > len_b else len_b
	num_a = ['0' for _ in range(max_length)]
	num_b = ['0' for _ in range(max_length)]
	copy_add(a, num_a, len_a, max_length)
	copy_add(b, num_b, len_b, max_length)
	flag = current_len = ans = 0 # remove if "ID" error (same id , etc)
	i = max_length - 1

	# compute
	for i in range(i ,-1 ,-1):
		if flag:
			if num_a[i] != num_b[i]: current_len += 1
			elif num_a[i] == num_b[i]:
				if current_len > ans: ans = current_len
				if num_a[i] == '1':
					current_len = 1
					flag = 1
				else:
					current_len = 0
					flag = 0
		elif num_a[i] == num_b[i] and num_a[i] == '1':
			flag = current_len = 1
	if flag:
		if current_len > ans: ans = current_len
	return ans + 1 

def main() -> 'main':
	# cases
	for _ in range(int(input() ,10)): 
		# call
		print(binAdd(input() ,input()))

# basic bitch like dineshC
if __name__ == '__main__':
# Python 3.7.3 (v3.7.3:ef4ec6ed12, Mar 25 2019, 21:26:53) [MSC v.1916 32 bit (Intel)] on win32
	main()
	exit()


# def funADD(A , B):
# 	cnt = 0
# 	A , B = int(A ,2)  ,int(B ,2)
# 	while B > 0:
# 		# print(A , B)
# 		U = A ^ B
# 		V = A & B
# 		A = U
# 		B = V*2
# 		cnt += 1
# 	# return (A , cnt)
# 	print(cnt)
# 	return
# for _ in range(int(input())):
# 	A = input()
# 	B = input()
# 	funADD(A , B)

# def funADD(A , B , cnt = 0) -> int:
# 	while B > 0:
# 		U = A ^ B
# 		V = A & B
# 		A , B = U , V*2
# 		cnt += 1
# 	return cnt

# for _ in range(int(input())): 
# 	print(funADD(int(input() , 2) , int(input() , 2)))

# def funADD(A , B):
# 	cnt = 0
# 	# print(A , B)
# 	while B > 0:
# 		U = A ^ B
# 		V = (A & B)<<1
# 		A , B = U , V
# 		# B = V
# 		cnt += 1
# 		# print(A , B)
# 	# return (A , cnt)
# 	print(cnt)
# 	return

# for _ in range(int(input())):
# 	A = int(input(), 2)
# 	B = int(input(), 2)
# 	funADD(A , B)
# exit()

# len = len

# def binAdd(a , b):
# 	cnt = 0

# 	if len(a) >= len(b):
# 		for i in range(len(b)):

# 			if (a[len(a) - 1 - i] == '1') and (b[len(b) - 1 - i] == '1') :
# 				j = i + 1
# 				for j in range(j , len(a)):
# 					u = a[len(a) - 1 - j] if j < len(a) else '0'
# 					v = b[len(b) - 1 - j] if j < len(b) else '0'
# 					if (not (u == '0' and v == '1')) and (not(u == '1' and v == '0')):
# 						break # check here

# 				cnt = max(cnt , j - i + 1)

# 			elif (a[len(a) -1 -i] == '0') and (b[len(b) - 1 - i] == '1'):
# 				cnt = max(cnt , 1)
	
# 	else:
# 		for i in range(len(a)):
# 			if (a[len(a) -1 -i] == '1') and (b[len(b) - 1 - i] == '1'):
# 				j = i + 1
# 				for j in range(j , len(b)):
# 					u = a[len(a) - 1 - j] if j < len(a) else '0'
# 					v = b[len(b) - 1 - j] if j < len(b) else '0'
# 					if (not (u == '0' and v == '1')) and (not(u == '1' and v == '0')):
# 						break
# 				cnt = max(cnt , j - i + 1)
				
# 			elif (a[len(a) -1 -i] == '0') and (b[len(b) - 1 - i] == '1'):
# 				cnt = max(cnt , 1)
# 		for i in range(len(a) , len(b)):
# 			if b[len(b) - 1 - i] == '1':
# 				cnt = max(cnt , 1)

# 	return cnt # try swapping bigger for only one loop

# def main():
# 	for _ in range(int(input())):
# 		a = input()
# 		b = input()
# 		print(binAdd(a , b))

# if __name__ == '__main__':
# 	main()

# def copy_Ed(orginal ,location ,length ,max_length):
# 	a = length - 1
# 	b = max_length - 1
# 	# while a>= 0: # for a in range(a+1 ,-1 ,-1):
# 	# 	location[b] = orginal[a]
# 	# 	a -= 1 # 
# 	# 	b -= 1 
# 	for a in range(a ,-1 ,-1):
# 		location[b] = orginal[a] 
# 		b -= 1 


# for _ in range(int(input())):
# 	a = input()
# 	b = input()

# 	if b == '0': 
# 		# print(0)
# 		return 0
# 		# continue

# 	len_a = len(a)
# 	len_b = len(b)
# 	# max_length = max(len_a ,len_b)
# 	max_length = len_a if len_a > len_b else len_b

# 	# num_a = ['0']*max_length
# 	# num_b = ['0']*max_length
# 	num_a = ['0' for _ in range(max_length)]
# 	num_b = ['0' for _ in range(max_length)]

# 	copy_Ed(a, num_a, len_a, max_length)
# 	copy_Ed(b, num_b, len_b, max_length)

# 	flag = 0
# 	current_len = 0
# 	i = max_length - 1
# 	ans = 0

# 	while i >= 0: # for i in range(i ,-1 ,-1):
# 	for i in range(i ,-1 ,-1):

# 		if flag:
# 			if num_a[i] != num_b[i]: current_len += 1

# 			elif num_a[i] == num_b[i]:
# 				if current_len > ans: ans = current_len

# 				if num_a[i] == '1':
# 					current_len = 1
# 					flag = 1

# 				else:
# 					current_len = 0
# 					flag = 0

# 		elif num_a[i] == num_b[i] and num_a[i] == '1':
# 			flag = 1
# 			current_len = 1

# 		# i -= 1
		
# 	if flag:
# 		if current_len > ans: ans = current_len

# 	return ans + 1 

# 	# print(ans + 1)

# def copy_add(orginal ,location ,length ,max_length) -> 'No Explicit Return':
# 	a = length - 1
# 	b = max_length - 1
# 	for a in range(a ,-1 ,-1):
# 		location[b] = orginal[a] 
# 		b -= 1 

# def binAdd(a ,b) -> int:
# 	# base
# 	if b == '0': return 0
# 	# init
# 	len_a = len(a)
# 	len_b = len(b)
# 	max_length = len_a if len_a > len_b else len_b
# 	num_a = ['0' for _ in range(max_length)]
# 	num_b = ['0' for _ in range(max_length)]
# 	copy_add(a, num_a, len_a, max_length)
# 	copy_add(b, num_b, len_b, max_length)
# 	flag = current_len = ans = 0 # remove if "ID" error (same id , etc)
# 	i = max_length - 1

# 	# compute
# 	for i in range(i ,-1 ,-1):
# 		if flag:
# 			if num_a[i] != num_b[i]: current_len += 1
# 			elif num_a[i] == num_b[i]:
# 				if current_len > ans: ans = current_len
# 				if num_a[i] == '1':
# 					current_len = 1
# 					flag = 1
# 				else:
# 					current_len = 0
# 					flag = 0
# 		elif num_a[i] == num_b[i] and num_a[i] == '1':
# 			flag = current_len = 1
# 	if flag:
# 		if current_len > ans: ans = current_len
# 	return ans + 1 

# # cases
# def main() -> 'main':
# 	for _ in range(int(input() ,10)): 
# 		# call
# 		print(binAdd(input() ,input()))

# if __name__ == '__main__':
# 	main()
