a=int(input())
list1=[0]*(a+1)
for i in range(2,a+1):

    list1[i]=list1[i-1]+1
    if i%3==0 and list1[i]>list1[i//3]+1:
        list1[i]=list1[i//3]+1
    if i%2==0 and list1[i]>list1[i//2]+1:
        list1[i]=list1[i//2]+1
print(list1[-1])
