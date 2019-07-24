dic={"black":0, "brown":1,"red":2, "orange":3,"yellow":4,"green":5,"blue":6,"violet":7,"grey":8,"white":9}
a=input()
b=input()
c=input()
z=str(dic[a])+str(dic[b])
dic2={"black":1,"brown":10,"red":100, "orange":1000,"yellow":10000,"green":100000,"blue":1000000,"violet":10000000,"grey":100000000,"white":1000000000}
print(int(z)*dic2[c])
