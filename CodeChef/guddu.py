# # ============ finally 25-8-19 ===========

def prefixXor(arr):
    output = [0]
    temp = 0
    out = dict()
    out[0] = [1 , 0]
    ans = 0

    for item in range(len(arr)):
        temp ^= arr[item]
        # creating a Prefix array
        output.append(temp)

        # creating base values with help of prefix array
        '''these base values are keys to a dictionary 
           eg {0:[1,0],etc} these base values hold two 
           values to a list 
           1) count = number of breakpoints 
                      to for subarray of ,
           2) sum  = sum of number of elements 
                     in these subarray(s) '''
        if not output[item+1] in out.keys():
            out[output[item+1]] = [0 , 0]


        count = out[output[item+1]][0]
        su = out[output[item+1]][1]

        # print(count,(item+1) , count , su)
        ''' here with the help of this formula
            {ans += count*item - count -sum}
            we find the total number of subarrays
            i.e answer '''
        ans += (count*(item+1)) - count - su
        count += 1

        # here we update the values
        out[output[item+1]][0] = count
        out[output[item+1]][1] += item+1
        # print(out)

    return ans

# driver Function
for _ in range(int(input())):
    N = int(input())
    arr = list(map(int , input().split()))
    print(prefixXor(arr))

# ==============================================================




















# # # Works time = 4sec  >>>>TLE<<<<<
# for case in range(int(input())):
#     N = int(input())
#     lst = list(map(int , input().split()))
#     count = 0 
#     final = ((a, b, c) for a in range(1,N+1) for b in range(a+1, N+1) for c in range(b, N+1))
#     while True:
#         # print('w')
#         try:
#             lt = next(final)
#         except:
#             break
#         xa = 0
#         xb = 0
#         for i in range(lt[0] , lt[1]):
#             xa = xa^lst[i-1]
#         for j in range(lt[1] , lt[2]+1):
#             xb = xb^lst[j-1]
#         # print(xa,xb)
#         if xa==xb: count += 1
#     print(count)
            
# import psyco
# psyco.full() # # PSYCO DOES  NOT WORK


# # # 1 case working + TLE
# for case in range(int(input())):
#     N = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0 
#     final = ((a, b, c) for a in range(1,N+1) for b in range(a+1, N+1) for c in range(b, N+1))
#     while True:
#         # print('w')
#         try:
#             lt = next(final)
#         except:
#             break
#         xa = 0
#         xb = 0
#         for i in range(lt[0] , lt[1]):
#             xa = xa^lst[i-1]
#         for j in range(lt[1] , lt[2]+1):
#             xb = xb^lst[j-1]
#         # print(xa,xb)
#         if xa==xb: count += 1
#     print(count)
            

# # # WORKS FIRST CASE BUT TLE
# # # Time = 3.92sec
# for case in range(int(input())):
#     N = int(input())
#     lst = tuple(map(int , input().split()))
#     final = [(a, b, c) for a in range(1,N+1) for b in range(a+1, N+1) for c in range(b, N+1)]
#     count = 0 
#     for l in range(len(final)):
#         lt = final[l]
#         xa = 0
#         xb = 0
#         for i in range(lt[0] , lt[1]):
#             xa = xa^lst[i-1]
#         for j in range(lt[1] , lt[2]+1):
#             xb = xb^lst[j-1]
#         if xa==xb: count += 1
#     print(count)
            


# # # # time = 3.99sec 

# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     # final = [(a, b, c) for a in range(1,N+1) for b in range(a+1, N+1) for c in range(b, N+1) if (a+b+c)>N]
#     final =[]
#     for k in range(2 , n+1): # because i can be =1 and  j=2
#         for j in range(2 , k+1):
#             for i in range(1 , j):
#                 final.append([i,j,k])
#     count = 0 
#     for l in range(len(final)):
#         lt = final[l]
#         xa = 0
#         xb = 0
#         for i in range(lt[0] , lt[1]):
#             xa = xa^lst[i-1]
#         for j in range(lt[1] , lt[2]+1):
#             xb = xb^lst[j-1]
#         if xa==xb: count += 1
#     print(count)


# # # # idk why but 3.99sec
# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     # final = [(a, b, c) for a in range(1,N+1) for b in range(a+1, N+1) for c in range(b, N+1) if (a+b+c)>N]
#     # final =[]
#     count = 0
#     for k in range(2 , n+1): # because i can be =1 and  j=2
#         # final =[]
#         for j in range(2 , k+1):
#             for i in range(1 , j):
#                 final =[]
#                 final.append([i,j,k])
#                 xa = 0
#                 xb = 0
#         # try with lt = final[1]
#         # lt = final[0]
#         # for i in range(lt[0] , lt[1]):
#         #     xa = xa^lst[i-1]
#         # for j in range(lt[1] , lt[2]+1):
#         #     xb = xb^lst[j-1]
#         #     print(xa ,xb)
#         # if xa==xb: count += 1
#                 print(final)
#                 for i in range(final[0][0] , final[0][1]):
#                     xa = xa^lst[i-1]
#                 for j in range(final[0][1] , final[0][2]+1):
#                     xb = xb^lst[j-1]
#                 if xa==xb: count += 1
#     # for l in range(len(final)):
#     #     lt = final[l]
#     #     xa = 0
#     #     xb = 0
#     #     for i in range(lt[0] , lt[1]):
#     #         xa = xa^lst[i-1]
#     #     for j in range(lt[1] , lt[2]+1):
#     #         xb = xb^lst[j-1]
#     #     if xa==xb: count += 1
#     print(count)


# # # time = 3.95sec
# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0
#     for k in range(2 , n+1): # because i can be =1 and  j=2
#         for j in range(2 , k+1):
#             for i in range(1 , j):      
#                 final = [i,j,k]
#                 xa = 0
#                 xb = 0
#                 for i in range(final[0] , final[1]):
#                     xa = xa^lst[i-1]
#                 for j in range(final[1] , final[2]+1):
#                     xb = xb^lst[j-1]
#                 if xa==xb: count += 1
#     print(count)


# # # BEST time = 2.13sec
# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0
#     j1,k1=0,0
#     for k in range(2 , n+1): # because i can be =1 and  j=2
#         for j in range(2 , k+1):
#             for i in range(1 , j):      
#                 # final = [i,j,k]
#                 xa = 0
                
#                 for a in range(i , j):
#                     xa = xa^lst[a-1]
#                 if j1==j and k1==k: pass
#                 else:
#                     xb = 0 
#                     for b in range(j , k+1):
#                         xb = xb^lst[b-1]
#                         j1,k1 = j,k
#                 if xa==xb: count += 1
#     print(count)


# # # time = 1.98sec
# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0
#     j1 = 0
#     k1 = 0
#     # xa = 0
#     # xb = 0
#     for k in range(2 , n+1):
#         xb = 0
#         for j in range(2 , k+1):
#             xa = 0
#             xb = xb^lst[j-1]
#             for i in range(1 , j):      
#                 # xa = 0
#                 # for a in range(i , j):
#                 #     xa = xa^lst[a-1]
#                 # if j1==j and k1==k: pass
#                 # else:
#                 #     xb = 0
#                 #     for b in range(j , k+1):
#                 #         xb = xb^lst[b-1]
#                 #         j1 = j
#                 #         k1 = k
#                 # if xa==xb: count += 1
#                 xa += xa^lst[i-1]
#                 # if j1 == j : pass
#                 # else:
#                 #     xb = xb^lst[j-1]
#                 #     j1=j
#                 if xa==xb: 
#                     count += 1
#                     print(i,j,k)
#     print(count)


# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0

#     for k in range(2 , n+1):
#         # xb = 0
#         # xa = 0
#         for j in range(2 , k+1):
#             # xa = 0
#             # xb = xb^lst[j-1]
#             if j == k:
#                 for i in range(1 , j):
#                     # print(i,j,k)      
#                     # xa = xa^lst[i-1]

#         # if xb == xa:
#         #     count += 1
#         #     print(i,j,k)
#     print(count)

# from operator import xor
# def findXOR(n): 
#     mod = n % 4; 
  
#     # If n is a multiple of 4 
#     if (mod == 0): 
#         return n; 
  
#     # If n % 4 gives remainder 1 
#     elif (mod == 1): 
#         return 1; 
  
#     # If n % 4 gives remainder 2 
#     elif (mod == 2): 
#         return n + 1; 
  
#     # If n % 4 gives remainder 3 
#     elif (mod == 3): 
#         return 0; 
  
# # Function to return the XOR of elements 
# # from the range [l, r] 
# def findXORFun(l, r): 
#     return (xor(findXOR(l - 1) , findXOR(r))); 


# def findXOR(s , e , lst):
#     if s==e:
#         return (lst[e])
#     return ( lst[s] ^ findXOR(s+1 , e , lst))

# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0
#     j1 = 0
#     k1 = 0 
#     for k in range(2 , n+1):
#         for j in range(2 , k+1):
#             for i in range(1 , j):
#                 xa = 0         
#                 xa = findXOR(i-1 , j-2 , lst)
#                 if j1 == j and k1 == k: pass
#                 else:
#                     # xb = 0
#                     xb = findXOR(j-1 , k-1 , lst)
#                     j1 = j
#                     k1 = k
#                 # print(xa , xb)
#                 if xa==xb:
#                     count+=1
#     print(count)

# def findXOR(s , e , lst):
#     if s==e:
#         return (lst[e])
#     return ( lst[s] ^ findXOR(s+1 , e , lst))

# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0
#     for k in range(2 , n+1):
#         for i in range(1 , k):
#             print(findXOR( i-1 , k-1 , lst))
#             if not findXOR( i-1 , k-1 , lst):
#                 count+=1
#     print(count)


# def findXOR(s , e , lst):
#     if s==e:
#         return (lst[e])
#     return ( lst[s] ^ findXOR(s+1 , e , lst))

# for case in range(int(input())):
#     n = int(input())
#     lst = tuple(map(int , input().split()))
#     count = 0
#     for k in range(2 , n+1):
#         for j in range(2 , k+1):
#             for i in range(1,j):
#                 # print(findXOR( i-1 , k-1 , lst))
#                 if not findXOR( i-1 , k-1 , lst):
#                     count+=1
#     print(count)


# def findXOR(s , e , lst):
#     if s==e:
#         return (lst[e])
#     return ( lst[s] ^ findXOR(s+1 , e , lst))

# for case in range(int(input())):
#     n = int(input())
#     lst = list(map(int , input().split()))
#     count = 0
#     for i in range(1 , n):
#         for k in range(i+1 , n+1):
#             # print(findXOR( i-1 , k-1 , lst))
#             if not findXOR( i-1 , k-1 , lst):
#                 count+=1
#     print(count*2)


# for case in range(int(input())):
#     n = int(input())
#     lst = list(map(int , input().split()))
#     count = 0
#     for i in range(1 , n):
#         for k in range(i+1 , n+1):
#             x = 0
#             for a in range(i , k+1):
#                 x = x^lst[a-1]
#             if x == 0: count += 1
#     print(count*2)



# # # MATRIX APPROACH

# def genMat(arr, res, n):
#     for i in range(0,n):
#         for j in range(0,n):
#             res[i][j] = arr[i] ^ arr[j]
#     return res


# for _t in range(int(input())):
#     n = int(input())
#     aList = list(map(int, input().split()))
#     res = [[0 for _ in range(n)] for _ in range(n)]
#     # res = [[0]*(n-1)]*(n-1)

#     res = genMat(aList, res, n)
#     print(res)
#     # count = 0
#     # for i in res:
#     #     # if i[0] == 0 or i[-1] == 0: count += 1
#     #     if sum(i) != 0: count +=1
#     # print(count) 





# # having XOR of elements as given value m  
# # with O(n) time complexity. 
  
# # Returns count of subarrays of arr  
# # with XOR value equals to m 
# def subarrayXor(arr, n, m):

#     ans = 0 # Initialize answer to be returned 
  
#     # Create a prefix xor-sum array such that 
#     # xorArr[i] has value equal to XOR 
#     # of all elements in arr[0 ..... i] 
#     xorArr =[0 for _ in range(n)] 
  
#     # Create map that stores number of prefix array 
#     # elements corresponding to a XOR value 
#     mp = dict() 
  
#     # Initialize first element  
#     # of prefix array 
#     xorArr[0] = arr[0] 
  
#     # Computing the prefix array. 
#     for i in range(1, n): 
#         xorArr[i] = xorArr[i - 1] ^ arr[i] 
  
#     # Calculate the answer 
#     for i in range(n): 
          
#         # Find XOR of current prefix with m. 
#         tmp = m ^ xorArr[i] 
  
#         # If above XOR exists in map, then there 
#         # is another previous prefix with same 
#         # XOR, i.e., there is a subarray ending 
#         # at i with XOR equal to m. 
#         if tmp in mp.keys(): 
#             ans = ans + (mp[tmp]) 
  
#         # If this subarray has XOR  
#         # equal to m itself. 
#         if (xorArr[i] == m): 
#             ans += 1
  
#         # Add the XOR of this subarray to the map 
#         mp[xorArr[i]] = mp.get(xorArr[i], 0) + 1
  
#     # Return total count of subarrays having  
#     # XOR of elements as given value m 
#     return ans 
  
# # Driver Code 
# # arr = [5,2,7]
# # n = len(arr) 
# # m = arr[2]
  
# # print("Number of subarrays having given XOR is", 
# #                         subarrayXor(arr, n, m))

# for _ in range(int(input())):
#     n = input()
#     *arr , = map(int , input().split())
#     m = 0
#     print(subarrayXor(arr, len(arr), m))

# # final.py

# # ---------final complete--------------

# def reverse_indexed_map(myList):
#     map_of_values = {}
#     for index,val in enumerate(myList):
#         if val not in map_of_values.keys():
#             map_of_values[val] = [index]
#         else:
#             map_of_values[val] += [index]
#     return map_of_values

# def number_of_triplets(indexed_values):
#     num = 0
#     if(0 in indexed_values.keys()):
#         indexed_values[0]+=[-1]

#     for key, indices_list in indexed_values.items():
#         indices_list.sort(reverse=True)
#         length = len(indices_list)-1
#         l = len(indices_list)
#         for i in indices_list:
#             num += (length*i)
#             length -=2
#         num -= int((l*(l-1))/2)
#     return num

# for _ in range(int(input()),0 ,-1):
#     number_of_integers = int(input())
#     *input_list , = map(int , input().split())

#     for index, val in enumerate(input_list):
#         if(index==0): continue
#         else: input_list[index] = input_list[index-1]^(val)

#     temp = reverse_indexed_map(input_list)
#     answer = number_of_triplets(temp)
#     print(answer)







#=====================================================

# def main(inp):
# # inp = [5,2,7]
#     count = 0
#     x1 = 0
#     for i in range(0 , len(inp)-1):
#         xa = 0
#         xb = 0
#         x1 ^= inp[i]
#         for j in range(0 , len(inp)-i-1):
#             xa ^= inp[j]
#         for k in range(len(inp)-i-1 , len(inp)):
#             xb ^= inp[k]
#         if xa == xb:
#             count += 1
#     if x1 != 0: count = 0
#     print(count)
# for case in range(int(input())):
#     main(list(map(int , input().split())))


# def prefixXor(arr):
#     output = [0]
#     temp = 0
#     for item in arr:
#         temp ^= item
#         output.append(temp) 
#     return output

# def prefixXor(arr):
#     output = [0]
#     temp = 0
#     arrout = dict()
#     arrout[0] = []
#     arrout[0].append(0)
#     # for item in arr:
#     for item in range(len(arr)):

#         temp ^= arr[item]
#         output.append(temp)
#         if not output[item+1] in arrout.keys():
#             arrout[output[item+1]] = []
#         arrout[output[item+1]].append(item+1)
#     print(output)
#     return arrout

# # def mapping(arr):
# #     arrout = dict()
# #     for index , item in enumerate(arr):
# #         if not item in arrout.keys():
# #             arrout[item] = []
# #         arrout[item].append(index)
# #     return arrout

# def finalFunc(mapout):
#     count = 0

#     return count 
# print([2,5,7,2,5,7])
# print(prefixXor([2,5,7,2,5,7]))
# # out = prefixXor([2,5,7,2,5,7])
# # print(mapping(out))
# # mapout = mapping(out)
# # print(finalFunc(mapout))


# def prefixXor(arr):
#     output = [0]
#     temp = 0
#     arrout = dict()
#     arrout[0] = []
#     arrout[0].append(0)
#     out = dict()
#     out[0] = [1 , 0]
#     ans = 0

#     for item in range(len(arr)):

#         temp ^= arr[item]
#         output.append(temp)

#         if not output[item+1] in arrout.keys():
#             arrout[output[item+1]] = []
#         arrout[output[item+1]].append(item+1)

#         if not output[item+1] in out.keys():
#             out[output[item+1]] = [0 , 0]
#             # [count(length) , sum to be stored]
#         # out[output[item+1]].append(item+1)
#         count = out[output[item+1]][0]
#         su = out[output[item+1]][1]
#         print(count , su , output[item+1]  , sep = '-')
#         print(out)
#         ans += (count*(item+1)) - count - su
#         count += 1
#         out[output[item+1]][0] = count
#         out[output[item+1]][1] += item+1 
#         # print(arrout)
#     print(output)
#     print(arrout)
#     return ans

# print([2,5,7,2,5,7])
# print(prefixXor([5,2,7]))



# # ============ finally 25-8-19 ===========

def prefixXor(arr):
    output = [0]
    temp = 0
    out = dict()
    out[0] = [1 , 0]
    ans = 0

    for item in range(len(arr)):
        temp ^= arr[item]
        # creating a Prefix array
        output.append(temp)

        # creating base values with help of prefix array
        '''these base values are keys to a dictionary 
           eg {0:[1,0],etc} these base values hold two 
           values to a list 
           1) count = number of breakpoints 
                      to for subarray of ,
           2) sum  = sum of number of elements 
                     in these subarray(s) '''
        if not output[item+1] in out.keys():
            out[output[item+1]] = [0 , 0]


        count = out[output[item+1]][0]
        su = out[output[item+1]][1]

        # print(count,(item+1) , count , su)
        ''' here with the help of this formula
            {ans += count*item - count -sum}
            we find the total number of subarrays
            i.e answer '''
        ans += (count*(item+1)) - count - su
        count += 1

        # here we update the values
        out[output[item+1]][0] = count
        out[output[item+1]][1] += item+1
        # print(out)

    return ans

# driver Function
for _ in range(int(input())):
    N = int(input())
    arr = list(map(int , input().split()))
    print(prefixXor(arr))

# ==============================================================


# def prefixXor(arr):
#     output = [0]
#     temp = ans = 0
#     out = dict()
#     out[0] = [1 , 0]

#     for item in range(len(arr)):
#         temp ^= arr[item]
#         output.append(temp)

#         if not output[item+1] in out.keys():
#             out[output[item+1]] = [0 , 0]

#         count = out[output[item+1]][0]
#         su = out[output[item+1]][1]

#         ans += (count*(item+1)) - count - su
#         count += 1

#         out[output[item+1]][0] = count
#         out[output[item+1]][1] += item+1
        
#     return ans

# for _ in range(int(input())):
#     N = int(input())
#     arr = list(map(int , input().split()))
#     print(prefixXor(arr))