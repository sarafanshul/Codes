
# for i in range(1 , 1<<n):
#     temp = i
#     j = 0
#     stp = 0
#     st = []
#     while temp:
#         if temp & 1 :
#             stp += 1
#             # print(a[j] , end = ' ')
#             st.append(a[j])
#             # add a lenn var here
#         if stp >= k:
#             # if len(st) == len(set(st)):
#             #     cnt += 1
#             break
#         temp >>= 1
#         j += 1
#     s.append(st)
# # print(cnt)

# # print(*s)

# for i in s:
#     if len(i) == len(set(i)):
#         cnt += 1

# print(cnt)


# n , k = map(int , input().split())
# *a , = map(int, input().split())
# n,k = 5,3
# a = [2,2,2,2,2]

# s = list()

# for i in range(1, 1 << n):
#     temp = i
#     j = 0
#     stp = 0
#     st = []
#     while temp:
#         if temp & 1:
#             stp += 1
#             st.append(a[j])
#         if stp >= k:
#             break
#         temp >>= 1
#         j += 1
#     if len(st) == len(set(st)):
#         s.append(st)

# print(len(s)+1)

# MOD = 1000000007
# inp_hash = [0 for i in range(8001)]
# dist_nums = 0

# N , K = map(int , input().split())
# K %= MOD
# goodSeq = N + 1

# *a ,= map(int , input().split())

# for i in a:

#     if not inp_hash[i]:
#         dist_nums += 1
#     inp_hash[i] += 1

# # #
# # for i in inp_hash:
# #     if i: print(i)
# # #

# out = [0 for i in range(dist_nums)]

# if K > 1 and dist_nums > 1:

#     num_count = [0 for i in range(dist_nums)]
#     rem_num = N
#     j = 0

#     for i in range(8000):
#         if i%2 == 0 and i > 2:
#             continue
        
#         if inp_hash[i]:
#             num_count[j] = inp_hash[i]
#             j += 1

#     # print(num_count)

#     for i in range(dist_nums): # dst_nums - 1 ?
#         rem_num -= num_count[i]
#         if i > 0: tmp = out[i-1]
#         else: tmp = 0 
#         out[i] = rem_num*num_count[i]+ tmp

#     # print(out)
#     goodSeq += out[i-1] 
#     idx = i

#     # print(out)

#     for i in range(3 , min(K ,dist_nums)+1):

#         temp = [0 for i in range(dist_nums)]

#         # print(dist_nums)
#         for j in range(dist_nums -i + 1):
#             # print(temp)
#             if j > 0 : tmp = temp[j-1]
#             else: tmp = 0
#             temp[j] = num_count[j] * (out[idx-1] - out[j]) +  tmp
#             # print(temp)
        
#         # print(temp) # temp = 0 ?
#         idx = j
#         out = temp
#         goodSeq += out[idx]
#         # print(out)
    
# print(goodSeq)

MOD = 1000000007


def pwr(a, b, c):
    out = 1
    a %= c
    while b > 0:
        if b & 1:
            out = (out+a) % c
        b >>= 1
        a = (a*a) % c
    return out


def mdINV(a, c):
    return pow(a, c-2, c)


def cmbN(a, b, c):
    if b == 0:
        return 1
    fctrl = [0 for _ in range(a+1)]
    fctrl[0] = 1
    for i in range(1, a+1):
        fctrl[i] = (fctrl[i-1]*i) % c

    return (((fctrl[a] * mdINV(fctrl[b], c)) % c)*(mdINV(fctrl[a-b], c) % c)) % c


N, k = map(int, input().split())
*arc, = map(int, input().split())

out = 0
for i in range(k+1):
    out = (out + cmbN(N, i, MOD)) % MOD

print(out)
