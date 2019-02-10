#include <iostream>
#include <list>
#include <vector>
#include <string.h>
using namespace std;

class Graph
{
public:
  int V;
  list<int> *adj;

  Graph(int V)
  {
    this->V = V;
    adj = new list<int>[V];
  }

  void addEdge(int v, int w)
  {
    adj[v].push_back(w);
    adj[w].push_back(v);
  }

  int DFSUtil(int v, bool visited[])
  {
    if(visited[v]) { return 0;}
    visited[v] = true;

    int tot = 1;
    list<int>::iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); i++)
    {
      tot += DFSUtil(*i, visited);
    }
    return tot;
  }

  void DFS()
  {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    vector<int> groups;
    for(int v = 0; v < V; v++)
    {
      if(!visited[v])
      {
        groups.push_back(DFSUtil(v, visited));
      }
    }

    /*
    for(int i = 0; i < groups.size(); i++)
    {
      cout << groups[i] << " ";
    }
    cout << '\n';
    */

    int ans = 0;
    for(int i = 0; i < groups.size(); i++)
    {
      ans += (V-groups[i])*groups[i];
    }
    ans /= 2;
    cout << ans << '\n';
  }
};

int main()
{
  int n, t; cin >> n >> t;
  Graph g(n);

  int t1, t2;
  for(int i = 0; i < t; i++)
  {
    cin >> t1 >> t2;
    g.addEdge(t1, t2);
  }

  g.DFS();

  return 0;
}
