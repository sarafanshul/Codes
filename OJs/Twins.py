n = int(input())
*coins , = map(int , input().split())

srtd_coins = sorted(coins , reverse = True)
summ = sum(coins)

splt = summ/2

count = 0
temp = 0
for coin in srtd_coins:
	count += 1
	temp += coin
	if temp > splt:
		break

print(count)