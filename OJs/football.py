# for cases in range(int(input())):
# 	for variables in range(int(input())):
# 		goals = list(map(int , input().split()))
# 		fouls = list(map(int , input().split()))
# 		out = []
# 		# out , num , a = [] , len(goals) ,0
# 		num = len(goals)
# 		a = 0
# 		while a<num:
# 			g = goals[a]
# 			f = fouls[a]
# 		# for g , f in goals , fouls:
# 			if g ==0: 
# 				out1 = 0
# 			else:
# 				out1 = (g*20) - (f*10)
# 				if out1 <= 0: 
# 					out1 = 0
# 				out.append(out1)
# 				a += 1
# 		print(max(out))
# 		del(out)

# for cases in range(int(input())):
# 	v = input()
# 	# for variables in range(int(input())):
# 	goals = list(map(int , input().split()))
# 	fouls = list(map(int , input().split()))
# 	out , num , a = [] , len(goals) , 0
# 	# zero while loop error 
# 	if num:
# 		while a<num:
# 			g = goals[a]
# 			f = fouls[a]
# 		# for g , f in goals , fouls:
# 			if g ==0: out1 = 0
# 			else:
# 				out1 = (g*20) - (f*10)
# 				if out1 <= 0: out1 = 0
# 				out.append(out1)
# 				a += 1
# 	print(max(out))
# 	del(out)

for cases in range(int(input())):
	v = input()
	goals = list(map(int , input().split()))
	fouls = list(map(int , input().split()))
	out , num = [] , len(goals)
	for a in range(len(goals)):
		g , f = goals[a] , fouls[a]
		if g == 0: out1 = 0
		else:
			out1 = (g*20) - (f*10)
			if out1 <= 0: out1 = 0
		out.append(out1)
	print(max(out))