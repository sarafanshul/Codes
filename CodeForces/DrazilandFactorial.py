# fact_dict = {
# 			0:1, 1:1, 2:2, 3:6, 
# 			4:24, 5:120, 6:720, 7:5040, 
# 			8:40320, 9:362880
# 			}

# _ = input()
# n = input().lstrip('0')

# a1 = 1
# for i in n:
# 	a1 *= fact_dict[int(i)]

# print(a1)

# a2 = ''
# while a1 > 1:

# 	print(a1 , a2)

# 	if a1 % fact_dict[2]==0:
# 		a1 /= fact_dict[2]
# 		a2 += ''.join('2')

# 	elif a1 % fact_dict[3]==0:
# 		a1 /= fact_dict[3]
# 		a2 += ''.join('3')

# 	elif a1 % fact_dict[4]==0:
# 		a1 /= fact_dict[4]
# 		a2 += ''.join('4')

# 	elif a1 % fact_dict[5]==0:
# 		a1 /= fact_dict[5]
# 		a2 += ''.join('5')

# 	elif a1 % fact_dict[6]==0:
# 		a1 /= fact_dict[6]
# 		a2 += ''.join('6')

# 	elif a1 % fact_dict[7]==0:
# 		a1 /= fact_dict[7]
# 		a2 += ''.join('7')

# 	elif a1 % fact_dict[8]==0:
# 		a1 /= fact_dict[8]
# 		a2 += ''.join('8')

# 	elif a1 % fact_dict[9]==0:
# 		a1 /= fact_dict[9]
# 		a2 += ''.join('9')

# 	else: break

# print(a2)

fct_lt = ["","","2","3","223","5","53","7","7222","7332"]

n = int(input())
s = input().replace('0' , '')

ans = ''

for i in s:
	ans += ''.join(fct_lt[int(i)])


*ans , = map(int, ans)
ans.sort(reverse = True)

print(*ans , sep = '')




