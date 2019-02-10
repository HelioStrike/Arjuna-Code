#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXN 100
#define INF 99999999
using namespace std;

//Standard DFS approach. Map makes it easy to setup edges as it takes O(1) time to detect main roads.
//Alternate approaches include BellmanFord algorithm and FloydWarshall algorithm.

map<pair<int,int>,int> m;

vector<int> vec[MAXN];
bool visited[MAXN];
int dists[MAXN];

void dfs(int v, int curr_dist)
{
    if(visited[v]) return;
    dists[v]=min(dists[v],curr_dist);
    visited[v]=1;
    FOR(i,0,vec[v].size())
    {
        dfs(vec[v][i], curr_dist+1);
    }
    visited[v]=0;
}

int main()
{
    int n,k,first,second,start; cin >> n >> k;
    fill(dists,dists+n,INF);
    FOR(i,0,k) { cin >> first >> second; m[make_pair(first-1,second-1)]=1;} 
    cin >> start; start--;
    FOR(i,0,n)
    {
        FOR(j,i+1,n)
        {
            if(m[make_pair(i,j)]!=1) { vec[i].push_back(j); vec[j].push_back(i);}
        }
    }
    dfs(start,0);
    FOR(i,0,n) if(i!=start) cout << dists[i] << " ";
    cout << '\n';

    return 0;
}