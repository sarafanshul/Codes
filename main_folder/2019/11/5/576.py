from sys import stdin
from re import findall

for l in tuple(stdin):
    if l == "e/o/i\n":
        break
    
    [a, b, c] = l.rstrip().split('/')
    if len(findall(r'[aeiouy]+', a)) != 5:
        print(1)
    elif len(findall(r'[aeiouy]+', b)) != 7:
        print(2)
    elif len(findall(r'[aeiouy]+', c)) != 5:
        print(3)
    else:
        print('Y')
