#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define pb push_back
#define INF 99999999
#define MAXN 100
using namespace std;

//We DFS through connections, sum the costs through them, and subtract the minimum of the costs from the sum
//This gives us the total cost we can evade
//Subtracting these value from the total gives us the desired answer
//Time Complexity - O(V+E) (DFS time complexity)
//Where V = number of vertices and E = number of edges, or connections in this case

vector<int> connections[MAXN];
int costs[MAXN];
bool visited[MAXN];

int dfs(int v1,int& minm)
{
    if(visited[v1]) return 0;
    visited[v1]=1;
    minm=min(minm,costs[v1]);
    int tot=costs[v1];
    FOR(i,0,connections[v1].size())
    {
        tot+=dfs(connections[v1][i],minm);
    }
    return tot;
}

int main()
{
    int V,c,v1,v2,tot=0; cin >> V >> c;
    FOR(i,0,V) { cin >> costs[i]; tot+=costs[i]; }

    FOR(i,0,c)
    {
        cin >> v1 >> v2;
        connections[v1-1].pb(v2-1);
    }

    int maxm,curr,minm;
    FOR(i,0,V)
    {
        if(!visited[i]) 
        {
            maxm=-1,minm=INF; curr=dfs(i,minm);
            maxm=max(maxm,curr-minm);
            tot-=maxm;
        }
    }
    cout << tot << '\n';

    return 0;
}
