#include <bits/stdc++.h>
#define MOVES 4
using namespace std;

int x_moves[MOVES] = { 1, 0, 0, -1};
int y_moves[MOVES] = { 0, 1, -1, 0};

int within(int n, int m, int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int propfire(int** map, int** visited, int n, int m, int x, int y)
{
  int tot = map[x][y];

  if(tot)
  {
    map[x][y] = 0;
    visited[x][y] = 1;
    int next_x, next_y;
    for(int i = 0; i < 4; i++)
    {
      next_x = x + x_moves[i];
      next_y = y + y_moves[i];
      if(!within(n, m, next_x, next_y) || visited[next_x][next_y]) continue;
      tot += propfire(map, visited, n, m, next_x, next_y);
    }
  }

  return tot;
}

int main()
{
  int n, m, k; cin >> n >> m >> k;
  int** map = new int*[n];
  for(int i = 0; i < n; i++)
  {
    map[i] = new int[m];
  }

  int cities = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      cin >> map[i][j];
      if(map[i][j]) cities++;
    }
  }

  int q1, q2, ans = cities;

  int** visited = new int*[n];
  for(int i = 0; i < n; i++)
  {
    visited[i] = new int[m];
  }

  for(int q = 0; q < k; q++)
  {
    cin >> q1 >> q2;

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        visited[i][j] = 0;
      }
    }

    ans -= propfire(map, visited, n, m, q1-1, q2-1);

    cout << ans << '\n';
  }

  return 0;
}
