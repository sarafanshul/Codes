def radix_sort(input, radix):

    m = len(str(max(input)))  #가장 큰 수의 길이를 잰다.
    for i in range(1, m+1):
        buckets = [[] for _ in range(radix)]
        base = 10 ** (i-1)
        for n in input:
            buckets[(n//base) % radix].append(n)
        input.clear()
        for bucket in buckets:
            for n in bucket:
                input.append(n)

    list=[([e for b in buckets for e in b])]
    for i in range(len(list)):
        print(list[i])
a=int(input())
list=[]
list2=[]
for i in range(a):
    list2.append(int(input()))
radix_sort(list2, 10)
