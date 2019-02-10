#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int n;
    list<int> *adj;
    int lake_cost, bridge_cost;

    Graph(int n, int lake_cost, int bridge_cost)
    {
        this->n = n;
        adj = new list<int>[n];
        this->lake_cost = lake_cost;
        this->bridge_cost = bridge_cost;
    }

    void addEdge(int u, int v)
    {
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }

    int connectedComponentsUtil(int u, int visited[])
    {
        visited[u] = 1;

        int tot = 1;
        list<int>::iterator it;
        for(it = adj[u].begin(); it != adj[u].end(); it++)
        {
            if(!visited[*it])
            {
               tot += connectedComponentsUtil(*it, visited);
            }
        }

        return tot;
    }

    void connectedComponents()
    {
        int visited[this->n];
        memset(visited, 0, sizeof(visited));

        int curr;
        int tot = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                curr = connectedComponentsUtil(i, visited);
                if(lake_cost > bridge_cost) tot += (curr-1)*bridge_cost + lake_cost;
                else tot += curr*lake_cost; 
            }
        }        
        cout << tot << '\n';
    }
};

int main()
{
    int n_islands, n_bridges, lake_cost, bridge_cost; cin >> n_islands >> n_bridges >> lake_cost >> bridge_cost;
    int s, e;

    Graph g(n_islands, lake_cost, bridge_cost);
    for(int i = 0; i < n_bridges; i++)
    {
        cin >> s >> e;
        g.addEdge(s-1, e-1);
    }

    g.connectedComponents();

    return 0;
}