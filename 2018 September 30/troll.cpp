#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  int arr[n];

  int tot = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i];
    tot += arr[i];
  }

  int min = *min_element(arr, arr+n);

  tot += (n-3)*min;

  cout << tot << '\n';

  return 0;
}
