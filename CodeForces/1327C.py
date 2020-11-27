n, m, _ = map(int, input().split())

print(2 * (n - 1) + (n + 1) * (m - 1))
print("U" * (n - 1) + "L" * (m - 1), end="")
for i in range(n):
    if i != 0:
        print("D", end="")
    if i % 2 == 0:
        print("R" * (m - 1), end="")
    else:
        print("L" * (m - 1), end="")