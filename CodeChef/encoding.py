
# def encode(num):
#     # num = list(map(int , str(num)))
#     # out = []
#     # for n in range(len(num)):
#     #     opt = abs(num.index(num[n]) - len(num) + 1 )
#     #     out.append(opt)
#     # sum = 0
#     # for i in range(len(num)):
#     #     sum += num[i]*10**out[i]
#     # return sum

# for i in range(int(input())):
# 	# inputting start and end values here only index 1 is usefull
# 	start = list(map( int , input().split()))
# 	end = list(map( int , input().split()))
# 	output = 0
# 	for num in range(start[1] , end[1]+1):
# # sending single value to function of output  
# 		output += encode(num)
# 	print(output)
	

# 	

# from itertools import groupby
# def encode(num):
# 	out = []
# 	num = list(map(int , str(num)))
# 	for v, g in groupby( enumerate(num), lambda k: k[1] ):
# 	    l = [*g]
# 	    for i in l:
# 	        b = abs(l[0][0]- len(num) + 1)
# 	        out.append(b)
#             # [8, 7, 7, 7, 4, 4, 2, 2, 0]
# 	sum = 0
# 	for i in range(len(num)): sum += num[i]*10**out[i]
# 	return sum

# for i in range(int(input())):
# 	# inputting start and end values here only index 1 is usefull
# 	start = list(map( int , input().split()))
# 	end = list(map( int , input().split()))
# 	output = 0
# 	for num in range(start[1] , end[1]+1):
# # sending single value to function of output  
# 		output += encode(num)
# 	print(output)
	


# # ---------------Works on this computer--------------
# from itertools import groupby
# def encode(num):
#     out = []
#     num = list(map(int , str(num)))
#     for v, g in groupby( enumerate(num), lambda k: k[1] ):
#         l = [*g]
#         for i in l:
#             b = abs(l[0][0]- len(num) + 1)
#             out.append(b)
#             # [8, 7, 7, 7, 4, 4, 2, 2, 0]
#     s = 0
#     value = False 
#     for i in range(len(num)): 
#         if value == num[i]:
#             pass
#         else:
#             s += num[i]*10**out[i]
#             value = num[i]
#     return s

# for i in range(int(input())):
#     # inputting start and end values here only index 1 is usefull
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     output = 0
#     for num in range(start[1] , end[1]+1):
# # sending single value to function of output  
#         output += encode(num)
#     print(output)
#     

# from itertools import groupby
# def encode(num):
#     out , num = [] , list(map(int , str(num)))
#     for v, g in groupby( enumerate(num), lambda k: k[1] ):
#         l = [*g]
#         for i in l:
#             out.append((abs(l[0][0]- len(num) + 1)))
#     s , value = 0 , False
#     for i in range(len(num)): 
#         if value == num[i]: pass
#         else:
#             s += num[i]*10**out[i]
#             value = num[i]
#     return s
    
# for i in range(int(input())):
#     start = list(map( int , input().split()))
#     end , output = list(map( int , input().split())) , 0
#     for num in range(start[1] , end[1]+1):
#         output += encode(num)
#     print(output)
    


# from itertools import groupby
# def encode(num):
#     out , num = [] , list(map(int , str(num)))
#     for _, g in groupby( enumerate(num), lambda k: k[1] ):
#         l = [*g]
#         out.extend([l[0][0]] * len(l))
#     out[:] = [abs(x-len(num)+1) for x in out]
#     s , value = 0 , False
#     for i in range(len(num)): 
#         if value == num[i]: pass
#         else:
#             s += num[i]*10**out[i]
#             value = num[i]
#     return s
    
# for i in range(int(input())):
#     start = list(map( int , input().split()))
#     end , output = list(map( int , input().split())) , 0
#     for num in range(start[1] , end[1]+1):
#         output += encode(num)
#     print(output)


# # Works but gives TLE
# from functools import lru_cache
# from itertools import groupby
# MOD=10**9+7
# @lru_cache(maxsize=1000000)
# def encode(num):
#     out , num = [] , list(map(int , str(num)))
#     for _, g in groupby( enumerate(num), lambda k: k[1] ):
#         l = [*g]
#         out.extend([l[0][0]] * len(l))
#     out[:] = [abs(x-len(num)+1) for x in out]
#     s , value = 0 , False
#     for i in range(len(num)): 
#         if value == num[i]: pass
#         else:
#             s += num[i]*10**out[i]
#             value = num[i]
#     return s%MOD
    
# for i in range(int(input())):
#     start = list(map( int , input().split()))
#     end , output = list(map( int , input().split())) , 0
#     for num in range(start[1] , end[1]+1):
#         output += encode(num)
#     print(output%MOD)

# # TLE + Works
# from functools import lru_cache
# from itertools import groupby
# MOD=10**9+7
# @lru_cache(maxsize=1000000)
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         out , num = [] , list(map(int , str(num)))
#         for _, g in groupby( enumerate(num), lambda k: k[1] ):
#             l = [*g]
#             out.extend([l[0][0]] * len(l))
#         out[:] = [abs(x-len(num)+1) for x in out]
#         s , value = 0 , False
#         for i in range(len(num)): 
#             if value == num[i]: pass
#             else:
#                 s += num[i]*10**out[i]
#                 value = num[i]
#         output += s
#     return output%MOD
    
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))


# # works finer than above

# # TLE + Works
# from itertools import groupby
# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         out , num = [] , list(map(int , str(num)))
#         for _, g in groupby( enumerate(num), lambda k: k[1] ):
#             l = [*g]
#             out.extend([l[0][0]] * len(l))
#         out[:] = [abs(x-len(num)+1) for x in out]
#         s , value = 0 , False
#         for i in range(len(num)): 
#             if value == num[i]: pass
#             else:
#                 s += (num[i]*10**out[i])
#                 value = num[i]
#         output += s%MOD
#     return output%MOD
    
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))


# from itertools import groupby
# MOD=10**9+7

# def encode(start , end):
#     output = 0
#     dct = {}
#     for num in range(start , end):
#         if num in dct: output = dct[num]
#         else:
#             num1 = num
#             out , num = [] , list(map(int , str(num)))
#             for _, g in groupby( enumerate(num), lambda k: k[1] ):
#                 l = [*g]
#                 out.extend([l[0][0]] * len(l))
#             out[:] = [abs(x-len(num)+1) for x in out]
#             s , value = 0 , False
#             for i in range(len(num)): 
#                 if value == num[i]: pass
#                 else:
#                     s += (num[i]*10**out[i])%MOD
#                     value = num[i]
#             output += s%MOD
#             dct[num1] = output%MOD 
#     return output%MOD
    
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))


# # # works rn 20-48
# start = 9
# end = 98
# output = 0
# for num in range(start , end):
    
#     num = list(map(int , str(num)))
#     num +='a'
#     value = False
#     out = 0
#     for y in range(len(num)):
#         if value == num[y]:
#             num[y] = 'i'        
#         else:
#             value = num[y]
#             if num[y] == 'a':
#                 break
#             else:
#                 d = num.index(num[y])
#                 e = abs(d-len(num)+2)
#                 out += num[y]*10**e
#                 num[d] = 'n'
#     output += out
# # print(out)
# print(output)





# # # # ------WORKING AS 20-50--------------
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         num = list(map(int , str(num)))
#         num +='a'
#         value = False
#         out = 0
#         for y in range(len(num)):
#             if value == num[y]:
#                 num[y] = 'i'        
#             else:
#                 value = num[y]
#                 if num[y] == 'a':
#                     break
#                 else:
#                     d = num.index(num[y])
#                     e = abs(d-len(num)+2)
#                     out += num[y]*10**e
#                     num[d] = 'n'
#         output += out
#     return output
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))



# # # # MODULUS ADDED TO PREVIOUS ONE -------BESST  TIME------------

# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         num = list(map(int , str(num)))
#         num +='a'
#         value = False
#         out = 0
#         for y in range(len(num)):
#             if value == num[y]:
#                 num[y] = 'i'        
#             else:
#                 value = num[y]
#                 if num[y] == 'a':
#                     break
#                 else:
#                     d = num.index(num[y])
#                     e = abs(d-len(num)+2)
#                     out += (num[y]*10**e)%MOD
#                     num[d] = 'n'
#         output += out
#     return output % MOD
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))


#     dct = {}
# if num in dct: output = dct[num]
# dct[num1] = output%MOD 


# # # Dictionary ADDED TO PREVIOUS ONE  LOW RATE

# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     dct = {}
#     for num in range(start , end):
#         num1 = num
#         if num in dct: out = dct[num]
#         else:
#             num = list(map(int , str(num)))
#             num +='a'
#             value = False
#             out = 0
#             for y in range(len(num)):
#                 if value == num[y]:
#                     num[y] = 'i'        
#                 else:
#                     value = num[y]
#                     if num[y] == 'a':
#                         break
#                     else:
#                         d = num.index(num[y])
#                         e = abs(d-len(num)+2)
#                         out += (num[y]*10**e)%MOD
#                         num[d] = 'n'
                    
#         output += out
#         dct[num1] = output % MOD 
#     return output % MOD
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))



# # # # dictionary outside dynamic does not works  
# MOD=10**9+7
# dct = {}
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         num1 = num
#         if num in dct: out = dct[num]
#         else:
#             num = list(map(int , str(num)))
#             num +='a'
#             value = False
#             out = 0
#             for y in range(len(num)):
#                 if value == num[y]:
#                     num[y] = 'i'        
#                 else:
#                     value = num[y]
#                     if num[y] == 'a':
#                         break
#                     else:
#                         d = num.index(num[y])
#                         e = abs(d-len(num)+2)
#                         out += (num[y]*10**e)%MOD
#                         num[d] = 'n'                   
#         output += out
#         dct[num1] = output % MOD 
#     return output % MOD
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))



    
# updated lines removed
# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         num = list(map(int , str(num))) + ['a']
#         value , out = False , 0
#         for y in range(len(num)):
#             if value == num[y]: num[y]='a'     
#             else:
#                 value = num[y]
#                 if num[y] == 'a': break
#                 else:
#                     d = num.index(num[y])
#                     e = abs(d-len(num)+2)
#                     out += (num[y]*10**e)%MOD
#                     num[d] = 'a'
#         # start
#         print(out)
#         #end
#         output += out
#     return output % MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))





# # # # ----------------WORKING LOGIC--------------
# num = 1112
# out = num
# num = list(map(int, str(num))) 
# lnum = len(num)
# num = [0,0]+num
# print(num)
# for i in range(lnum):
#     if num[len(num) - i - 1] == num[len(num) - i - 2]:
#         out -= num[len(num) - i - 1]*10**i
# print(out) 


# # # WORKS *HERE and on server too tle  =3.5sec
# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         out = num
#         num = list(map(int, str(num))) 
#         lnum = len(num)
#         num = [0,0]+num
#         # print(num)
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 out -= num[len(num) - i - 1]*10**i
#         output += out%MOD
#     return output%MOD
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))


# # # TLE == 2.5.2secs 
# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         out = num
#         # num = list(map(int, str(num))) 
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         # print(num)
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 out -= int(num[len(num) - i - 1])*10**i
#         output += out%MOD
#     return output%MOD
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split())) 
#     print(encode(start[1], end[1]+1))


# # # TLE -- 3.20secs
# MOD=10**9+7
# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     # start = input().split()
#     # end = input().split()
#     output = 0
#     for num in range(start[1] , end[1]+1):
#     # for num in range(int(start[1]) , int(end[1])+1):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 out -= int(num[len(num) - i - 1])*10**i
#         output += out%MOD
#     print(output%MOD)


# # # TLE == 2.5.2secs 
# # COPIED FROM ABOVE

# MOD=10**9+7
# def encode(start , end):
#     output = 0
    
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 out -= int(num[len(num) - i - 1])*10**i
#         output += out%MOD    
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))




# # # broken code DO NOT TOUCH
# MOD=10**9+7
# def encode(start , end):
#     output = 0

#     # starts with start as base value then 
#     # we need to add or subctract value periodically
#     num = start
#     out = num
#     num = str(num)
#     lnum = len(num)
#     num= '00'+num
#     # this initiallizes value for the function bellow

#     for i in range(lnum):
#         if num[len(num) - i - 1] == num[len(num) - i - 2]:
#             out -= int(num[len(num) - i - 1])*10**i
#     output += out%MOD 
#     diff = start - output
#     # here output = first start no. functioned

#     # this returns the first number functioned 

#     # for num in range(start , end):

#     for j in range(end - start):
#         # output += 1
        
        
           
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))



# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     value = 0
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         num1 = num
#         if num1.count(num1[-1]) < value:
#             output += out%MOD
        
#         else:
#             lnum = len(num)
#             num = '00'+num
#             for i in range(lnum):
#                 if num[len(num) - i - 1] == num[len(num) - i - 2]:  # try to do this outside for loop
#                     out -= int(num[len(num) - i - 1])*10**i
#                     value = num1.count(num1[-1])
#             output += out%MOD    
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))


# # # time = 2.18 sec
# MOD=10**9+7
# def encode(start , end):
#     output = 0
    
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 out -= int(num[len(num) - i - 1])*10**i
#         output += out%MOD    
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))


# MOD=10**9+7
# def encode(start , end):
#     output = 0
    
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 out -= int(num[len(num) - i - 1])*10**i
#         output += out%MOD    
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))

# # # pypy3 works fast 2.2sec+ 3/5 of second tc

# # # # # --NOT--FASTER THAN ABOVE(s) time = 2.24 sec , 2/5
# MOD=10**9+7
# def encFun(out , num):
#     for i in range(len(num)-2):
#                 if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                     out -= int(num[len(num) - i - 1])*10**i
#     return [out , num.count(num[-1])]


# def encode(start , end):
#     output = 0
#     ret_num = 0
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         num = '00'+num
#         if ret_num < num.count(num[-1]):
#             output += out
#             ret_num = num.count(num[-1])
#         else:
#             funout = encFun(out , num)
#             output += funout[0]%MOD 
#             ret_num = funout[1]
  
#     return output%MOD


# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))



# # # works fine
# MOD=10**9+7
# def encode(start , end):
#     output = 0
# # arr = [3,8,8,8,2,2,4,4,2]
#     for arr in range(start , end):
#         arr = list(map(int , str(arr)))
#         ele = 0
#         out = 0
#         sub = len(arr)-1
#         for i in range(sub+1):
#             if arr[i] == ele: arr[i] = 0
#             else:
#                 out += arr[i]*10**(sub-i)
#                 ele = arr[i]
# # print(arr)
#         output+=out%MOD
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))

# # # fastest ----------NOt-----

# MOD=10**9+7
# def encode(start , end):
#     output = 0
#     for arr in range(start , end):
#         arr = list(map(int , str(arr)))
#         ele = 0
#         out = 0
#         sub = len(arr)-1
#         for i in range(sub+1):
#             if arr[i] == ele: 
#                 # arr[i] = 0
#                 pass
#             else:
#                 out += arr[i]*10**(sub-i)
#                 ele = arr[i]
#         output+=out%MOD
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(encode(start[1], end[1]+1))


# time = 2.18 sec

# from math import pow
# MOD=10**9+7
# def encode(start , end):
#     output = 0
    
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 # pow does not work here
#                 out -= int(num[len(num) - i - 1])*10**i
#                 # out -= int(num[len(num) - i - 1])*pow(10 , i)
#         output += out%MOD    
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(int(encode(start[1], end[1]+1)))


# # # # unefficient approach

# from math import pow
# MOD = 10**9+7
# t = int(input())
# for _ in range(t):
#     nl, L = map(int, input().split())
#     nr, R = map(int, input().split())
#     fx = 0
#     for x in range(L, R+1):
#         number_in_place = list(map(int, str(x)))
#         prev_num = next_num = 0
#         n = len(number_in_place)
#         for i in range(n):
#             if i is 0:
#                 prev_num = -1
#             else:
#                 prev_num = number_in_place[i-1]
#             if i is n-1:
#                 next_num = -1
#             else:
#                 next_num = number_in_place[i+1]
#             if number_in_place[i] is not prev_num and number_in_place[i] is next_num:
#                 fx += number_in_place[i] * pow(10, n-i-1)
#                 continue
#             if number_in_place[i] is prev_num and number_in_place[i] is not next_num:
#                 continue
#             if number_in_place[i] is prev_num and number_in_place[i] is next_num:
#                 continue
#             fx += number_in_place[i] * pow(10, n-i-1)
#     print(int(fx)%MOD)


# # using GENERATORS
# # time = 2.18 sec

# # # from math import pow
# MOD=10**9+7
# def encode(start , end):
#     # output = 0
    
#     # for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 # pow does not work here
#                 out -= int(num[len(num) - i - 1])*10**i
#                 # out -= int(num[len(num) - i - 1])*pow(10 , i)
#         output += out%MOD    
#     return output%MOD

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     # print(int(encode(start[1], end[1]+1)))
#     output = 0
#     for num in range(start[1] , end[1]+1):
        
#         output += next(encode) 




# # # idea FAILED!!!!!!
# from math import pow
# MOD=10**9+7
# def encode(start , end):
#     output = 0
    
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 # pow does not work here
#                 out -= int(num[len(num) - i - 1])*10**i
#                 # out -= int(num[len(num) - i - 1])*pow(10 , i)
#         output += out%MOD    
#     return output%MOD
# def encode(start , end):
# 	outArr = []
# 	for num in range(start , end):
# 		outArr.append(num)
# 	return encodeFun(outArr)

# def encodeFun(arr):
# 	output = 0
# 	for num in arr:
# 		out = num
#         num = str(num)
#         lnum = len(num)
#         num = '00'+num
#         for i in range(lnum):
#             if num[len(num) - i - 1] == num[len(num) - i - 2]:
#                 # pow does not work here
#                 out -= int(num[len(num) - i - 1])*10**i
#                 # out -= int(num[len(num) - i - 1])*pow(10 , i)
#         output += out%MOD    

# for case in range(int(input())):
#     start = list(map( int , input().split()))
#     end = list(map( int , input().split()))
#     print(int(encode(start[1], end[1]+1)))



# MOD=10**9+7
# # main func
# def encode(start , end):
#     output = 0
#     for num in range(start , end):
#         out = num
#         num = str(num)
#         lnum = len(num)
#         if len(set(num))==lnum: pass
#         # if len(set(num))==lnum: continue
#         else:
#             num = '00'+num
#             for i in range(lnum):
#                 if num[i]==num[i-1]: pass
#                 elif num[len(num) - i - 1] == num[len(num) - i - 2]:
#                     out -= int(num[len(num) - i - 1])*10**i
#         output += out%MOD    
#     return output%MOD

# # driver function
# for case in range(int(input())):
#     *_ , start = map(int , input().split())
#     *_ ,  end = map(int , input().split())
#     print(encode(start, end+1))

# # ---------final complete--------------

def encodeFun(num):
    s = str(num)
    l = len(s)
    d = {}
    j = 0
    Sum = 0

    for i in range(1, l):
        if(s[i] == s[i-1]): continue
        else:
            x = int(s[j])*(10**(l-j-1))
            Sum += x
            j = i
    Sum += int(s[j])*(10**(l-j-1))

    return Sum


for _ in range(int(input())):
    l, lr = map(int, input().split())
    r, rr = map(int, input().split())
    s = 0
    for i in range(lr, rr+1):
        s+=encodeFun(i)
    print(s%(10**9 + 7))