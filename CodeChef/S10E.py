# for _ in range(int(input())):
#     N = int(input())
#     *a , = map(int , input().split())

#     # minprice = 1e9
#     # ans = 1

#     # tmp = 0
#     # for i in range(1 ,int(N)):
#     #     if tmp == 5:            
#     #         tmp -= 1
#     #         if a[i] < minprice: 
#     #             ans +=1 
#     #             minprice = a[i]
#     #     minprice = min(a[i], minprice)
#     #     tmp += 1

#     # print(ans)
#     ans = 1
#     minprice = min(a[1:6])
#     for i in range(5 ,N):
#         if a[i] < minprice : ans += 1 
#         minprice = min(a[i] , minprice)
    
#     print(ans)

for _ in range(int(input())):
    N = int(input())
    *a, = map(int, input().split())

    good = 0
    arr = []
    for i in range(N):
        n = a[i]

        if len(arr) == 0:
            arr.append(n)
            good += 1
        
        elif len(arr)< 5:
            minel = min(arr)
            if n < minel:
                good += 1
            arr.append(n)
        
        else:
            minel = min(arr)
            ds = arr[::-1]
            ds.pop()
            arr = ds[::-1]
            if n < minel:
                good += 1
            arr.append(n)
    print(good)

