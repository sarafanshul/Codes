# # using array for traversal example may it work
# len = len
# N , Q = map(int , input().split())
# #edg = [[prev , new] , ..]
# edg = [[]for i in range(N-1)]

# for i in range(N-1):
#     x , y = map(int , input().split())
#     if x > y : x , y = y , x

#     edg[i] = [x , y]

# # edg.sort(key = lambda t : t[0] < t[1])
# edg.sort(key=lambda t: t[0])
# childNode = [[] for i in range(N+1)]
# travED = [0 for i in range(N+1)]
# travED[1] = 1
# s = len(edg)

# # for _ in range(len(edg)-1 , -1 , -1):
# while s != 0:
#     for i in range(len(edg)):
#         # print(i)
#         if len(edg[i]):
#             if travED[edg[i][0]] == 1:
#                 childNode[edg[i][0]].append(edg[i][1])
#                 travED[edg[i][1]] = 1
#                 # try:
#                 #     it = edg.index(edg[i])
#                 # except ValueError : 
#                 #     it = -1
#                 # if it != -1:
#                 #     edg.remove(it)
#                 try:
#                     # edg.remove(edg[i])
#                     edg[i] = []
#                 except ValueError: pass
#                 s -= 1
            
#             elif travED[edg[i][1]] == 1:
#                 childNode[edg[i][1]].append(edg[i][0])
#                 travED[edg[i][0]] = 1
#                 # try:
#                 #     it = edg.index(edg[i])
#                 # except ValueError:
#                 #     it = -1
#                 # if it != -1:
#                 #     edg.remove(it)
#                 try:
#                     # edg.remove(edg[i])
#                     edg[i] = []
#                 except ValueError:pass
#                 s -= 1

# bctinp = map(int ,input().split())
# # bctpr = [0 for i in range(N+1)]
# bctpr = [[0 , 0]]
# for bct in bctinp: bctpr.append([bct , 0])

# # for i in range(N):
# #     bctpr[i+1] = [bctinp[i] , 0]
# # temp = [el for el in childNode if len(el)]
# # childNode = temp
# # print(childNode)
# # print(bctpr)

# for _ in range(Q , 0 , -1):
#     for i in range(1 ,N+1):
#         if len(childNode[i]):
#             for j in range(len(childNode[i])):
#                 # print(i , j)
#                 bctpr[childNode[i][j]][1] += bctpr[i][0]
            
#             bctpr[i][0] = bctpr[i][1]
#             bctpr[i][1] = 0
        
#         else:
#             bctpr[i][0] += bctpr[i][1]
#             bctpr[i][1] = 0
    
#     for i in range(N+1):
#         bctpr[i][0] += bctpr[i][1]
#         bctpr[i][1] = 0
    
#     inp = input().split()

#     # print(bctpr)
#     if inp[0] == '+': bctpr[int(inp[1])][0] += int(inp[2])
#     else: print(bctpr[int(inp[1])][0] + bctpr[int(inp[1])][1])

# MAXX = 1e12
# __author__ = '''

#   _                            _   _  _____ _    _ _    _ _      
#  | |             _       /\   | \ | |/ ____| |  | | |  | | |     
#  | |__  _   _   (_)     /  \  |  \| | (___ | |__| | |  | | |     
#  | '_ \| | | |         / /\ \ | . ` |\___ \|  __  | |  | | |     
#  | |_) | |_| |   _    / ____ \| |\  |____) | |  | | |__| | |____ 
#  |_.__/ \__, |  (_)  /_/    \_\_| \_|_____/|_|  |_|\____/|______|
#          __/ |                                                   
#         |___/                                                    

# '''
# if __author__:
#     # using array for traversal example may it work
#     len = len # fast (accrd to me)
#     N, Q = map(int, input().split())
#     #edg = [[prev , new] , ..]
#     ansarr = []
#     out = []
#     edg = [[]for i in range(N-1)]
#     childNode = [[] for i in range(N+1)]
#     travED = [0 for i in range(N+1)]# traversed NODES
#     travED[1] = 1

#     for i in range(N-1):
#         x, y = map(int, input().split())
#         if x > y:edg[i] = [y , x]
#         else: edg[i] = [x , y]

#     edg.sort(key=lambda t: t[0])
#     s = len(edg)

#     # forming all child nodes
#     while s:
#         for i in range(len(edg)):
#             # print(i)
#             if len(edg[i]):
#                 if travED[edg[i][0]] == 1:
#                     childNode[edg[i][0]].append(edg[i][1])
#                     travED[edg[i][1]] = 1
#                     try:
#                         edg[i] = []
#                     except ValueError:
#                         pass
#                     s -= 1

#                 elif travED[edg[i][1]] == 1:
#                     childNode[edg[i][1]].append(edg[i][0])
#                     travED[edg[i][0]] = 1
#                     try:
#                         edg[i] = []
#                     except ValueError:
#                         pass
#                     s -= 1

#     print(childNode)
#     print(travED)
#     bctinp = map(int, input().split())
#     # bctpr = [0 for i in range(N+1)] # let it be empty
#     bctpr = [[0, 0]]
#     for bct in bctinp: bctpr.append([bct, 0])

#     # for i in range(N):
#     #     bctpr[i+1] = [bctinp[i] , 0]
#     # temp = [el for el in childNode if len(el)]
#     # childNode = temp
#     # print(childNode)
#     # print(bctpr)

#     for _ in range(Q):
#         # starting with base querry
#         for i in range(1, N+1):
#             if len(childNode[i]):
#                 for j in range(len(childNode[i])):
#                     # print(i , j)
#                     bctpr[childNode[i][j]][1] += bctpr[i][0]

#                 bctpr[i][0] = bctpr[i][1]
#                 bctpr[i][1] = 0

#             else:
#                 bctpr[i][0] += bctpr[i][1]
#                 bctpr[i][1] = 0

#         for i in range(N+1):
#             bctpr[i][0] += bctpr[i][1]
#             bctpr[i][1] = 0

#         inp = input().split()

#         # print(bctpr)
#         # updating wrt Q
#         if inp[0] == '+':
#             # updating v->k
#             bctpr[int(inp[1])][0] += int(inp[2])
#         else:
#             # for ? input()
#             print(bctpr[int(inp[1])][0] + bctpr[int(inp[1])][1])

# len = len
# bctpr = [[0, 0]]
# N, Q = map(int, input().split())

# childNode = [[] for _ in range(N+1)]
# for _ in range(N-1):
#     x, y = map(int, input().split())
#     if x > y: childNode[y].append(x)
#     else: childNode[x].append(y)

# for item in childNode: 
#     if len(item): item.sort()

# bctinp = map(int, input().split())
# for bct in bctinp: bctpr.append([bct, 0])

# for _ in range(Q):
#     for i in range(1, N+1):
#         if len(childNode[i]):
#             for j in range(len(childNode[i])):
#                 bctpr[childNode[i][j]][1] += bctpr[i][0]

#             bctpr[i][0] = bctpr[i][1]
#             bctpr[i][1] = 0

#         else:
#             bctpr[i][0] += bctpr[i][1]
#             bctpr[i][1] = 0

#     for i in range(N+1):
#         bctpr[i][0] += bctpr[i][1]
#         bctpr[i][1] = 0

#     inp = input().split()

#     if inp[0] == '+': bctpr[int(inp[1])][0] += int(inp[2])
#     else: print(bctpr[int(inp[1])][0] + bctpr[int(inp[1])][1])



# from collections import defaultdict

# class Graph:
#     def __init__(self):
#         self.graph = defaultdict(list)
#         self.DFSgraph = []

#     # function to add an edge to graph
#     def addEdge(self, u, v):
#         self.graph[u].append(v)

#     # A function used by DFS
#     def DFSUtil(self, v, visited):
#         # if v >= len(visited): return
#         visited[v] = True
#         # print(v, end=' ')
#         self.DFSgraph += [v]

#         # Recur for all the vertices
#         # adjacent to this vertex
#         for i in self.graph[v]:
#             # print(visited, i, self.graph[v])
#             if visited[i] == False:
                
#                 self.DFSUtil(i, visited)

#     # The function to do DFS traversal. It uses
#     # recursive DFSUtil()
#     def DFS(self, v):

#         # Mark all the vertices as not visited
#         # visited = [False] * (len(self.graph))
#         # print((max(self.graph.values())))
#         visited = [False]*((max(self.graph.values()))[0]+1)

#         # Call the recursive helper function
# #         # to print DFS traversal
# #         self.DFSUtil(v, visited)


# # g = Graph()


# # # g.addEdge(0, 1)
# # # g.addEdge(0, 2)
# # # g.addEdge(1, 2)
# # # g.addEdge(2, 0)
# # # g.addEdge(2, 3)
# # # g.addEdge(3, 3)

# # N , Q = map(int , input().split())
# # for i in range(N-1):
# #     x , y = map(int , input().split())
# #     if x > y : g.addEdge(y , x)
# #     else: g.addEdge(x , y)

# # # print(g.graph)
# # # print("Following is DFS from (starting from vertex 2)")
# # g.DFS(1)
# # # print(g.DFSgraph)
# # *arr ,= map(int , input().split())
# # tesarr = [0]
# # for i in g.DFSgraph:
# #     tesarr.append(arr[i-1])
# # print(tesarr)

# from collections import deque

# def main():

#     def update(x , delta , q1 , BIT):
#         while x<=(n+q1+4):
#             BIT[x]+=delta
#             x+=x&-x
    
#     def query(x ,BIT):
#         s=0
#         while x>0:
#             s+=(BIT[x])
#             x=x-(x&-x)
#         return s

#     def dfs(s , bm , visited , m ,queries , BIT):
#         visited[s]=True
        
#         for i in m[s].keys():
#             if i in bm:
#                 bm[i]+=m[s][i]
#                 update(i+1,m[s][i] , q1 , BIT)
#             else:
#                 bm[i]=m[s][i]
#                 update(i+1,m[s][i] , q1 , BIT)
#         if s in queries:
#             if ladj[s]==0:
#                 for i in queries[s]:
#                     ans[i]=query(levels[s]+i+2 , BIT)
#             else:
#                 for i in queries[s]:
#                     if (levels[s]+i+1) in bm:
#                         ans[i]=bm[levels[s]+i+1]
#                     else:
#                         ans[i]=0
#         for i in adj[s]:
#             if not visited[i]:
#                 dfs(i , bm , visited , m , queries , BIT)
#         for i in m[s].keys():
#             bm[i]-=m[s][i]
#             update(i+1,-m[s][i] , q1 , BIT)

#     n,q1=map(int,input().split())
#     adj=[[] for i in range(n)]
#     ladj=[0]*n
#     bm=dict()
#     BIT=[0]*(n+q1+5)
    
#     for i in range(n-1):
#         a,b=map(int,input().split())
#         adj[a-1].append(b-1)
#         adj[b-1].append(a-1)
    
#     q=deque()
#     q.append(0)
#     levels=[0]*n
#     visited=[False]*n
#     visited[0]=True
#     mil=0

#     while q:
#         s=q.popleft()
#         for i in adj[s]:
#             if not visited[i]:
#                 q.append(i)
#                 visited[i]=True
#                 levels[i]=levels[s]+1
#                 mil=max(levels[i],mil)
#                 ladj[s]+=1

#     for i in range(n):
#         levels[i]=mil-levels[i]

#     ans=[-1]*q1

#     m=[dict() for i in range(n)]
#     v=list(map(int,input().split()))

#     for i in range(n):
#         m[i][levels[i]]=v[i]

#     queries=dict()
#     for i in range(q1):
#         l=list(input().split())
#         l1=int(l[1])-1

#         if l[0]=="?":
#             if l1 in queries:
#                 queries[l1].append(i)
#             else:
#                 queries[l1]=[i]
#         else:
#             l1=int(l[1])
#             l2=int(l[2])
#             m[l1-1][levels[l1-1]+i+1]=l2

#     visited=[False]*n

#     dfs(0 , bm , visited ,m , queries , BIT)

#     for i in range(q1):
#         if ans[i]!=-1:      
#             print(ans[i])


# if __name__ == "__main__":
#     map = map
#     len = len
#     range = range 
#     main()

from collections import deque

def main():

    def update(x, delta):

        while x <= (n+q1+4):
            BIT[x] += delta
            x += x & -x

    def query(x):
        s = 0
        while x > 0:
            s += (BIT[x])
            x = x-(x & -x)
        return s

    def dfs(s):
        visited[s] = True

        for i in m[s].keys():
            if i in bm:
                bm[i] += m[s][i]
                update(i+1, m[s][i])
            else:
                bm[i] = m[s][i]
                update(i+1, m[s][i])

        if s in queries:

            if ladj[s] == 0:
                for i in queries[s]:
                    ans[i] = query(levels[s]+i+2)
            else:
                for i in queries[s]:
                    if (levels[s]+i+1) in bm:
                        ans[i] = bm[levels[s]+i+1]
                    else:
                        ans[i] = 0

        for i in adj[s]:
            if not visited[i]:
                dfs(i)

        for i in m[s].keys():
            bm[i] -= m[s][i]
            update(i+1, -m[s][i])

    n, q1 = map(int, input().split())

    adj = [[] for i in range(n)]
    ladj = [0]*n
    bm = dict()
    BIT = [0]*(n+q1+5)

    for i in range(n-1):
        a, b = map(int, input().split())
        adj[a-1].append(b-1)
        adj[b-1].append(a-1)

    q = deque()
    q.append(0)
    levels = [0]*n
    visited = [False]*n
    visited[0] = True
    mil = 0

    while q:
        s = q.popleft()
        for i in adj[s]:

            if not visited[i]:
                q.append(i)
                visited[i] = True
                levels[i] = levels[s]+1
                mil = max(levels[i], mil)
                ladj[s] += 1

    for i in range(n):
        levels[i] = mil-levels[i]

    ans = [-1]*q1
    m = [dict() for i in range(n)]
    v = list(map(int, input().split()))

    for i in range(n):
        m[i][levels[i]] = v[i]

    queries = dict()

    for i in range(q1):
        l = list(input().split())
        l1 = int(l[1])-1

        if l[0] == "?":
            if l1 in queries:
                queries[l1].append(i)
            else:
                queries[l1] = [i]
        else:
            l1 = int(l[1])
            l2 = int(l[2])
            m[l1-1][levels[l1-1]+i+1] = l2
    visited = [False]*n

    dfs(0)

    for i in range(q1):
        if ans[i] != -1:
            print(ans[i])

if __name__ == '__main__':
    main()
