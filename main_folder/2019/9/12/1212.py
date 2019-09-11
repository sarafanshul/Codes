n=input()
sum=""
for i in range(0,len(n)):
    if n[i]=="0":
        sum+="000"
    elif n[i]=="1":
        sum+="001"
    elif n[i]=="2":
        sum+="010"
    elif n[i]=="3":
        sum+="011"
    elif n[i]=="4":
        sum+="100"
    elif n[i]=="5":
        sum+="101"
    elif n[i]=="6":
        sum+="110"
    elif n[i]=="7":
        sum+="111"
if sum[0]=="0":
    if sum[1]=="0":
        print(sum[2:])
    else:
        print(sum[1:])
else:
    print(sum)
