l , r , k = map(int , input().split())
cur , f = 1 , 1
while( cur <= r):
    if(cur >= l) :
        print(cur , sep = ' ')
        f = 0
    cur *= k
if(f):
    print(-1)
