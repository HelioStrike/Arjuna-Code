#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
#define pb push_back
#define fs first
#define sd second
#define MAXN 100
using namespace std;

int n,e,k,v1,v2,s,ans;
vector<pii> g[MAXN];
bool vis[MAXN];

void dfs(int v)
{
    if(vis[v]) return;
    vis[v]=1; ans++;
    FOR(i,0,g[v].size()) if(g[v][i].sd<=k) dfs(g[v][i].fs);
}

int main()
{
    cin>>n>>e;
    FOR(i,0,e)
    {
        cin>>v1>>v2>>s;
        g[v1-1].pb({v2-1,s});
        g[v2-1].pb({v1-1,s});
    }
    cin>>n>>k;
    FOR(i,0,n)
    {
        cin>>e; dfs(e-1);
    }
    cout<<ans<<'\n';

    return 0;
}