#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int n;
    list<int> *adj;

    Graph(int n)
    {
        this->n = n;
        adj = new list<int>[n];
    }

    void addEdge(int u, int v)
    {
        this->adj[u].push_back(v);
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
    int n, pos, h; cin >> n;
    map<int, int> pos2i;
    map<int, int> pos2h;

    for(int i = 0; i < n_bridges; i++)
    {
        cin >> pos >> h;
        pos2i.insert(pair<int, int> (pos, i));
        pos2i.insert(pair<int, int> (pos, h));
    }

    Graph g(n);
    map<int, int>::iterator it;
    pair<int, int> curr_elem;
    int curr_pos;
    for(it = pos2i.begin(); it != pos2i.end(); it++)
    {
        curr_elem = *pos2h.find((*it).first);
        if(pos2h.find(curr_elem.first + curr_elem.second) != pos2h.end())
        {
            g.addEdge((*it).second, (*pos2i.find(curr_elem.first + curr_elem.second)).second);
        }

        if(pos2h.find(curr_elem.first - curr_elem.second) != pos2h.end())
        {
            g.addEdge((*it).second, (*pos2i.find(curr_elem.first - curr_elem.second)).second);
        }
    }

    g.connectedComponents();

    return 0;
}