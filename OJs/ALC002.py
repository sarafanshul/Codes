'''

  _                            _   _  _____ _    _ _    _ _      
 | |             _       /\   | \ | |/ ____| |  | | |  | | |     
 | |__  _   _   (_)     /  \  |  \| | (___ | |__| | |  | | |     
 | '_ \| | | |         / /\ \ | . ` |\___ \|  __  | |  | | |     
 | |_) | |_| |   _    / ____ \| |\  |____) | |  | | |__| | |____ 
 |_.__/ \__, |  (_)  /_/    \_\_| \_|_____/|_|  |_|\____/|______|
         __/ |                                                   
        |___/                                                    

'''

# ========= asnhul ========
# def Func(a, k):
# 	if len(a) <= k:
# 		return a
# 	test = []
# 	i = 1
# 	while len(a) >= k:
# 		test.append(sum(a[:k]))
# 		a = a[k:]
# 	test.extend(a)
# 	print(test)
# 	return Func(test , k)

# for _ in range(int(input())):
# 	n , k = map(int , input().split())
# 	*a , = map(int , input().split())

# 	out = Func(a , k)

# 	if len(out) == k:
# 		print(sum(out))
# 	else:
# 		print(*out)

# import pdb; pdb.set_trace()


for i in range(int(input())):
    n,K = map(int,input().split())
    *A , = map(int,input().split())

    while(len(A) >= K):
        B=[]
        i = j = 0

        while(j < len(A)):
            s = 0
            if (len(A)-j) < K:
                s = A[j]
                j += 1
            else:
                for i in range(K):
                    s = s + A[j+i]
                j += i+1
            
            B.append(s) 
        A = B

    print(*A)