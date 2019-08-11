#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
using namespace std;

int n,k,x,y;
pii m,o;
map<int,int> mp;

bool cmp(const pii& a,const pii& b) { return a.second<b.second; }

int main()
{
    cin>>n>>k;
    FOR(i,0,n) cin>>x>>y,mp[x]=max(mp[x],y);
    m=*max_element(mp.begin(),mp.end(),cmp);
    mp[m.first]=0;
    o=*max_element(mp.begin(),mp.end(),cmp);
    cout<<m.second+o.second<<'\n';

    return 0;
}