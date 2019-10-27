from sys import stdin
from re import findall

for l in stdin:
    print(len(findall(r'[a-zA-Z]+', l)))
