a=[int(x) for x in input().split(' ')]
n=len(a)

for i in range(n-1,-1,-1):
    if a[i]>0:
        for j in range(i+1,n):
            if(a[j]<0):
                if abs(a[i])==abs(a[j]): a[i]=a[j]=0
                elif(abs(a[j])<abs(a[i])): a[j]=0
                else:
                    a[i]=0
                    break

rem=[]
for i in range(0,n):
    if a[i]!=0: rem.append(a[i])

if len(rem)==0:
    print(-1)
else:
    out=''
    for x in rem:
        out += str(x) + ' '
    print(out)