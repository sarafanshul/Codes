a=input()
b=input()
hourA=int(a[0]+a[1])
hourB=int(b[0]+b[1])
minutesA=int(a[3]+a[4])
minutesB=int(b[3]+b[4])
secondA=int(a[6]+a[7])
secondB=int(b[6]+b[7])

if secondB>secondA:
    secondC=secondB-secondA
else:
    secondC=60-(secondA-secondB)
    minutesB-=1

if minutesB>minutesA:
    minutesC=minutesB-minutesA
else:
    minutesC=60-(minutesA-minutesB)
    hourB-=1

hourC=hourB-hourA
if hourC<10 and hourC>0:
    hourC="0"+str(hourC)
elif hourC<0:
    hourC="23"
else:
    hourC=str(hourC)
if minutesC<10:
    minutesC="0"+str(minutesC)
else:
    minutesC=str(minutesC)
if secondC<10:
    secondC="0"+str(secondC)
else:
    secondC=str(secondC)
print("%s:%s:%s"%(hourC,minutesC,secondC))
