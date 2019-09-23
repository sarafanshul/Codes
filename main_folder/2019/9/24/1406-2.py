from sys import stdin
input = stdin.readline
stack1 = list(input().replace('\n',''))
stack2 = []
for T in range(int(input())):
    c = input().replace('\n', '')
    if c == "L":
        if stack1:
            stack2.append(stack1.pop())
    elif c == "D":
        if stack2:
            stack1.append(stack2.pop())
    elif c == "B":
        if stack1:
            stack1.pop()
    else:
        stack1.append(c[2])
print(''.join(stack1+stack2[::-1]))
