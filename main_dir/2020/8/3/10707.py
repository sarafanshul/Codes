list=[int(input()) for i in range(5)]
costx=list[4]*list[0]
if list[2]>=list[4]:
    costy=list[1]
else:
    costy=(list[4]-list[2])*list[3]+list[1]
if costx>costy:
    print(costy)
else:
    print(costx)
