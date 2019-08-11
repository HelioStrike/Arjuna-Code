a=[int(x) for x in input().split(' ')]
k=int(input())

a=sorted(a)
a=[0]+a
n=len(a)

ans=0
while(len(a)>1):
    c=a[1]
    r=k-c
    a.pop(1)

    l=0
    h=len(a)
    while(l<h):
        m=(l+h)//2
        if(a[m]==r): break
        elif(a[m]<r): l=m
        else: h=m-1
    
    if m!=0:
        a.pop(m)
    ans+=1

print(ans)
    

