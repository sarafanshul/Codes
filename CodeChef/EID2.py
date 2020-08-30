
# def compare(a, b):
# 	if a > b:
# 		return 1
# 	if a < b:
# 		return -1
# 	return 0

# def mainFunc(a1 ,a2 ,a3 ,c1 ,c2 ,c3):
# 	if (compare(a1 ,a2) == compare(c1 ,c2) 
# 		and compare(a3 ,a2) == compare(c2 ,c3)
# 		and compare(a1 ,a3) == compare(c1 ,c3)):

# 		return 'FAIR'
	
# 	return 'NOT FAIR'

# for case in range(int(input())):

# 	 print(map(int , input().split()))

# 	
# def compare(a, b):
# 	if a > b:
# 		return 1
# 	if a < b:
# 		return -1
# 	return 0

# def mainFunc(a1 ,a2 ,a3 ,c1 ,c2 ,c3):
# 	if (compare(a1 ,a2) == compare(c1 ,c2) 
# 		and compare(a2 ,a3) == compare(c2 ,c3)
# 		and compare(a1 ,a3) == compare(c1 ,c3)):

# 		return 'FAIR'
	
# 	return 'NOT FAIR'

# for case in range(int(input())):
# 	a1 ,a2 ,a3 ,c1 ,c2 ,c3 =  map(int , input().split())
# 	if ((a1>a2 and c1>c2) or (a1<a2 and c1<c2) or(a1==a2 and c1==c2)) and ((a3>a2 and c3>c2) or (a3<a2 and c3<c2) or (a3==a2 and c3==c2)) and ((a1>a3 and c1>c3) or (a1<a3 and c1<c3) or (a1==a3 and c1==c3)): print("FAIR")
#     else: print("NOT FAIR")


# c = 0
# for case in range(int(input())):
#     a1 ,a2 ,a3 ,c1 ,c2 ,c3 =  map(int , input().split())
#     if (a1==a2 and c1==c2):
#         c+=1
#     if (a1==a3 and c1==c3):
#         c+=1
#     if (a3==a2 and c3==c2):
#         c+=1        
#     if (a1>a2 and c1>c2):
#         c+=1 
#     if (a1>a3 and c1>c3):
#         c+=1    
#     if (a2>a3 and c2>c3):
#         c+=1 
#     if (a1<a2 and c1<c2):
#         c+=1 
#     if (a1<a3 and c1<c3):
#         c+=1    
#     if (a2<a3 and c2<c3):
#         c+=1 
#     if c==3:
#         print("FAIR")
#     else:
#         print("NOT FAIR")

for _ in range(int(input())):
    c=0
    a1,a2,a3,c1,c2,c3 = map(int,input().split())
    if (a1==a2 and c1==c2):
        c+=1
    if (a1==a3 and c1==c3):
        c+=1
    if (a3==a2 and c3==c2):
        c+=1        
    if (a1>a2 and c1>c2):
        c+=1 
    if (a1>a3 and c1>c3):
        c+=1    
    if (a2>a3 and c2>c3):
        c+=1 
    if (a1<a2 and c1<c2):
        c+=1 
    if (a1<a3 and c1<c3):
        c+=1    
    if (a2<a3 and c2<c3):
        c+=1 
    if c==3:
        print("FAIR")
    else:
        print("NOT FAIR")