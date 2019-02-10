#include <bits/stdc++.h>
#define ll long long
#define MAXV 100
#define INF 99999
#define FOR(i,a,b,c) for(ll i = (a); i < (b); i += (c))
using namespace std;

ll g[MAXV][MAXV][2]; list<ll> lv; vector<ll> vis(MAXV);

int dfs(ll curr, ll V)
{
    if(lv.empty()) return 0;
    ll maxi=0,c;
    FOR(i,0,V,1) if(curr!=i&&g[curr][i][0]!=INF&&!g[curr][i][1]&&!vis[i])
    { lv.remove(i),g[curr][i][1]=1,g[i][curr][1]=1,vis[curr]=1;c=dfs(i,V); if((c+g[curr][i][0])>maxi)maxi=c+g[curr][i][0];
    g[curr][i][1]=0,g[i][curr][1]=0,lv.push_back(i);vis[i]=0;}
    return maxi;
}

int main()
{
    ll V,E,e1,e2,curr,a,ma,m=0,c; cin >> V >> E; 
    FOR(i,0,V,1) FOR(j,0,V,1) g[i][j][0]=INF,g[i][j][1]=0;
    FOR(i,0,V,1) lv.push_back(i);
    FOR(i,0,E,1) cin >> e1 >> e2 >> a, g[e1-1][e2-1][0]=a, g[e2-1][e1-1][0]=a;
    FOR(i,0,V,1) { 
        FOR(i,0,V,1) vis[i]=0;
        lv.remove(i); ma=dfs(i,V); vis[i]=1; if(ma>m) m=ma; lv.push_back(i); vis[i]=0; cout << ma << '\n';
    }
    cout << m << '\n';
    return 0;
}
/*
5 7
1 3 10
1 2 20
1 4 20
2 4 30
2 3 20
3 4 40
4 5 20
*/