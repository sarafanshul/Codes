# 1) lower all characters
inpstr = input().lower()
# 2) delete the vowels
vow = {'a','e','i','o','u','y'}
inpset = set(inpstr)
uni = list(inpset&vow)
# print(uni)
for voe in uni:
	inpstr = inpstr.replace(voe , '')
out = '.'.join(inpstr)
print('.',out , sep = '')
