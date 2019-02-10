#include <iostream>
#include <list>
#include <string.h>
using namespace std;

class Graph
{
  int V;
  list<int> *adj;
  int DFSUtil(int v, int k, int& t, bool visited[], bool reaches_out[], bool overlap[]);

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

int Graph::DFSUtil(int v, int k, int& t, bool visited[], bool reaches_out[], bool overlap[])
{
  visited[v] = true;

  int reaches = 0;
  int more_dfs;

  list<int>::iterator i;
  for(i = adj[v].begin(); i != adj[v].end(); ++i)
  {
    if(reaches_out[*i]) { return 2;}
    if(visited[*i] == true) { overlap[*i] = true; continue;}
    if((*i) == k) { t += 1; reaches = 1; continue;}

    more_dfs = DFSUtil(*i, k, t, visited, reaches_out, overlap);
    if(more_dfs == 1)
    {
      reaches_out[v] = true;
      reaches = 1;
    }
    else if(more_dfs == 2)
    {
      return 2;
    }
  }

  visited[v] = false;
  if(reaches)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void Graph::DFS(int v, int k)
{
  int t = 0;
  bool visited[V];
  bool reaches_out[V];
  bool overlap[V];

  memset(visited, 0, sizeof(visited));
  memset(reaches_out, 0, sizeof(reaches_out));
  memset(overlap, 0, sizeof(overlap));


  int deeefes = DFSUtil(v, k, t, visited, reaches_out, overlap);
  for(int i = 0; i < V; i++)
  {
    if(reaches_out[i] && overlap[i])
    {
      cout << "Infinite Paths" << '\n';
      return;
    }
  }

  if(deeefes == 2)
  {
    cout << "Infinite Paths" << '\n';
  }
  else
  {
    cout << t << '\n';
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
