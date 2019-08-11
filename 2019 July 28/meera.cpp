#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n,k,x,minm,ans;

int main()
{
    cin>>n>>k;
    cin>>x; minm=x;
    FOR(i,1,n) {
        cin>>x,minm=min(x,minm);
        ans=max(ans,x-minm);
    }
    cout<<ans*k<<'\n';

    return 0;
}