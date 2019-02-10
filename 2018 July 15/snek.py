n = int(input())

for i in range(n):
    out = ""
    for j in range(i+1):
        j += 1

        sum = 0
        for k in range(n, 5 - j, -1):
            sum += k

        if(j%2 == 1):
            out += str(sum - n + i + 1) + " "
        else:
            out += str(sum - i + n) + " "

    print(out)
