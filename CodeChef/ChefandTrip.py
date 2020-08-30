# for case in range(int(input())):
# 	n , K = map(int , input().split())
# 	*arr , = map(int , input().split())

# 	if arr.count(-1) == n:
# 		print('YES')

# 		if not n&1:
# 			print('1 2 '*(n//2))
# 		else:
# 			print('1' , '2 1 '*(n//2))

# 	else:
# 		# for idx in range(n):
# 		# 	if idx == 0:
# 		# 		if arr[idx] == -1 :
# 		# 			arr[idx] = arr[idx+1]
# 		if arr[0] == -1:
# 			if n > 1:
# 				if K - arr[1] > 0:
# 					arr[0] = 1
# 				else:
# 					arr[0] = arr[1] - K
# 			else:
# 				arr[0] = K

# 		arr += [0]
# 		flag = 1

# 		for idx in range(1 , n):
# 			if arr[idx] == -1 :
# 				L = arr[idx-1]
# 				R = arr[idx+1]

# 				if R == 0 or R == -1:
# 					val = abs(L - K)
# 					if not val:
# 						val = 1
# 					else:
# 						val = 2
# 					# if L > K:
# 					# 	arr[idx] = val
# 					# else:
# 					# 	arr[idx] = val
# 					arr[idx] = val

# 				else:
# 					val = 0
# 					if L == R:
# 						val = abs(K-L)
# 						if not val:
# 							val = 1
# 						else:
# 							val = 2
# 						arr[idx] = val

# 					if abs(L-R) == 1:
# 						print('NO')
# 						flag = 0
# 						break

# 					else:
# 						val = (L+R)//2
# 						arr[idx] = val

# 		if flag:
# 			print('YES')
# 			print(*arr)


# for case in range(int(input())):
# 	n , K = map(int , input().split())
# 	*arr , = map(int , input().split())

# 	if arr.count(-1) == n:
# 		print('YES')

# 		if not n&1:
# 			print('1 2 '*(n//2))
# 		else:
# 			print('1' , '2 1 '*(n//2))
			
# 	else:
# 		if arr[0] == -1:
# 			if n > 1:
# 				if K - arr[1] > 0:
# 					arr[0] = 1
# 				else:
# 					arr[0] = arr[1] - K
# 			else:
# 				arr[0] = K

# 		arr += [0]
# 		flag = 1

# 		for idx in range(1 , n):
# 			if arr[idx] == -1 :
# 				L = arr[idx-1]
# 				R = arr[idx+1]

# 				if R == 0 or R == -1:
# 					val = abs(L - K)
# 					if val: # not val
# 						val = 1
# 					else:
# 						val = 2

# 					arr[idx] = val

# 				else:
# 					val = 0
# 					if L == R:
# 						val = abs(K-L)
# 						if not val:
# 							val = 1
# 						else:
# 							val = 2
# 						arr[idx] = val

# 					if abs(L-R) == 1:
# 						print('NO')
# 						flag = 0
# 						break

# 					else:
# 						val = (L+R)//2
# 						arr[idx] = val

# 		temp = 0
# 		for i in arr:
# 			if i == temp:
# 				flag = 0
# 				print('NO')
# 				break
# 			else:
# 				temp = i

# 		if flag:
# 			print('YES')
# 			print(*arr)
 

for case in range(int(input())):
    n, k = map(int, input().split())
    arr = input().split()

    if n == 1:
        print('YES')
        if arr[0] == '-1':
            arr[0] = '1'
        print(arr[0])
        continue

    if k == 2:
        if arr[0] == '-1':
            for i in range(n):
                if arr[i] != '-1': break

            if arr[i] != '-1':
                e = arr[i]
                if e == '1':
                    if i % 2 == 1:
                        arr[0] = '2'
                    else:
                        arr[0] = '1'
                else:
                    if i % 2 == 0:
                        arr[0] = '2'
                    else:
                        arr[0] = '1'
            
            else:
                arr[0] = '1'
        
        for i in range(1, n - 1):
            if arr[i] == '-1':
                if arr[i - 1] == arr[i + 1] or arr[i + 1] == '-1':
                    if arr[i - 1] == '1':
                        arr[i] = '2'
                    else:
                        arr[i] = '1'                
                else:
                    print('NO')
                    break
        else:
            i += 1            
            print('YES')
            if arr[i] == '-1':
                if arr[i - 1] == '1':
                    arr[i] = '2'
                else:
                    arr[i] = '1'
            # print(' '.join(arr))
            print(*arr , sep = ' ')

    else:
        if arr[0] == '-1':
            if arr[1] == '1':
                arr[0] = '2'
            else:
                arr[0] = '1'
        
        for i in range(1, n - 1):
            if arr[i] == '-1':
                if arr[i -1] == '1' or arr[i + 1] == '1':
                    if arr[i - 1] == '2' or arr[i + 1] == '2':
                        arr[i] = '3'
                    else:
                        arr[i] = '2'
                else:
                    arr[i] = '1'   
        else:    
            i += 1
            if arr[i] == '-1':
                if arr[i - 1] == '1':
                    arr[i] = '2'
                else:
                    arr[i] = '1'
            print('YES')
            # print(' '.join(arr))
            print(*arr , sep = ' ')