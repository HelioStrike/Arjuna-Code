 #include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define MAXN 100
using namespace std;

//We construct a graph with each node in the adjecency list being (Worth, Day)
//Performing DFS for each initial node, only branching out when the next node's Day value
//is greater than or equal to that of the current node, gives us the final worth for each initial TV.
//Summing up the final worths gives us total worth.

struct Trade { int worth, day; };

vector<Trade> vec[MAXN];
bool visited[MAXN];

void dfs(int v, int day, int& maxm)
{
    if(visited[v]) return;
    visited[v] = 1;

    FOR(i,0,vec[v].size())
    {
        if(vec[v][i].day < day) continue;
        maxm = max(maxm, vec[v][i].worth);
        dfs(vec[v][i].worth, vec[v][i].day, maxm);
    }
}

void clearVisited() { FOR(i,0,MAXN) visited[i] = 0;}

int main()
{
    int n,numd; scanf("%d%d",&n,&numd);
    int arr[n]; FOR(i,0,n) scanf("%d",&arr[i]);

    int d,v1,v2,tot=0,maxm;
    FOR(i,0,numd)
    {
        scanf("%d%d%d",&d,&v1,&v2);
        vec[v1].push_back({v2,d});
        vec[v2].push_back({v1,d});
    }

    FOR(i,0,n)
    {
        clearVisited(); maxm = arr[i];
        dfs(arr[i],1,maxm);
        tot += maxm;
    }
    printf("%d\n",tot);

    return 0;
}