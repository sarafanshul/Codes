graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}
def dfs_recursive(graph,vertex,visited=[]):
    if vertex not in visited:
        visited.append(vertex)

        for node in graph[vertex].difference(visited):
            dfs_recursive(graph,node,visited)
    return visited

def dfs_iterator(graph,start):
    visited=[]
    stack=[start]

    while stack:
        vertex=stack.pop()
        if vertex not in visited:
            visited.append(vertex)
            stack.extend(graph[vertex].difference(visited))
    return visited

def dfs_paths(graph,start,goal):
    stack=[(start,[start])]
    while stack:
        (vertex,path)=stack.pop()

        for next in graph[vertex].difference(path):
            if next==goal:
                print(path+[next])
            else:
                stack.append((next,path+[next]))

print(dfs_recursive(graph,'A'))
print(dfs_iterator(graph,"A"))
dfs_paths(graph,"A","F")
