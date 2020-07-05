str=input()
cnt=0
for i in range(len(str)):
    if(('A' <= str[i]) and (str[i] <= 'C')):
        cnt+=3
    elif(('D' <= str[i]) and (str[i] <= 'F')):
        cnt+=4;
    elif(('G' <= str[i]) and (str[i] <= 'I')):
        cnt+=5;
    elif(('J' <= str[i]) and (str[i] <= 'L')):
        cnt+=6;
    elif(('M' <= str[i]) and (str[i] <= 'O')):
        cnt+=7;
    elif(('P' <= str[i]) and (str[i] <= 'S')):
        cnt+=8;
    elif(('T' <= str[i]) and (str[i] <= 'V')):
        cnt+=9;
    elif(('W' <= str[i]) and (str[i] <= 'Z')):
        cnt+=10;
print(cnt)
