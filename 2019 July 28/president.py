votes = [int(x) for x in ["0"] + input().split(' ')]
times = [int(x) for x in ["0"] + [input().split(' ') + ["999999999"]][0]]
inps = [int(x) for x in input().split(' ')]
inps = [x for x in enumerate(inps)]
inps = sorted(inps, key = lambda x: x[1])
n = len(inps)
anss = [0 for x in range(n)]

summ = 0
curr = 0
for i in range(n):
    while(curr < len(times) and times[curr+1]<=inps[i][1]):
        curr += 1
        summ += votes[curr]
        if summ == curr-summ:
            anss[inps[i][0]] = votes[curr]
        elif summ < curr/2:
            anss[inps[i][0]] = 0
        else:
            anss[inps[i][0]] = 1

print(" ".join([str(x) for x in anss]))
