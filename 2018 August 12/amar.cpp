#include <iostream>
#include <list>
using namespace std;

class Graph
{
  int V;
  list<int> *adj;
  int DFSUtil(int v, int k, int& t, bool visited[]);

public:
  Graph(int V);
  void addEdge(int v, int w);
  void DFS(int v, int k);
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

int Graph::DFSUtil(int v, int k, int& t, bool visited[])
{
  visited[v] = true;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
  {
    if(visited[*i] == true) { return 0;}
    if((*i) == k) { t += 1; continue;}

    if(!DFSUtil(*i, k, t, visited))
    {
      return 0;
    }
  }
  visited[v] = false;
  return 1;
}

void Graph::DFS(int v, int k)
{
  int t = 0;
  bool visited[V];
  for(int i = 0; i < V; i++)
  {
    visited[i] = false;
  }

  if(DFSUtil(v, k, t, visited))
  {
    cout << t << '\n';
  }
  else
  {
    cout << "Infinite Paths" << '\n';
  }
}

main()
{
  int n; cin >> n;
  int t; cin >> t;

  Graph g(n);

  int t1; int t2;
  for(int i = 0; i < t; i++)
  {
    cin >> t1; cin >> t2;
    g.addEdge(t1-1, t2-1);
  }

  g.DFS(0, n-1);

  return 0;
}
