n = int(input())
mapp = [0 for i in range(100)]

for i in range(n):
    s = input().split(' ')
    summ = 0
    for val in s[:-1]:
        summ += int(val)
        mapp[summ] += 1

print(n-max(mapp))