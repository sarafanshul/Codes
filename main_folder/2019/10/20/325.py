from sys import stdin
from re import findall

for l in tuple(stdin):
    if l[0] == '*':
        break
    
    l = l.rstrip().lstrip()
    f = findall(r'^([-\+]?[0-9]+)((\.[0-9]+[eE][-\+]?[0-9]+)|(\.[0-9]+)|([eE][-\+]?[0-9]+))$', l)
    
    if (f):
        print ("%s is legal." % l)
    else:
        print("%s is illegal." % l)
        
