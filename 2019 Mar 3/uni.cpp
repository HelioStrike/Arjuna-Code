#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXU 100
using namespace std;

int nu,nmedals[MAXU];

int main()
{
    int n,ans; scanf("%d",&n);
    int a[n]; FOR(i,0,n) scanf("%d",&a[i]),nmedals[a[i]]++,nu=max(nu,a[i]);
    FOR(i,0,n)
    {
        ans=-1;
        FOR(j,i+1,n) if(nmedals[a[j]]>nmedals[a[i]]) { ans=a[j]; break; }
        printf("%d ",ans); 
    }
    printf("\n");

    return 0;
}