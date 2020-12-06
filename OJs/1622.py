from itertools import permutations as pm
a = input()
b = sorted(set(map("".join ,pm(a ,len(a)))))
print(len(b) ,*b ,sep = "\n")