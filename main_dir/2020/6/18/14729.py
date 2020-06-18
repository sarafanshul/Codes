import sys
list1=[]
for _ in range(int(input())):
    list1.append(float(sys.stdin.readline()))
list1=sorted(list1)
for i in range(7):
    print("%.3f"%list1[i])
