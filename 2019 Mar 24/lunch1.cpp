#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n,c,ans,x,y;

int main()
{
    cin>>n; int a[n+1],b[n+1];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];
    a[n]=b[n]=100000000;
    sort(a,a+n); sort(b,b+n);
    while(x<n || y<n)
    {
        if(a[x]==b[y]) x++,y++,ans++;
        else if(a[x]>b[y]) y++;
        else if(a[x]<b[y] || y==n) x++;
    }
    cout<<(n-ans)<<'\n';

    return 0;
}