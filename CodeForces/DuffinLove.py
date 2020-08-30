num = int(input())

mn , out = 2 , 1

while mn * mn <= num:
    if num % mn == 0:
        out *= mn

        while num % mn == 0:
            num /= mn
    mn += 1

if num > 1:
    out *= num

print(int(out))