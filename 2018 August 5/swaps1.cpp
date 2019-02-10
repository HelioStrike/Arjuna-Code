#include <iostream>
#include<bits/stdc++.h>
#define MIN(a,b) (a>b?b:a)
using namespace std;

int minimumSwaps(pair<int, int> arr[], int n)
{
  int visited[n];
  for(int i = 0; i < n; i++) { visited[i] = 0;}

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
      if (visited[i] || arr[i].second == i) { continue;}

      int size = 0;
      int curr = i;
      while (!visited[curr])
      {
          visited[curr] = 1;

          curr = arr[curr].second;
          size++;
      }

      ans += (size - 1);
  }

  return ans;
}

bool sort_rev(const pair<int, int> &a, const pair<int, int> &b) { return (a.first > b.first);}

main()
{
  int n; cin >> n;
  int elem;
  pair<int, int> arr_asc[n];
  pair<int, int> arr_dec[n];

  for(int i = 0; i < n; i++)
  {
    cin >> elem;
    arr_asc[i].first = arr_dec[i].first = elem;
    arr_asc[i].second = arr_dec[i].second = i;
  }

  sort(arr_asc, arr_asc+n);
  sort(arr_dec, arr_dec+n, sort_rev);

  int ans_asc = minimumSwaps(arr_asc, n);
  int ans_dec = minimumSwaps(arr_dec, n);
  cout << MIN(ans_asc, ans_dec) << '\n';
}
