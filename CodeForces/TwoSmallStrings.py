# ========== asnhul ===========
# n = int(input())
# s = input()
# t = input()


# raf = {'ab':['acb','bac','bca','cba'],
# 		'ac':['abc','bca','cab','cba'],
# 		'ba':['abc','acb','bca','cab'],
# 		'bc':['acb','bac','cab','cba'],
# 		'ca':['abc','acb','bac','cba'],
# 		'cb':['abc','bac','bca','cab'],
# 		'aa':['abc','acb','bac',
# 				'bca','cab','cba'],
# 		'bb':['abc','acb','bac',
# 				'bca','cab','cba'],
# 		'cc':['abc','acb','bac',
# 				'bca','cab','cba'],
# 		}

# # print(raf[s] , raf[t])

# list_s = raf[s]
# list_t = raf[t]

# repeat = 0

# if s == 'aa' or s == 'bb' or s == 'cc':
# 	repeat += 1

# if t == 'aa' or t == 'bb' or t == 'cc':
# 	repeat += 1 # for checking

# if repeat == 2:
# 	print('abc'*n)

# elif repeat == 1:
# 	# repeat + simple
# 	if s == 'aa' or s == 'bb' or s == 'cc':
# 		ret = raf[t][1]
# 		print(ret*n)
# 	else:
# 		ret = raf[s][1]
# 		print(ret*n)

# else:
# 	# simple + simple
# 	

refr = {"ab":"acb", "ac":"abc", "ba":"abc", "bc":"acb", "ca":"acb", "cb":"abc"}

n = int(input())
s = input()
t = input()

print('YES')

if s[0] == s[1]:
	if t[0] == t[1]:
		ret = 'abc'
	else:
		ret = refr[t]

	print(ret*n)

else:

	ret = refr[s]
	if t[0] == t[1]:
		print(ret*n)

	elif t[0] == s[0] and t[1] != s[1]:
		print(s[1]*n + t[1]*n + s[0]*n)

	elif t[1] == s[1] and t[0] != s[0]:
		print(s[1]*n + s[0]*n + t[0]*n)

	elif t[0] == s[1] and t[1] == s[0]:
		char = ['a' , 'b' , 'c']
		char.remove(s[0])
		char.remove(s[1])

		ret = s[0] + char[0] + s[1]
		ret_rev = s[1] + char[0] + s[0]

		print((ret+ret_rev)*(n//2) + ret*(n%2))

	else:
		print(ret*n)
