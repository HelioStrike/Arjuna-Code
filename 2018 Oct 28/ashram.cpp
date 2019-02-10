#include <bits/stdc++.h>
#define ll long long
#define MAXV 100
#define INF 99999
#define FOR(i,a,b,c) for(int i = (a); i < (b); i += (c))
using namespace std;

int g[MAXV][MAXV];

int maxKey(int key[], vector<bool>vis, int V)
{
    int max=-1, max_index;
    FOR(i,0,V,1) if(vis[i]==0&&key[i]>max) max=key[i],max_index=i;
    return max_index; 
}

int mst(int V)
{
    int parent[V]; int key[V]; vector<bool> vis(V);
    int maxi=-1,tot;    

    FOR(i,0,V,1)
    {
        FOR(x,0,V,1) key[x]=-1,vis[x]=false;
        key[i]=0,parent[i]=-1;
        FOR(j,0,V-1,1)
        {
            int u=maxKey(key,vis,V); vis[u]=true;
            FOR(v,0,V,1) if(g[u][v]!=INF&&vis[v]==false&&g[u][v]>key[i]) parent[v]=u, key[v]=g[u][v];
        }
        tot = 0;
        FOR(x,0,V,1)
        {
            if(i!=x) tot+=key[x];
        }
        if(tot>maxi) maxi=tot;
    } 
    return maxi;
}

int main()
{
    int V,E,e1,e2,curr,m,a; cin >> V >> E; 
    FOR(i,0,V,1) FOR(j,0,V,1) g[i][j]=INF;
    FOR(i,0,E,1) cin >> e1 >> e2 >> a, g[e1-1][e2-1]=a, g[e2-1][e1-1]=a;
    m = mst(V);
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