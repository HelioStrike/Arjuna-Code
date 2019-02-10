#include <iostream>
#include <limits.h>
#define INF 99999
using namespace std;

void printSolution(int** dist, int V)
{
  for(int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++)
    {
      if(dist[i][j] == INF) { cout << "INF\t"; continue;}
      cout << dist[i][j] << "\t";
    }
    cout << '\n';
  }
}

int** floydWarshall(int** graph, int V)
{
  int** dist = new int*[V];;
  for(int i = 0; i < V; i++)
  {
    dist[i] = new int[V];
  }

  for(int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++) { dist[i][j] = graph[i][j];}
  }

  for(int k = 0; k < V; k++)
  {
    for(int i = 0; i < V; i++)
    {
      for(int j = 0; j < V; j++)
      {
        if(dist[i][k] + dist[k][j] < dist[i][j]) { dist[i][j] = dist[i][k] + dist[k][j];}
      }
    }
  }

  //printSolution(dist, V);
  return dist;
}

int main()
{
  int v, e; cin >> v >> e;
  int** graph = new int*[v];;
  for(int i = 0; i < v; i++)
  {
    graph[i] = new int[v];
  }

  for(int i = 0; i < v; i++)
  {
    for(int j = 0; j < v; j++)
    {
      graph[i][j] = INF;
    }
  }

  int start, end, weight;
  for(int i = 0; i < e; i++)
  {
    cin >> start >> end >> weight;
    graph[start-1][end-1] = weight;
  }
  //printSolution(graph, v);

  graph = floydWarshall(graph, v);
  int c; cin >> c;
  for(int i = 0; i < c; i++)
  {
    cin >> start >> end;
    cout << graph[start-1][end-1] << '\n';
  }


  return 0;
}
