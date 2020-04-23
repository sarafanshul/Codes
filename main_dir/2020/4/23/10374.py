from sys import stdin, stdout

def main():
    n = int(stdin.readline().rstrip())

    for i in range(n):
        stdin.readline()
        m = int(stdin.readline().rstrip())
        d = {}
        for j in range(m):
            cand = stdin.readline().rstrip()
            party = stdin.readline().rstrip()
            d[cand] = [0, party]
            
        m = int(stdin.readline().rstrip())
        for j in range(m):
            cand = stdin.readline().rstrip()
            if cand in d:
                d[cand][0] += 1

        maximum = max(d, key = d.get)
        maxval = d[maximum][0]
        if sum([1 for key in d if d[key][0] == maxval]) < 2:
            stdout.write(str(d[maximum][1]) + "\n")
        else:
            stdout.write("tie\n")
        if i < n - 1: stdout.write("\n")

if __name__ == "__main__":
    main()
