for case in range(int(input())):
    N, K = map(int, input().split())
    *a, = map(int, input().split())

    if K > N//2 and N % 2:
        a[N//2] = 0
    K = K % (N*3)

    for i in range(K):
        a[i % N] ^= a[N-(i % N)-1]
    print(*a)

# for case in range(int(input())):
#     N , K = map(int , input().split())
#     *a , = map(int , input().split())

#     # out = [0 for i in range(min(N , K))]

#     for i in range(K):
#         aa =  a[i%N]
#         bb = a[(N - (i%N)-1)]
#         a[i%N] = aa^bb
    
#     print('--'  ,*a)


# for case in range(int(input())):
#     print('9 0 -- 1 2 3 4 5 6 7 8 9')
#     for k in range(1,600):
#         # N, K = map(int, input().split())
#         # *a, = map(int, input().split())
#         N = 9
#         K = k
#         a = [1,2,3,4,5,6,7,8,9]
        
#         # out = [0 for i in range(min(N , K))]

#         for i in range(K):
#             aa = a[i % N]
#             bb = a[(N - (i % N)-1)]
#             a[i % N] = aa ^ bb

#         print(N , K,'--', *a)

# for case in range(int(input())):
#     N, K = map(int, input().split())
#     *a, = map(int, input().split())

#     # out = [0 for i in range(min(N , K))]

#     if K <= N:
            
#         for i in range(K):
#             aa = a[i % N]
#             bb = a[(N - (i % N)-1)]
#             a[i % N] = aa ^ bb

#     else:
#         nwar = []
#         for i in range((N*3)+1):
#             aa = a[i % N]
#             bb = a[(N - (i % N)-1)]
#             a[i % N] = aa ^ bb
#             # nwar.append(a)
#             if i == K%(N*3)-1:
#                 if N%2:
#                     a[N//2] = 0
#                 print(*a)
#                 break
        
#     #     ans = nwar[K%(N*3)]

#     #     if N%2:
#     #         ans[(N//2)] = 0

#     # print(nwar)
#     # print(*ans)


# for case in range(int(input())):
#     N, K = map(int, input().split())
#     *a, = map(int, input().split())
#     b = a.copy()

#     if K <= N:

#         for i in range(K):
#             aa = a[i % N]
#             bb = a[(N - (i % N)-1)]
#             a[i % N] = aa ^ bb
        
#         print(*a)

#     else:

#         for i in range((N*3)+1):
#             aa = a[i % N]
#             bb = a[(N - (i % N)-1)]
#             a[i % N] = aa ^ bb

#             if i == K % (N*3)-1:
#                 if N % 2: a[N//2] = 0
#                 print(*a)
#                 break
        
#         if not K % N*3:
#             if N%2:b[N//2] = 0
#             print(*b)


# for case in range(int(input())):
#     N, K = map(int, input().split())
#     *a, = map(int, input().split())

#     if not K%(N*3):
#         if N%2 : a[N//2] = 0
#         print(*a)

#     else:
#         for i in range(0 , (N*3)):
#             aa = a[i % N]
#             bb = a[(N - (i % N)-1)]
#             a[i % N] = aa ^ bb

#             if K <= N and i+1 == K:
#                 print(*a)
#                 break

#             if i == K%(N*3)-1:
#                 print(*a)
#                 break

# for case in range(int(input())):
#     N, K = map(int, input().split())
#     *a, = map(int, input().split())

#     if K>N//2 and N%2:
#         a[N//2] = 0
    
#     K = K%(N*3)

#     for i in range(K):
#         a[i%N] ^= a[N-(i%N)-1]
    
#     print(*a)
