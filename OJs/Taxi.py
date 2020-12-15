
# n = int(input())
# *si , = map(int , input().split())

# taxi = 0

# taxi += si.count(4)

# ones = si.count(1)
# two = si.count(2)
# three = si.count(3)

# if three == ones:
# 	taxi += three
# 	three = ones = 0

# elif three > ones:
# 	taxi += ones
# 	three -= ones
# 	ones = 0

# else:
# 	taxi += three
# 	ones -= three
# 	three = 0

# if three:
# 	taxi += three
# 	three = 0


# taxi += two//2

# two %= 2
# if two :
# 	if ones >= 2 :
# 		taxi += 1
# 		two = 0
# 		ones -= 2
# 	else:
# 		taxi += 1


# print(taxi)
# if ones//4 > 0:
# 	taxi += ones//4
# 	ones %= 4

# if ones:
# 	taxi += 1
# print(taxi)


n = int(input())
*si , = map(int , input().split())

if sum(si) <= 4:
	print(1)

else:	
	cnt = [0 , 0 , 0 , 0 , 0]

	cnt[1] = si.count(1)
	cnt[2] = si.count(2)
	cnt[3] = si.count(3)
	cnt[4] = si.count(4)

	total = cnt[4] + cnt[3] + cnt[2]//2

	# cnt[2] //= 2

	cnt[1] -= cnt[3]

	if cnt[2]%2 == 1:
		total += 1
		cnt[1] -= 2

	if cnt[1] > 0:
		total += (cnt[1]+3)//4

	print(total)
