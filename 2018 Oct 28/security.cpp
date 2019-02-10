#include <bits/stdc++.h>
#define ll long long
#define MAXV 1000
#define FOR(i,a,b,c) for(ll i = (a); i < (b); i += (c))
using namespace std;

vector<ll> g[MAXV], vis(MAXV);

void dfs(ll curr, ll level, ll V, ll &t, ll &r)
{
    if(curr==V-1) { t+=level,r++; return;}
    vis[curr]=1;
    FOR(i,0,g[curr].size(),1) if(!vis[g[curr][i]]) dfs(g[curr][i],level+1,V,t,r);
    vis[curr]=0;
}

int main()
{
    ll V,E,e1,e2,curr,t=0,r=0; cin >> V >> E; 
    FOR(i,0,E,1) cin >> e1 >> e2, g[e1-1].push_back(e2-1);
    dfs(0,1,V,t,r);
    cout << (t-V) << " " << r << '\n';
    return 0;
}