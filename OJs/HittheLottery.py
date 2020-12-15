money = int(input())

bills = 0

if money >= 100:
	bills += money//100
	money %= 100

if money >= 20:
	bills += money//20
	money %= 20

	
if money >= 10:
	bills += money//10
	money %= 10

if money >= 5:
	bills += money//5
	money %= 5

if money < 5:
	bills += money

print(bills) 