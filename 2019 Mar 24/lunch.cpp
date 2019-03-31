#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int n,ans,counts[2];

int main()
{
    cin>>n;
    int b[n],s[n];
    FOR(i,0,n) cin>>b[i];
    FOR(i,0,n) cin>>s[i],counts[s[i]]++;

    FOR(i,0,n)
    {
        if(counts[b[i]]==0)
        {
            ans=n-i; break;
        }
        counts[b[i]]--;
    }

    cout<<ans<<'\n';

    return 0;
}