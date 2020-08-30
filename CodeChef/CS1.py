# #27-7-19 Codechef math
# final = []
# for i in range(int(input())):
#     ln , test , test_count = int(input()) , (input()).split(' ') , 0
#     for index in range(0, len(test)):
#         for j in range(index + 1, len(test)):
#             a , b = test[index] , test[j]
#             test_prod , prod_sum = int(a) * int(b) , 0        
#             while test_prod:
#                 prod_sum += (test_prod % 10)
#                 test_prod = test_prod//10
#             if test_count < prod_sum: test_count = prod_sum
#     final.append(test_count)
# print(*final , sep='\n')



# final = []
# for i in range(int(input())):
#     ln , test , test_count = int(input()) , input().split() , 0
#     for index in range(0, len(test)):
#         for sub in range(index + 1, len(test)):
#             a , b = test[index] , test[sub]
#             test_prod , prod_sum = int(a) * int(b) , 0        
#             prod_sum = sum(map(int, str(test_prod)))
#             if test_count < prod_sum: test_count = prod_sum
#     final.append(test_count)
# print(*final , sep='\n')


# sum of digits in one line -- 
'''
 			sum(map(int, str(number)))
'''

# shortest 9 lines

# for i in range(int(input())):
#     ln , test , test_count = int(input()) , input().split() , 0
#     for index in range(0, len(test)):
#         for sub in range(index + 1, len(test)):
#             a , b = test[index] , test[sub]
#             test_prod , prod_sum = int(a) * int(b) , 0        
#             prod_sum = sum(map(int, str(test_prod)))
#             if test_count < prod_sum: test_count = prod_sum
#     print(test_count)

# from multiprocessing import Process
# def func(ln , test , test_count):

#     for index in range(0, len(test)):
#         for sub in range(index + 1, len(test)):
#             a , b = test[index] , test[sub]
#             test_prod , prod_sum = int(a) * int(b) , 0        
#             prod_sum = sum(map(int, str(test_prod)))
#             if test_count < prod_sum: test_count = prod_sum
#     return print(test_count)

# if __name__ == '__main__':
# 	process = []
# 	for i in range(int(input())):
# 		a = Process(target = func , args = (int(input()) , input().split() , 0) ) 
# 		process.append(a)

# 	for p in process:
# 		p.start()
# 	for p in process:
# 		p.join()
