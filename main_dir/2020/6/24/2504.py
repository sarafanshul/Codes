bracket_dict = {'(':')', '[':']'}
stack = []
flag = True
s = input()
for i in range(len(s)):
    #print stack
    if s[i] in ['(', '[']:
        stack.append(s[i])
    else:
        try:
            pop = stack.pop()
        except:
            print("0")
            flag = False
            break
        temp = 0
        while pop!='[' and pop!='(':
            temp += pop
            pop = stack.pop()
        if s[i]==bracket_dict[pop]:
            if s[i]==')':
                if temp==0:
                    stack.append(2)
                else:
                    stack.append(2*temp)
            else:
                if temp==0:
                    stack.append(3)
                else:
                    stack.append(3*temp)
        else:
            print("0")
            flag = False
            break
if flag:
    try:
        print(sum(stack))
    except:
        print("0")
