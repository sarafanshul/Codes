import time
start = time.time()
m=n=0
for i in range(3, 1000000, 2):
	t=i;c=0
	while i != 1:
		i=i/2 if i%2==0 else i*3+1;c+=1
	if c>m:m=c;n=t
print(n)
end = time.time() - start
print(end)


