n = int(input())
*pi , = map(int , input().split())
*prize , = map(int , input().split())


total = [0 , 0 , 0 , 0 , 0]

temp = 0
for i in pi:
	temp += i
	if temp >= prize[-1]:
		total[4] += (temp // prize[-1])
		temp -= prize[-1]*(temp // prize[-1])
		

	if temp >= prize[-2]:	
		total[3] += temp // prize[-2]
		temp -= prize[-2]*(temp // prize[-2])
		

	if temp >= prize[-3]:
		total[2] += temp // prize[-3]
		temp -= prize[-3]*(temp // prize[-3])
		

	if temp >= prize[-4]:
		total[1] += temp // prize[-4]
		temp -= prize[-4]*(temp // prize[-4])
		

	if temp >= prize[-5]:
		total[0] += temp // prize[-5]
		temp -= prize[-5]*(temp // prize[-5])
		


print(*total )
print(temp)