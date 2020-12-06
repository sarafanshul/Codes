
for case in range(int(input())):
    R, C, Q = map(int, input().split())
    rows = [0 for _ in range(R)]
    cols = [0 for _ in range(C)]

    for _ in range(Q):
        x, y = map(int, input().split())
        rows[x-1] += 1
        cols[y-1] += 1
        rows[x-1] %= 2
        cols[y-1] %= 2

    odds = 0
    zer = cols.count(0)
    ons = cols.count(1)

    for e in rows:
        if e:
            odds += zer
        else:
            odds += ons

    print(odds)

# TLE 80 pts
# for case in range(int(input())):
#     R , C , Q = map(int , input().split())
#     rows = [0 for _ in range(R)]
#     cols = [0 for _ in range(C)]

#     for _ in range(Q):
#         x , y = map(int , input().split())
#         rows[x-1] += 1
#         cols[y-1] += 1
    
#     odds = 0
#     for i in rows:
#         for j in cols:
#             if (i+j)%2 != 0: odds += 1
    
#     print(odds)

# for case in range(int(input())):
#     R, C, Q = map(int, input().split())
#     rows = [0 for _ in range(R)]
#     cols = [0 for _ in range(C)]

#     for _ in range(Q):
#         x, y = map(int, input().split())
#         rows[x-1] += 1
#         cols[y-1] += 1

#     odds = 0


#     *rows ,= map(lambda x: x%2 , rows)
#     *cols ,= map(lambda x: x%2 , cols)

#     # print(rows , cols , rows , cols , sep = '\n')

#     for e in rows:
#         if e : odds += cols.count(0)
#         else: odds += cols.count(1)

#     # for i in rows:
#     #     for j in cols:
#     #         if (i+j) % 2 != 0:
#     #             odds += 1

#     print(odds)


# for case in range(int(input())):
#     R, C, Q = map(int, input().split())
#     rows = [0 for _ in range(R)]
#     cols = [0 for _ in range(C)]

#     for _ in range(Q):
#         x, y = map(int, input().split())
#         rows[x-1] += 1
#         cols[y-1] += 1
#         rows[x-1] %= 2
#         cols[y-1] %= 2

#     odds = 0
#     zer = cols.count(0)
#     ons = cols.count(1)

#     for e in rows:
#         if e:
#             odds += zer
#         else:
#             odds += ons

#     print(odds)
    
