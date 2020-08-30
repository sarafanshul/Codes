# DP = []
# month = [31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31]

# def isleap(year):
# 	if (year % 4) == 0: 
# 		if (year % 100) == 0: 
# 			if (year % 400) == 0: 
# 				return True
# 			else: 
# 				return False
# 		else: 
# 			 return True
# 	else: 
# 		return False

# # ul CalcDayNumFromDate(ui y, ui m, ui d)
# # {
# #   m = (m + 9) % 12;
# #   y -= m / 10;
# #   ul dn = 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d - 1);

# #   return dn;
# # }

# # // ----------------------------------------------------------------------
# # // Given year, month, day, return the day of week (string).
# # // ----------------------------------------------------------------------
# # std::string CalcDayOfWeek(int y, ul m, ul d)
# # {
# #   std::string day[] = {
# #     "Wednesday",
# #     "Thursday",
# #     "Friday",
# #     "Saturday",
# #     "Sunday",
# #     "Monday",
# #     "Tuesday"
# #   };

# #   ul dn = CalcDayNumFromDate(y, m, d);

# #   return day[dn % 7];
# # }

# def CalcDayNumFromDate(y ,m ,d):
# 	m = (m +9) %12
# 	y -= m //10
# 	dn = 365*y + y//4 - y//100 + y//400 + (m*306 + 5)//10 + (d-1)
# 	return dn%7

# def calc(m ,y):
# 	count = 0
# 	for i in range(1 ,y):
# 		for j in range(1 ,13):
# 			# first friday and second last sunday
# 			days = month[j-1]
# 			if isleap(i) and j == 2:
# 				days += 1
# 			coll = [[0 ,0] ,0]
# 			for k in range(1 ,days+1):
# 				if CalcDayNumFromDate(i ,j ,k) == 2: # first friday
# 					coll[0][0] ,coll[0][1] = k , k +10
# 					break
# 			# flag = False
# 			for k in range(days , 0 , -1):
# 				if CalcDayNumFromDate(i ,j ,k) == 4: # penultimate sunday
# 					# if not flag:
# 					# 	flag = True
# 					# elif flag:
# 					# 	coll[1] = k
# 					# 	break
# 					# print(k)
# 					coll[1] = k-6
# 					break
# 			# print(coll)
# 			if coll[0][1] >= coll[1]:
# 				count += 1

# 	for j in range(1 ,m + 1):
# 		days = month[j-1]
# 		if isleap(y) and j == 2:
# 			days += 1
# 		coll = [[0 ,0] ,0]
# 		for k in range(1 ,days+1):
# 			if CalcDayNumFromDate(y ,j ,k) == 2: # first friday
# 				coll[0][0]  ,coll[0][1] = k , k +10
# 				break
# 		for k in range(days , 0 , -1):
# 			if CalcDayNumFromDate(y ,j ,k) == 4: # penultimate sunday
# 				coll[1] = k-6
# 				break
# 		if coll[0][1] >= coll[1]:
# 			count += 1
# 		# print(coll)
# 	return count



# if __name__ == '__main__':
# 	# print(CalcDayNumFromDate(2020 , 2 ,10)%7)
# 	print(calc(2 ,2020) - calc(10 ,2009))

# only feburary

# from collections import defaultdict

# DP = defaultdict( lambda : -1)
# month = [31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31]

# def isleap(year):
# 	if (year % 4) == 0: 
# 		if (year % 100) == 0: 
# 			if (year % 400) == 0: 
# 				return True
# 			else: 
# 				return False
# 		else: 
# 			 return True
# 	else: 
# 		return False

# def CalcDayNumFromDate(y ,m ,d):
# 	m = (m +9) %12
# 	y -= m //10
# 	dn = 365*y + y//4 - y//100 + y//400 + (m*306 + 5)//10 + (d-1)
# 	return dn%7

# def calc(m ,y):
# 	count = 0
# 	for i in range(1 ,y):
# 		if DP[i] == -1: # not done
# 			tmp_count = 0
# 			for j in range(1 ,13):
# 				# first friday and second last sunday
# 				days = month[j-1]
# 				if isleap(i) and j == 2: days += 1
# 				coll = [0,0]
# 				for k in range(1 ,days+1):
# 					if CalcDayNumFromDate(i ,j ,k) == 2: # first friday
# 						coll[0] = k +10
# 						break
# 				for k in range(days , 0 , -1):
# 					if CalcDayNumFromDate(i ,j ,k) == 4: # penultimate sunday
# 						coll[1] = k-6
# 						break
				
# 				if coll[0] >= coll[1]: 
# 					tmp_count += 1
# 					print(f'{k} / {j} / {i}')

# 			DP[i] = tmp_count
# 		count += DP[i]
		
# 	for j in range(1 ,m + 1):
# 		days = month[j-1]
# 		if isleap(y) and j == 2:
# 			days += 1
# 		coll = [[0 ,0] ,0]
# 		for k in range(1 ,days+1):
# 			if CalcDayNumFromDate(y ,j ,k) == 2: # first friday
# 				coll[0]=k +10
# 				break
# 		for k in range(days , 0 , -1):
# 			if CalcDayNumFromDate(y ,j ,k) == 4: # penultimate sunday
# 				coll[1] = k-6
# 				break
# 		if coll[0]>= coll[1]: # no update dp
# 			count += 1
# 		# print(coll)
# 	return count



# if __name__ == '__main__':
# 	# print(CalcDayNumFromDate(2020 , 2 ,10)%7)
# 	print(calc(2 ,20200) - calc(10 ,2009))


from collections import defaultdict

DP = defaultdict( lambda : -1)
month = [31 ,28 ,31 ,30 ,31 ,30 ,31 ,31 ,30 ,31 ,30 ,31]

def isleap(year):
	if (year % 4) == 0: 
		if (year % 100) == 0: 
			if (year % 400) == 0: return True
			else: return False
		else: return True
	else: return False

def CalcDayNumFromDate(y ,m ,d):
	m = (m +9) %12
	y -= m //10
	dn = 365*y + y//4 - y//100 + y//400 + (m*306 + 5)//10 + (d-1)
	return dn%7

def calc(m ,y):
	count = 0
	for i in range(1 ,y):
		if DP[i] == -1: # not done
			tmp_count = 0
			# for j in range(1 ,13):
			if True :
				j = 2
				# first friday and second last sunday
				days = month[j-1]
				if isleap(i) and j == 2: days += 1
				coll = [0,0]
				for k in range(1 ,days+1):
					if CalcDayNumFromDate(i ,j ,k) == 2: # first friday
						coll[0] = k +10
						break
				for k in range(days , 0 , -1):
					if CalcDayNumFromDate(i ,j ,k) == 4: # penultimate sunday
						coll[1] = k-6
						break
				
				if coll[0] >= coll[1]: 
					tmp_count += 1
					# print(f'{coll[0]} - {coll[1]} / {j} / {i}')

			DP[i] = tmp_count
		count += DP[i]
		
	# for j in range(1 ,m + 1):
	if True :
		j = 2
		days = month[j-1]
		if isleap(y) and j == 2:
			days += 1
		coll = [0,0]
		for k in range(1 ,days+1):
			if CalcDayNumFromDate(y ,j ,k) == 2: # first friday
				coll[0]=k +10
				break
		for k in range(days , 0 , -1):
			if CalcDayNumFromDate(y ,j ,k) == 4: # penultimate sunday
				coll[1] = k-6
				break
		if coll[0]>= coll[1]: # no update dp
			count += 1
			# print(f'{coll[0]} - {coll[1]} / {j} / {y}')
	return count



if __name__ == '__main__':
	# print(CalcDayNumFromDate(2020 , 2 ,10)%7)
	print(calc(2 ,2020) - calc(2 ,2020)) # try 2019