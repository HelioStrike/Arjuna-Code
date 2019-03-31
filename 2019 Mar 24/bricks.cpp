#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
#define sd second
using namespace std;

int n,k,c,s,ans;
map<int,int> m;

int cmp(const pii& a, const pii&b) { return a.sd-b.sd;}

int main()
{
    cin>>n;
    FOR(i,0,n)
    {
        cin>>k; s=0;
        FOR(i,0,k-1) cin>>c,s+=c,m[s]++;
        cin>>c;
    }

    ans=(*max_element(m.begin(),m.end(),cmp)).sd;
    cout<<(n-ans)<<'\n';

    return 0;
}