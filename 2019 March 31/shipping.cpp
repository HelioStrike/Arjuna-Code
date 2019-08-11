#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pii pair<int,int>
#define pb push_back
#define fs first
#define sd second
#define MAXN 110
#define INF 999999999
using namespace std;

int n,e,k,v1,v2,s,src,dest,ans=INF;
vector<pii> g[MAXN];
int vis[MAXN];

void dfs(int v,int c, int cc)
{
    if(vis[v] || c>k+1) return;
    if(v==dest)
    {
        ans=min(ans,cc);
        return;
    }
    vis[v]=1;
    FOR(i,0,g[v].size()) dfs(g[v][i].fs,c+1,cc+g[v][i].sd);
    vis[v]=0;
}

int main()
{
    cin>>n>>e;
    FOR(i,0,e)
    {
        cin>>v1>>v2>>s;
        g[v1].pb({v2,s});
    }
    cin>>src>>dest>>k;
    dfs(src,0,0);
    if(ans==INF) cout<<-1<<'\n';
    else cout<<ans<<'\n';

    return 0;
}