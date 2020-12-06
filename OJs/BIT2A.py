for _ in range(int(input())):
    N = int(input())
    *A ,= map(int , input().split())
    
    # # A  = [0] + A
    B = []

    # for i in range(1 , N):
    #     temp = A[i] - A[i-1]

    #     if temp:
    #         B.append(N-i)
    #     else: B.append(0)

    # print(*B)
    # preArr = [A[0]]
    # for i in range(1 , N):  
    #     preArr.append(A[i]+preArr[i-1])
    
    # print(preArr)

    # preArr = [A[-1]-A[-2]]
    for i in range(N-1 , 0 , -1):  
        # preArr.append(A[i] - A[i-1])
        if (A[i] - A[i-1]):
            B.append(N-i)
        else: B.append(0)
    
    # print(preArr)
    print(*(B[::-1]+[0]))
