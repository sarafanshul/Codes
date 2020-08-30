# for case in range(int(input())):
#     N = int(input())
#     *a , = map(int , input().split())

#     strarr = sorted(a)

#     star = 0
#     for el in strarr:

#         rng = a.index(el)
#         if rng <= star: break
#         temp = 0

#         for j in range(rng):
#             if a[j]%el == 0: temp += 1

#         star = max(star , temp)

#     # for i in range(N-1 , -1 , -1):
#     #     if star >= i : break
#     #     tmp = 0
        
#     #     for j in range(i):
#     #         if  a[j]%a[i] == 0: tmp += 1
        
#     #     star = max(star , tmp)
    
#     print(star)

# for case in range(int(input())):
#     N = int(input())
#     *a, = map(int, input().split())

#     if N < 5000:
#         star = 0
#         for i in range(N-1, -1, -1):
#             if star > i:
#                 break
#             tmp = 0
#             for j in range(i):
#                 if a[j] % a[i] == 0:
#                     tmp += 1
#             star = max(star, tmp)
#         print(star)
#     else:
#         strarr = sorted(a)
#         star = 0
#         for el in strarr:
#             rng = a.index(el)
#             if rng <= star:
#                 break
#             temp = 0
#             for j in range(rng):
#                 if a[j] % el == 0:
#                     temp += 1
#             star = max(star, temp)
#         print(star)

# for case in range(int(input())):
#     N = int(input())
#     *a, = map(int, input().split())

#     dct = dict()

#     for i in a:
#         dct[i] = 0
    
#     for j in range(1 , N):
#         for k in range(j-1 , -1 , -1):
#             # print(j)
#             if not a[k]%a[j]:
#                 # print('treu')
#                 if dct[a[k]]:
#                     # print('89--' ,a[j], dct[a[k]])
#                     dct[a[j]] += dct[a[k]] + 1
#                     break
#                 dct[a[j]] += 1
#     # print(dct)
#     print(max(dct.values()))
        
# for case in range(int(input())):
#     N = int(input())
#     *a, = map(int, input().split())

#     star = 0
#     for i in range(N-1, -1, -1):
#         if star >= i:
#             break
#         tmp = 0

#         if a[i] == 1: 
#             tmp += i
#             continue
#         for j in range(i):
#             if a[j] % a[i] == 0:
#                 tmp += 1

#         star = max(star, tmp)

#     print(star)

for case in range(int(input())):
    N = int(input())
    *a, = map(int, input().split())

    mx = 0
    arr2 = [0 for i in range(N)]
    n = N-1

    while n :
        if arr2[n] == 1:
            n -= 1
            continue

        sr = 0
        a = a[n]

        for i in range(n-1 , -1 , -1):
            if not a[i]%a[n]:
                arr2[i] = 1
                sr += 1

        mx = max(mx , sr)

        n -= 1

    print(mx) 
