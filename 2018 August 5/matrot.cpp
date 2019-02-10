#include <iostream>
using namespace std;

int main()
{
  int n, m, r; cin >> n >> m >> r;
  int mat[n][m];

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++) { cin >> mat[i][j];}
  }

  int new_mat[n][m];

  int visited[n][m];

  for(int i = 0; i < r; i++)
  {
    for(int x = 0; x < n; x++)
    {
      for(int y = 0; y < m;y++) { new_mat[x][y] = 0; visited[x][y] = 0;}
    }

    for(int k = 0; k < n/2; k++)
    {
      for(int i = k; i < n-k; i++)
      {
        for(int j = k; j < n-k; j++)
        {
          if(!(i == k || j == k || i == n-k-1 || j == n-k-1)) { continue;}

          if(i == k)
          {
            if(j == k) { new_mat[i+1][j] = mat[i][j];}
            else {new_mat[i][j-1] = mat[i][j];}
          }
          else if(i == n-k-1)
          {
            if(j == n-k-1) { new_mat[i-1][j] = mat[i][j];}
            else { new_mat[i][j+1] = mat[i][j];}
          }
          else if(j == k)
          {
            if(i == n-k-1) { new_mat[i][j+1] = mat[i][j];}
            else { new_mat[i+1][j] = mat[i][j];}
          }
          else if(j == n-k-1)
          {
            new_mat[i-1][j] = mat[i][j];
          }

          visited[i][j] = 1;
        }
      }
    }

    if(n%2 == 1 && m%2 == 1)
    {
      new_mat[n/2][m/2] = mat[n/2][m/2];
    }

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        mat[i][j] = new_mat[i][j];
      }
    }
  }

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++) { cout << new_mat[i][j] << " ";}
    cout << '\n';
  }

}
