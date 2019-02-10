#include <bits/stdc++.h>
#define INF 99999
using namespace std;

int moveTheBall(int arr[], int visited[], int n, int end, int curr)
{
  if(curr < 0) curr = n + curr;

  if(visited[curr]) return INF;
  if(curr == end) return 0;
  visited[curr] = 1;

  int mini = min(1 + moveTheBall(arr, visited, n, end, (curr + arr[curr])%n), 1 + moveTheBall(arr, visited, n, end, (curr - arr[curr])%n));

  visited[n] = 0;
  return mini;
}

int main()
{
  int n, start, end;
  cin >> n >> start >> end;
  start--; end--;

  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];

  int visited[n]; memset(visited, 0, sizeof(visited));
  int k =  moveTheBall(arr, visited, n, end, start);

  cout << k << '\n';

  return 0;
}
