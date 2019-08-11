a=[int(x) for x in input().split(' ')]
k=int(input())

a=sorted(a)
n=len(a)

ans=0
l=0
r=len(a)-1
while(l<=r):
    if(l==r):
        l+=1
        ans+=1
    elif(a[l]+a[r]>k):
        r-=1
        ans+=1
    else:
        l+=1
        r-=1
        ans+=1

print(ans)
    

