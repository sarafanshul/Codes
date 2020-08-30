
# fucking things I PRESUME **(ZERO CAN BE ANS TOO)**
import math
for case in range(int(input())):
	N, M = map(int, input().split())

	if M == 0 and N == 1: print(0)  # try zero

	elif M == 1:
		if N == 2 or N == 1: print(1)
		else: print(-1)

	elif M < N-1 or M > N*(N+1)/2 or M == 0: print(-1)

	elif M <= N + 1: print(2)  # considering cyclic structures too

	else:
		ans = math.ceil(2*(M/N) - 1)
		avs = max(int(ans), 3)
		print(min(N, avs))






# for case in range(int(input())):
# 	N , M = map(int , input().split())

# 	# 1) base cases
# 	if M < N-1:
# 		print(-1)
# 	elif M > N*(N+1)//2:
# 		print(-1)
# 	# messed up case of 1
# 	elif N == 1 and M == 1:
# 		print(1)
# 		if M != 1:
# 			print(-1)
# 	elif N == M:
# 		print(2)

# 	# max case of 1
# 	elif M == N-1:
# 		print(1)
# 	# max case of 2
# 	elif M < (N-1)*2:
# 		print(2)
# 	# other cases
# 	else:
# 		print(3)


# for case in range(int(input())):
# 	N, M = map(int, input().split())

# 	if M == 1:
# 		if N == 2 or N == 1:
# 			print(1)
# 		else:
# 			print(-1)

# 	elif M == 0:
# 		print(-1)
# 	elif M < N-1:
# 		print(-1)
# 	elif M > N*(N+1)/2:
# 		print(-1)

# 	# max case of 2
# 	elif M <= N + 1:
# 		print(2)  # considering cyclic structures too
# 	# elif M == N*(N+1)//2:
# 	# 	print(N)
		
# 	else:
# 		ans = 2*(M/N) - 1
# 		if M % N:
# 			chk = 1
# 		else:
# 			chk = 0
# 		mx = N
# 		avs = max(int(ans+chk), 3)
# 		print(min(N, avs))

# import math
# for case in range(int(input())):
# 	N, M = map(int, input().split())

# 	if M == 1:
# 		if N == 2 or N == 1:
# 			print(1)
# 		else:
# 			print(-1)

# 	elif M == 0:
# 		print(-1)
# 	elif M < N-1:
# 		print(-1)
# 	elif M > N*(N+1)/2:
# 		print(-1)

# 	# max case of 2
# 	elif M <= N + 1:
# 		print(2)  # considering cyclic structures too

# 	else:
# 		ans = math.ceil(2*(M/N) - 1)
# 		if M % N:
# 			chk = 0
# 		else:
# 			chk = 0
# 		mx = N
# 		avs = max(int(ans+chk), 3)
# 		print(min(N, avs))

# # fucking things I PRESUME **(ZERO CAN BE ANS TOO)
# import math
# for case in range(int(input())):
# 	N, M = map(int, input().split())

# 	if M == 0 and N == 1:
# 	    print(0)  # try zero

# 	elif M == 1:
# 		if N == 2 or N == 1:
# 			print(1)
# 		else:
# 			print(-1)

# 	elif M < N-1 or M > N*(N+1)/2 or M == 0:
# 		print(-1)

# 	elif M <= N + 1:
# 		print(2)  # considering cyclic structures too

# 	else:
# 		ans = math.ceil(2*(M/N) - 1)
# 		if M % N:
# 			chk = 0
# 		else:
# 			chk = 0
# 		mx = N
# 		avs = max(int(ans+chk), 3)
# 		print(min(N, avs))
