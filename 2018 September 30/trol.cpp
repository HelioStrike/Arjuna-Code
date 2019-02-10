#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];

  if(n == 1) { cout << arr[0] << '\n'; exit(0);}
  else if(n == 2) { cout << max(arr[0], arr[1]) << '\n'; exit(0);}
  else if(n == 3) { cout << (arr[0] + arr[1] + arr[2]) << '\n'; exit(0);}

  sort(arr, arr+n);

  int tot = 0;
  while(2*arr[1] < (arr[0]+arr[n-2]) && n > 3)
  {
    tot += (arr[0] + 2*arr[1] + arr[n-1]);
    n -= 2;
  }


  if(n == 1) tot += arr[0];
  else if(n == 2) tot += max(arr[0], arr[1]);
  else if(n == 3) tot += (arr[0] + arr[1] + arr[2]);
  else
  {
    tot += ((n-3)*arr[0]);
    for(int i = 0; i < n; i++) tot += arr[i];
  }
  cout << tot << '\n';

}
