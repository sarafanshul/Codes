s = []
files = {}
folders = {}

for _ in range(101):
    try: a = input()
    except EOFError : break
    s.append(a)
    b = a.split("\\")
    for i in range(2 ,len(b)):
        path = tuple(b[:i])
        if(path not in files):
            files[path] = 0
            folders[path] = set()
        files[path] += 1
        for j in range(i + 1 ,len(b)):
            path2 = tuple(b[:j])
            folders[path].add(path2)

print(f'{max([len(x) for x in folders.values()])} {max(files.values())}')


