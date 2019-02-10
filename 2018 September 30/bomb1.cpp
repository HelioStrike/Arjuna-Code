#include <bits/stdc++.h>
using namespace std;

int x_moves[8] = { 1, 1, 1, 0, 0, -1, -1, -1};
int y_moves[8] = { 1, 0, -1, 1, -1, 1, 0, -1};

int within(int n, int m, int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
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

  int x, y, ans, next_x, next_y;

  for(int q = 0; q < k; q++)
  {
    cin >> x >> y;

    x--;
    y--;
    ans = 0;
    for(int i = 0; i < 8; i++)
    {
      next_x = x + x_moves[i];
      next_y = y + y_moves[i];

      if(within(n, m, next_x, next_y))
      {
        if(map[next_x][next_y]) ans++;
      }
    }

    cout << (cities-ans) << '\n';
  }

  return 0;
}
