

def binCoeff(n, k):
    if(k > n - k):
        k = n - k
    res = 1

    for i in range(k):
        res = res * (n - i)
        res = res / (i + 1)

    return res


for case in range(int(input())):

    n, k = map(int, input().split())
    *a, = map(int, input().split())

    b = sorted(a)

    lem = b[k-1]

    if b.count(lem) == 1:
        print(1)
    else:
        try:
            lmt = b[:k].index(lem)
        except:
            print(1)

        else:
            N = b.count(lem)

            if k-lmt <= 0 or N <= k-lmt or N == k:
                print(1)

            else:
                print(int(binCoeff(N, k-lmt)))
